#PLATFORMID=0x3233
PLATFORMID=12851

# Force disable of EXMEM (not implemented yet)
override OPT_EXMEM_MALLOC=
override OPT_CHDK_IN_EXMEM=
override OPT_EXMEM_TESTING=

PLATFORMOS=dryos

ROMBASEADDR=0xFF000000
MAXRAMADDR=0x0fffffff

MEMBASEADDR=0x1900

MEMISOSTART=0x18C7B4

PLFLAGS=-DMEMBASEADDR=$(MEMBASEADDR) -DMEMISOSTART=$(MEMISOSTART) -DMEMISOSIZE=$(MEMISOSIZE)

NEED_ENCODED_DISKBOOT=7

KEYSYS=d4c

PLATFORMOSVER=49
