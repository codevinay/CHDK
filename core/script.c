#include "camera_info.h"
#include "stdlib.h"
#include "keyboard.h"
#include "modes.h"
#include "viewport.h"
#include "conf.h"
#include "script.h"
#include "console.h"
#include "action_stack.h"
#include "shot_histogram.h"
#include "lang.h"
#include "gui.h"
#include "gui_lang.h"
#include "ptp.h"
#include "clock.h"

#include "script_api.h"
#include "motion_detector.h"

//-------------------------------------------------------------------

static AS_ID running_script_stack_name = 0;     // ID of action_stack, which used to control script processing

//-------------------------------------------------------------------
// script terminate key, may be set from script
static int script_terminate_key = KEY_SHOOT_FULL;
static char script_terminate_key_name[20]; // TODO this is only here because there's no easy way to map key number back to name

// Forward references
void script_end();

// External references
extern const char* script_source_str;
extern char script_params[SCRIPT_NUM_PARAMS][28];

//=======================================================
//                 SCRIPT CONSOLE FUNCTIONS
//=======================================================

//-------------------------------------------------------------------
static int  print_screen_p;             // print_screen predicate: 0=off, else is log file number. negative=append, postive=overwrite 
static int  print_screen_d = -1;        // print_screen file descriptor.
char print_screen_file[25];

static void script_print_screen_init()
{
    print_screen_p = 0;
    if (print_screen_d >= 0) {
        close(print_screen_d);
        print_screen_d = -1;
    }
}

static void script_print_screen_end()
{
    if (print_screen_d >= 0) {
        close(print_screen_d);
        print_screen_d = -1;
        print_screen_p = 0;
    }
}

void script_print_screen_statement(int val)
{
  // Negative values for 'val' parameter will append to log file,
  // positive values will truncate the log file
  int flag_trunc = O_TRUNC;

  print_screen_p = val;
  if (val) {
    if (print_screen_d>=0) close(print_screen_d);
    if (val<0) {
       flag_trunc = 0;
       val = -val;
    }
    while (val > 9999) val -= 10000;
    sprintf(print_screen_file, "A/CHDK/LOGS/LOG_%04d.TXT", val);
    print_screen_d = open(print_screen_file, O_WRONLY|O_CREAT|flag_trunc, 0777);
    if (print_screen_d>=0) lseek(print_screen_d,0,SEEK_END);
  }
  else script_print_screen_end() ;
}

void script_console_add_line(long str_id)
{
    const char* str = lang_str(str_id);
    console_add_line(str);

    if (print_screen_p && (print_screen_d >= 0)) {
        char nl = '\n';
        // TODO this should be uncached memory
        write(print_screen_d, str, strlen(str) );
        write(print_screen_d, &nl, 1);
    }
}

//=======================================================
//                 SCRIPT FUNCTIONS
//=======================================================

// Stack process function for running current script
static int action_stack_AS_SCRIPT_RUN()
{
    if (camera_info.state.state_kbd_script_run)
    {
        int rv = libscriptapi->script_run();
        if (rv != SCRIPT_RUN_RUNNING)
        {
            // Script language is responsible for displaying 'Finished' or error
            // messages so all we need to do is shutdown the script engine
            script_end();
            return 1;
        }
    }
    else
    {
        action_pop_func(0);
        return 1;
    }
    return 0;
}

long script_stack_start()
{
    camera_info.state.state_kbd_script_run = SCRIPT_STATE_RAN;
    running_script_stack_name = action_stack_create(&action_stack_AS_SCRIPT_RUN);
    return running_script_stack_name;
}

int script_is_running()
{
    return !action_stack_is_finished(running_script_stack_name);
}

//-------------------------------------------------------------------
void script_set_terminate_key(int key, const char *keyname)
{
    script_terminate_key = key;
    strncpy(script_terminate_key_name,keyname,sizeof(script_terminate_key_name));
    script_terminate_key_name[sizeof(script_terminate_key_name)-1] = 0;
}

