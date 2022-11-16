# Copyright (C) ARM Limited, 2010-2012. All rights reserved.
#
# This makefile is intended to allow command-line users to build this project outside of Eclipse
# This makefile is NOT used by the Eclipse managed builder project (which creates its own makefiles)
#
# This makefile is intended for use with GNU make
# This example is intended to be built with ARM Compiler 6

include ../startup_R52_armclang/makefile.common

# Uncomment to retarget printf to PL011 (UART)
#RETARGET=-DRETARGETON

TARGET=GIC_R52_armclang

all: $(TARGET)
	 $(call DONE,$(TARGET))

rebuild: clean all

clean:
	$(call RM,.\obj\*.o)
	$(call RM,*.o)
	$(call RM,$(TARGET)*.*)

$(TARGET) : ./obj/main.o ./obj/pl011.o ./obj/retarget.o ./obj/sorts.o ./obj/startup.o ./obj/v8rgicv3cpuif.o ./obj/generictimer.o ./obj/GIC.o ./obj/exception_handlers.o ./obj/GICIsrVectorTable.o scatter.scat
	$(LD) ./obj/main.o ./obj/pl011.o ./obj/retarget.o ./obj/sorts.o ./obj/startup.o ./obj/v8rgicv3cpuif.o ./obj/generictimer.o ./obj/GIC.o ./obj/exception_handlers.o ./obj/GICIsrVectorTable.o --scatter=scatter.scat --entry=Start -o $(TARGET).axf --info=totals $(LDFLAG)
	$(LD) ./obj/main.o ./obj/pl011.o ./obj/retarget.o ./obj/sorts.o ./obj/startup.o ./obj/v8rgicv3cpuif.o ./obj/generictimer.o ./obj/GIC.o ./obj/exception_handlers.o ./obj/GICIsrVectorTable.o --scatter=scatter2.scat --entry=Start -o $(TARGET)2.axf --info=totals $(LDFLAG)
	$(FE) --i32 $(TARGET).axf --output $(TARGET).hex
	$(FE) --bin $(TARGET).axf --output $(TARGET).bin
	$(FE) --i32 $(TARGET)2.axf --output $(TARGET)2.hex
	$(FE) --bin $(TARGET)2.axf --output $(TARGET)2.bin

./obj/main.o : ./main.c
	$(CC) -c $(CCOPT) ./main.c -o ./obj/main.o 

./obj/retarget.o : ./retarget.c
	$(CC) -c $(CCOPT) ./retarget.c -o ./obj/retarget.o $(RETARGET)

./obj/pl011.o : ./pl011.c
	$(CC) -c $(CCOPT) ./pl011.c -o ./obj/pl011.o

./obj/GIC.o : ./GIC.c
	$(CC) -c $(CCOPT) ./GIC.c -o ./obj/GIC.o

./obj/GICIsrVectorTable.o : ./GICIsrVectorTable.c
	$(CC) -c $(CCOPT) ./GICIsrVectorTable.c -o ./obj/GICIsrVectorTable.o
	
./obj/sorts.o : ../startup_R52_armclang/sorts.c
	$(CC) -c $(CCOPT) ../startup_R52_armclang/sorts.c -o ./obj/sorts.o

./obj/startup.o : ../startup_R52_armclang/startup.s
	$(AS) $(ASFLAG) $(APD) ../startup_R52_armclang/startup.s -o ./obj/startup.o

./obj/v8rgicv3cpuif.o : ./v8rgicv3cpuif.s
	$(AS) $(ASFLAG) $(APD) ./v8rgicv3cpuif.s -o ./obj/v8rgicv3cpuif.o
	
./obj/generictimer.o : ./generictimer.s
	$(AS) $(ASFLAG) $(APD) ./generictimer.s -o ./obj/generictimer.o

./obj/exception_handlers.o : ./exception_handlers.s
	$(AS) $(ASFLAG) $(APD) ./exception_handlers.s -o ./obj/exception_handlers.o

