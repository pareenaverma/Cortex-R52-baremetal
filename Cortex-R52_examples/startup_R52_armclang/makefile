# Copyright (C) ARM Limited, 2010-2012. All rights reserved.
#
# This makefile is intended to allow command-line users to build this project outside of Eclipse
# This makefile is NOT used by the Eclipse managed builder project (which creates its own makefiles)
#
# This makefile is intended for use with GNU make
# This example is intended to be built with ARM Compiler 6

include makefile.common

TARGET=startup_R52_armclang.axf

all: $(TARGET)
	 $(call DONE,$(TARGET))

rebuild: clean all

clean:
	  $(call RM,*.o)
	  $(call RM,$(TARGET))

$(TARGET) : main.o sorts.o startup.o scatter.scat
	$(LD) main.o sorts.o startup.o --scatter=scatter.scat --entry=Start -o $(TARGET) --info=totals $(LDFLAG)

main.o : main.c
	$(CC) -c $(CCOPT) main.c

sorts.o : sorts.c
	$(CC) -c $(CCOPT) sorts.c

startup.o : startup.s
	$(AS) $(ASFLAG) $(APD) startup.s 