void script_get_alt_text(char *buf)
{
    if ((script_terminate_key == KEY_SHOOT_FULL) || (gui_get_mode() != GUI_MODE_SCRIPT))
    {
        strcpy(buf,"<ALT>"); // TODO maybe it should be SCRIPT?
    }
    else
    {
        sprintf(buf,"<EXIT=%s>",script_terminate_key_name);
    }
}

// Main button processing for CHDK Script mode

static int gui_script_kbd_process()
{
    // Stop a script if the shutter button pressed in Script mode
    if (kbd_is_key_clicked(script_terminate_key))
    {
        script_console_add_line(LANG_CONSOLE_TEXT_INTERRUPTED);
        if (camera_info.state.state_kbd_script_run == SCRIPT_STATE_INTERRUPTED)
            script_end();
        else
        {
            camera_info.state.state_kbd_script_run = SCRIPT_STATE_INTERRUPTED;
            if (libscriptapi->run_restore() == 0)
                script_end();
        }
    }

    return 0;
}

//-------------------------------------------------------------------
void gui_script_draw()
{
    extern void gui_chdk_draw();
    gui_chdk_draw();

    if ((mode_get()&MODE_MASK) == MODE_REC || (mode_get()&MODE_MASK) == MODE_PLAY)
    {
        static int show_md_grid=0;
        if (camera_info.state.state_kbd_script_run) show_md_grid=5;
        if (show_md_grid)
        {
            --show_md_grid;
            libmotiondetect->md_draw_grid();
        }
    }
}

// GUI handler for Script mode
gui_handler scriptGuiHandler = { GUI_MODE_SCRIPT, gui_script_draw, gui_script_kbd_process, 0, 0 };      

static gui_handler *old_gui_handler = 0;

//-------------------------------------------------------------------

// Terminate a script, either because of error, or the script finished
void script_end()
{
    // Tell other code that script has ended
    camera_info.state.state_kbd_script_run = SCRIPT_STATE_INACTIVE;
    camera_info.state.osd_title_line = 1 ;
    
    // reset the script terminate key
    script_terminate_key = KEY_SHOOT_FULL ;

    script_print_screen_end();

    // Restore old handler - prevent calling MD draw after module unloaded
    if (old_gui_handler)
    {
        gui_set_mode(old_gui_handler);
        old_gui_handler = 0;
    }

    // Reset script language module
    libscriptapi->script_reset();

    // Kill off the action_stack for the script, since we've just reset the script
    // language and unloaded the MD module, we don't need to let the stack empty
    // itself.
    action_stack_kill(running_script_stack_name);
    running_script_stack_name = -1;

	shot_histogram_set(0);
    kbd_key_release_all();

    conf_setAutosave(1);    // Turn on autosave of config file in conf_setValue in case script turned it off
    conf_update_prevent_shutdown();
}

long script_start_gui( int autostart )
{
    int i;

    shot_histogram_set(0);
    camera_info.state.auto_started = autostart;

    // Keyboard init
    camera_info.state.kbd_last_clicked = 0;
    camera_info.state.kbd_last_checked_time = get_tick_count();
    kbd_key_release_all();

    // Close old console, will be re-opened when first line added
    console_close();
    script_print_screen_init();

    save_params_values(0);

    script_console_add_line((autostart)?LANG_CONSOLE_TEXT_AUTOSTARTED:LANG_CONSOLE_TEXT_STARTED);

    module_set_script_lang(conf.script_file);
    if ( !libscriptapi->script_start(script_source_str,0) )
    {
        return -1;
    }
    for (i=0; i<SCRIPT_NUM_PARAMS; ++i)
    {
        if( script_params[i][0] )
        {
            libscriptapi->set_variable(i, conf.script_vars[i]);
        }
    }

    conf_update_prevent_shutdown();

    old_gui_handler = gui_set_mode(&scriptGuiHandler);

    return script_stack_start();
}

//-------------------------------------------------------------------
