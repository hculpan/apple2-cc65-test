This is a simple little C program written for CC65 and targeting the Enhanced Apple IIe.

Note that this Makefile will create a 140k ProDos bootable disk image and copy the program to it.  However, it does not copy STARTUP, so you will need to create that yourself.  To do so, the first time you book the disk, type the following:

]NEW
]10 PRINT CHR$(4);"-ADDER"     <-- replace ADDER with your actual program name
]SAVE STARTUP

The Makefile only creates a new disk if you remove the old disk; otherwise it just replaces the original file.  To facilitate this, this project has three clean targets:

clean: standard clean that removes everything but the disk image
clean-disk: removes only the disk image
clean-all: calls both of above
