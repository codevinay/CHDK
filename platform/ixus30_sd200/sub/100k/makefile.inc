#0x30C0
PLATFORMID=12480

PLATFORMOS=vxworks

MEMBASEADDR=0x1900

# at ff8118b8
MEMISOSTART=0x72D40
ROMBASEADDR=0xff810000


PLFLAGS=-DMEMBASEADDR=$(MEMBASEADDR) -DMEMISOSTART=$(MEMISOSTART) -DMEMISOSIZE=$(MEMISOSIZE)
