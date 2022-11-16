//==================================================================
// Copyright ARM Ltd 2016. All rights reserved.
//
// Cortex-R52 Embedded example - Startup Code
//==================================================================

// MPU region defines

// Protection Base Address Register
.equ Execute_Never, 0b1 		// Bit 0
.equ RW_Access, 0b01			// AP[2:1]
.equ RO_Access, 0b11
.equ Non_Shareable, 0b00 		// SH[1:0]
.equ Outer_Shareable, 0x10
.equ Inner_Shareable, 0b11

// Protection Limit Address Register
.equ ENable, 0b1 				// Bit 0
.equ AttrIndx0, 0b000			// AttrIndx[2:0]
.equ AttrIndx1, 0b001
.equ AttrIndx2, 0b010
.equ AttrIndx3, 0b011
.equ AttrIndx4, 0b100
.equ AttrIndx5, 0b101
.equ AttrIndx6, 0b110
.equ AttrIndx7, 0b111

//==================================================================

// Define some values
.equ Mode_USR, 0x10
.equ Mode_FIQ, 0x11
.equ Mode_IRQ, 0x12
.equ Mode_SVC, 0x13
.equ Mode_MON, 0x16
.equ Mode_ABT, 0x17
.equ Mode_UNDEF, 0x1B
.equ Mode_SYS, 0x1F
.equ Mode_HYP, 0x1A
.equ I_Bit, 0x80 // when I bit is set, IRQ is disabled
.equ F_Bit, 0x40 // when F bit is set, FIQ is disabled

//==================================================================
#ifdef __ARMGNU__
	.section .stack
	.align	3
#ifdef __STACK_SIZE
	.equ	Stack_Size, __STACK_SIZE
#else
	.equ	Stack_Size, 0x10000
#endif
	.globl	__StackTop
	.globl	__StackLimit
__StackLimit:
	.space	Stack_Size
	.size	__StackLimit, . - __StackLimit
__StackTop:
	.size	__StackTop, . - __StackTop

	.section .heap
	.align	3
#ifdef __HEAP_SIZE
	.equ	Heap_Size, __HEAP_SIZE
#else
	.equ	Heap_Size, 0xc00
#endif
	.globl	__HeapBase
	.globl	__HeapLimit
__HeapBase:
#if	Heap_Size
	.space	Heap_Size
#endif
	.size	__HeapBase, . - __HeapBase
__HeapLimit:
	.size	__HeapLimit, . - __HeapLimit
#endif 

//==================================================================
#ifdef __ARMGNU__
	.section  .isr_vector,"ax"
	.align 3
	.syntax unified
#endif
#ifdef __ARMCLANG__
	.section  VECTORS,"ax"
	.align 3
#endif 
//==================================================================
// Entry point for the Reset handler
//==================================================================

	.global Start
	.type Start, %function

Start:	

//==================================================================
// EL2 Exception Vector Table
//==================================================================
// Note: LDR PC instructions are used here, though branch (B) instructions
// could also be used, unless the exception handlers are >32MB away.

EL2_Vectors:	
        LDR PC, EL2_Reset_Addr
        LDR PC, EL2_Undefined_Addr
        LDR PC, EL2_HVC_Addr
        LDR PC, EL2_Prefetch_Addr
        LDR PC, EL2_Abort_Addr
        LDR PC, EL2_HypModeEntry_Addr
        LDR PC, EL2_IRQ_Addr
        LDR PC, EL2_FIQ_Addr


EL2_Reset_Addr:			.word	 EL2_Reset_Handler
EL2_Undefined_Addr:		.word	 EL2_Undefined_Handler
EL2_HVC_Addr:			.word	 EL2_HVC_Handler
EL2_Prefetch_Addr:		.word	 EL2_Prefetch_Handler
EL2_Abort_Addr:			.word	 EL2_Abort_Handler
EL2_HypModeEntry_Addr:	.word	 EL2_HypModeEntry_Handler
EL2_IRQ_Addr:			.word	 EL2_IRQ_Handler
EL2_FIQ_Addr:			.word	 EL2_FIQ_Handler


//==================================================================
// EL2 Exception Handlers
//==================================================================

.weak EL2_Undefined_Handler
.type EL2_Undefined_Handler, %function
EL2_Undefined_Handler:	
        B   EL2_Undefined_Handler
.weak EL2_HVC_Handler
.type EL2_HVC_Handler, %function
EL2_HVC_Handler:	
        B   EL2_HVC_Handler
.weak EL2_Prefetch_Handler
.type EL2_Prefetch_Handler, %function
EL2_Prefetch_Handler:	
        B   EL2_Prefetch_Handler
.weak EL2_Abort_Handler
.type EL2_Abort_Handler, %function
EL2_Abort_Handler:	
        B   EL2_Abort_Handler
.weak EL2_HypModeEntry_Handler
.type EL2_HypModeEntry_Handler, %function
EL2_HypModeEntry_Handler:	
        B   EL2_HypModeEntry_Handler
.weak EL2_IRQ_Handler
.type EL2_IRQ_Handler, %function
EL2_IRQ_Handler:	
        B   EL2_IRQ_Handler
.weak EL2_FIQ_Handler
.type EL2_FIQ_Handler, %function
EL2_FIQ_Handler:	
        B   EL2_FIQ_Handler

//==================================================================
// EL1 Exception Vector Table
//==================================================================
// Note: LDR PC instructions are used here, though branch (B) instructions
// could also be used, unless the exception handlers are >32MB away.

	.align 5
EL1_Vectors:	
        LDR PC, EL1_Reset_Addr
        LDR PC, EL1_Undefined_Addr
        LDR PC, EL1_SVC_Addr
        LDR PC, EL1_Prefetch_Addr
        LDR PC, EL1_Abort_Addr
        LDR PC, EL1_Reserved
        LDR PC, EL1_IRQ_Addr
        LDR PC, EL1_FIQ_Addr


EL1_Reset_Addr:		.word	 EL1_Reset_Handler
EL1_Undefined_Addr:	.word	 EL1_Undefined_Handler
EL1_SVC_Addr:		.word	 EL1_SVC_Handler
EL1_Prefetch_Addr:	.word	 EL1_Prefetch_Handler
EL1_Abort_Addr:		.word	 EL1_Abort_Handler
EL1_Reserved_Addr:	.word	 EL1_Reserved
EL1_IRQ_Addr:		.word	 EL1_IRQ_Handler
EL1_FIQ_Addr:		.word	 EL1_FIQ_Handler


//==================================================================
// EL1 Exception Handlers
//==================================================================

.weak EL1_Undefined_Handler
.type EL1_Undefined_Handler, %function
EL1_Undefined_Handler:	
        B   EL1_Undefined_Handler
.weak EL1_SVC_Handler
.type EL1_SVC_Handler, %function
EL1_SVC_Handler:	
        B   EL1_SVC_Handler
.weak EL1_Prefetch_Handler
.type EL1_Prefetch_Handler, %function
EL1_Prefetch_Handler:	
        B   EL1_Prefetch_Handler
.weak EL1_Abort_Handler
.type EL1_Abort_Handler, %function
EL1_Abort_Handler:	
        B   EL1_Abort_Handler
EL1_Reserved:	
        B   EL1_Reserved
.weak EL1_IRQ_Handler
.type EL1_IRQ_Handler, %function
EL1_IRQ_Handler:	
        B   EL1_IRQ_Handler
.weak EL1_FIQ_Handler
.type EL1_FIQ_Handler, %function
EL1_FIQ_Handler:	
        B   EL1_FIQ_Handler

//==================================================================
// EL2 Reset Handler
//==================================================================
#ifdef __ARMGNU__
	.section  .reset,"ax"
	.align 3
	.syntax unified
#endif
#ifdef __ARMCLANG__
	.section  RESET,"ax"
	.align 3
#endif 
#ifdef __THUMB__
	.thumb
#endif

.weak EL2_Reset_Handler
.type EL2_Reset_Handler, %function
EL2_Reset_Handler:

	//Check which CPU I am
		MRC p15, 0, r0, c0, c0, 5 		// Read MPIDR into Rt
		ANDS r0, r0, 0xF
		BEQ EL2_cpu0
		WFI								// Wait For Interrupt if not cpu0
		
EL2_cpu0:	
	// Change EL2 exception base address
		LDR r0, =EL2_Vectors
		MCR p15, 4, r0, c12, c0, 0 		// 	Write r0 to HVBAR

	// Init HSCTLR	
		LDR r0, =0x30C5180C				// See TRM for decoding				
		MCR p15, 4, r0, c1, c0, 0 		// Write r0 to HSCTLR
	
	// Enable EL1 access to all IMP DEF registers	
		LDR r0, =0x7F81				
		MCR p15, 4, r0, c1, c0, 1 		// Write r0 to HACTLR
	
	// Change EL1 exception base address
		LDR r0, =EL1_Vectors
		MCR p15, 0, r0, c12, c0, 0 		// 	Write r0 to VBAR
	
	// Go to SVC mode
		MRS r0, cpsr
		MOV r1, #Mode_SVC
		BFI r0, r1, #0, #5
#ifdef __THUMB__
        ORR r0, r0, #(0x1 << 5)         // Set T bit
#endif
		MSR spsr_hyp, r0
		LDR r0, =EL1_Reset_Handler
		MSR elr_hyp, r0
		DSB
		ISB
		ERET


	

.weak EL1_Reset_Handler
EL1_Reset_Handler:

//==================================================================
// Disable MPU and caches
//==================================================================

	// Disable MPU and cache in case it was left enabled from an earlier run
    // This does not need to be done from a cold reset
        MRC p15, 0, r0, c1, c0, 0       // Read System Control Register
        BIC r0, r0, #0x05               // Disable MPU (M bit) and data cache (C bit)
        BIC r0, r0, #0x800              // Disable branch prediction (Z bit)
        BIC r0, r0, #0x1000             // Disable instruction cache (I bit)
        DSB                             // Ensure all previous loads/stores have completed
        MCR p15, 0, r0, c1, c0, 0       // Write System Control Register
        ISB                             // Ensure subsequent insts execute wrt new MPU settings


//==================================================================
// Cortex-R52 implementation specific configuration
//==================================================================
#ifdef ENABLE_R52_SPECIFIC_CONFIG		
		LDR r1,=0x3C					// SIZE field mask
		
		MRC p15, 0, r0, c15, c0, 1		// Read from FLASHIFREGIONR
		ANDS r2, r0, r1					// Extract SIZE and set flags
		BEQ 1f
		ORR r0, r0, #0x1				// Set enable bit if SIZE=!0x0
		MCR p15, 0, r0, c15, c0, 1		// Write r0 to FLASHIFREGIONR if SIZE=!0x0
1:		
		MRC p15, 0, r0, c15, c0, 0		// Read from PERIPHPREGIONR
		ANDS r2, r0, r1					// Extract SIZE and set flags
		BEQ 2f
		ORR r0, r0, #0x1				// Set enable bit if SIZE=!0x0
		MCR p15, 0, r0, c15, c0, 0		// Write r0 to PERIPHPREGIONR if SIZE=!0x0
2:
#endif

//==================================================================
// Initialize Stacks using Linker symbol from scatter file.
// ABT, IRQ, FIQ, UNDEF size = STACKSIZE, SVC the rest.
// Stacks must be 8 byte aligned.
//==================================================================
#ifdef __ARMCLANG__
.equ STACKSIZE, 512
	.global Image$$ARM_LIB_STACKHEAP$$ZI$$Limit
		LDR r0, =Image$$ARM_LIB_STACKHEAP$$ZI$$Limit
		
		CPS #Mode_ABT
		MOV SP, r0

		CPS #Mode_IRQ
		SUB r0, r0, #STACKSIZE
		MOV SP, r0

		CPS #Mode_FIQ
		SUB r0, r0, #STACKSIZE
		MOV SP, r0
		
		CPS #Mode_SVC
		SUB r0, r0, #STACKSIZE
		MOV SP, r0
#endif

//==================================================================
// Cache invalidation. However R52 provides CFG signals to 
// invalidate cache automatically out of reset (CFGL1CACHEINVDISx)
//==================================================================

        DSB             // Complete all outstanding explicit memory operations

        MOV r0, #0

        MCR p15, 0, r0, c7, c5, 0       // Invalidate entire instruction cache
        
		// Invalidate Data/Unified Caches
        MRC     p15, 1, r0, c0, c0, 1      // Read CLIDR
        ANDS    r3, r0, #0x07000000        // Extract coherency level
        MOV     r3, r3, LSR #23            // Total cache levels << 1
        BEQ     Finished                   // If 0, no need to clean
    
        MOV     r10, #0                    // R10 holds current cache level << 1
Loop1:  ADD     r2, r10, r10, LSR #1       // R2 holds cache "Set" position 
        MOV     r1, r0, LSR r2             // Bottom 3 bits are the Cache-type for this level
        AND     r1, r1, #7                 // Isolate those lower 3 bits
        CMP     r1, #2
        BLT     Skip                       // No cache or only instruction cache at this level
        
        MCR     p15, 2, r10, c0, c0, 0     // Write the Cache Size selection register
        ISB                                // ISB to sync the change to the CacheSizeID reg
        MRC     p15, 1, r1, c0, c0, 0      // Reads current Cache Size ID register
        AND     r2, r1, #7                 // Extract the line length field
        ADD     r2, r2, #4                 // Add 4 for the line length offset (log2 16 bytes)
        LDR     r4, =0x3FF
        ANDS    r4, r4, r1, LSR #3         // R4 is the max number on the way size (right aligned)
        CLZ     r5, r4                     // R5 is the bit position of the way size increment
        LDR     r7, =0x7FFF
        ANDS    r7, r7, r1, LSR #13        // R7 is the max number of the index size (right aligned)

Loop2:  MOV     r9, r4                     // R9 working copy of the max way size (right aligned)

#ifdef __THUMB__
Loop3:  LSL		r12, r9, r5
		ORR     r11, r10, r12		       // Factor in the Way number and cache number into R11
        LSL		r12, r7, r2
		ORR     r11, r11, r12		       // Factor in the Set number
#else
Loop3:  ORR     r11, r10, r9, LSL r5       // Factor in the Way number and cache number into R11
        ORR     r11, r11, r7, LSL r2       // Factor in the Set number
#endif
        MCR     p15, 0, r11, c7, c6, 2     // Invalidate by Set/Way
        SUBS    r9, r9, #1                 // Decrement the Way number
        BGE     Loop3
        SUBS    r7, r7, #1                 // Decrement the Set number
        BGE     Loop2
Skip:   ADD     r10, r10, #2               // increment the cache number
        CMP     r3, r10
        BGT     Loop1

Finished:

//===================================================================
// TCM Configuration
//===================================================================

// R52 optionally provides three Tightly-Coupled Memory (TCM) blocks (ATCM, BTCM and CTCM) 
//    for fast access to code or data.

// The following illustrates basic TCM configuration, as the basis for exploration by the user

#ifdef TCM

        MRC p15, 0, r0, c0, c0, 2       // Read TCM Type Register
        // r0 now contains TCM availability

        MRC p15, 0, r0, c9, c1, 0       // Read ATCM Region Register
        // r0 now contains ATCM size in bits [5:2]
        LDR r0, =Image$$ATCM$$Base  	// Set ATCM base address
        ORR r0, r0, #1                  // Enable it
        MCR p15, 0, r0, c9, c1, 0       // Write ATCM Region Register

        MRC p15, 0, r0, c9, c1, 1       // Read BTCM Region Register
        // r0 now contains BTCM size in bits [5:2]
        LDR r0, =Image$$BTCM$$Base  	// Set BTCM base address
        ORR r0, r0, #1                  // Enable it
        MCR p15, 0, r0, c9, c1, 1       // Write BTCM Region Register

        MRC p15, 0, r0, c9, c1, 2       // Read CTCM Region Register
        // r0 now contains CTCM size in bits [5:2]
        LDR r0, =Image$$CTCM$$Base  	// Set CTCM base address
        ORR r0, r0, #1                  // Enable it
        MCR p15, 0, r0, c9, c1, 2       // Write CTCM Region Register

#endif


//===================================================================
// MPU Configuration
//===================================================================
// Notes:
// * Regions apply to both instruction and data accesses.
// * Each region base address must be a multiple of its size
// * Any address range not covered by an enabled region will abort
// * The region at 0x0 over the Vector table is needed to support semihosting

// Region 0: Init/Flash    	Base = See scat/ld		Limit = Based on usage   Normal  Non-shared  Full access  Executable
// Region 1: Code/UNUSED	Base = See scat/ld		Limit = Based on usage   Normal  Non-shared  Full access  Executable
// Region 2: Data          	Base = See scat/ld	  	Limit = Based on usage   Normal  Non-shared  Full access  Not Executable
// Region 3: Stack-Heap    	Base = See scat/ld	  	Limit = Based on usage   Normal  Non-shared  Full access  Not Executable
// Region 4: Peripherals   	Base = 0x9A000000  		Limit = 0xAFFFFFC0		 Device				 Full access  Not Executable
// Region 5: ATCM	       	Base = Configurable 	Limit = Based on usage   Normal  Non-shared  Full access  Executable
// Region 6: BTCM	       	Base = Configurable 	Limit = Based on usage   Normal  Non-shared  Full access  Executable
// Region 7: CTCM	       	Base = Configurable 	Limit = Based on usage   Normal  Non-shared  Full access  Executable

		LDR		r0, =64

        // Region 0 - Init/Flash
#ifdef __ARMGNU__
        LDR     r1, =Start 
#endif
#ifdef __ARMCLANG__
        LDR     r1, =Load$$LR$$LOAD$$Base 
#endif
		LDR		r2, =((Non_Shareable<<3) | (RW_Access<<1))
		ORR		r1, r1, r2
		MCR 	p15, 0, r1, c6, c8, 0 					// write PRBAR0
#ifdef __ARMGNU__
		LDR     r1, =__FlashLimit
#endif
#ifdef __ARMCLANG__
        LDR     r1, =Load$$LR$$LOAD$$Limit
#endif
		BFC 	r1, #0, #6								// align to Limit to 64bytes
		LDR		r2, =((AttrIndx0<<1) | (ENable))
		ORR		r1, r1, r2
		MCR 	p15, 0, r1, c6, c8, 1 					// write PRLAR0
        
#ifndef __ARMGNU__
		// Region 1 - Code
        LDR     r1, =Image$$CODE$$Base 
		LDR		r2, =((Non_Shareable<<3) | (RW_Access<<1))
		ORR		r1, r1, r2
		MCR 	p15, 0, r1, c6, c8, 4 					// write PRBAR1
        LDR     r1, =Image$$CODE$$Limit 
		BFC 	r1, #0, #6								// align to Limit to 64bytes
		LDR		r2, =((AttrIndx0<<1) | (ENable))
		ORR		r1, r1, r2
		MCR 	p15, 0, r1, c6, c8, 5 					// write PRLAR1
#endif

        // Region 2 - Data
#ifdef __ARMGNU__
        LDR     r1, =__data_start__ 
#endif
#ifdef __ARMCLANG__
        LDR     r1, =Image$$DATA$$Base 
#endif
		LDR		r2, =((Non_Shareable<<3) | (RW_Access<<1))
		ORR		r1, r1, r2
		MCR 	p15, 0, r1, c6, c9, 0 					// write PRBAR2
#ifdef __ARMGNU__
        LDR     r1, =__bss_end__
#endif
#ifdef __ARMCLANG__
        LDR     r1, =Image$$DATA$$ZI$$Limit 
#endif
		BFC 	r1, #0, #6								// align to Limit to 64bytes
		LDR		r2, =((AttrIndx0<<1) | (ENable))
		ORR		r1, r1, r2
		MCR 	p15, 0, r1, c6, c9, 1 					// write PRLAR2

        // Region 3 - Stack-Heap
#ifdef __ARMGNU__
        LDR     r1, =__end__ 
#endif
#ifdef __ARMCLANG__
        LDR     r1, =Image$$ARM_LIB_STACKHEAP$$Base 
#endif
		LDR		r2, =((Non_Shareable<<3) | (RW_Access<<1))
		ORR		r1, r1, r2
		MCR 	p15, 0, r1, c6, c9, 4 					// write PRBAR3
#ifdef __ARMGNU__
        LDR     r1, =__StackTop 
#endif
#ifdef __ARMCLANG__
        LDR     r1, =Image$$ARM_LIB_STACKHEAP$$ZI$$Limit 
#endif
		BFC 	r1, #0, #6								// align to Limit to 64bytes
		LDR		r2, =((AttrIndx0<<1) | (ENable))
		ORR		r1, r1, r2
		MCR 	p15, 0, r1, c6, c9, 5 					// write PRLAR3

        // Region 4 - Peripherals
        LDR     r1, =0x9A000000
		LDR		r2, =((Non_Shareable<<3) | (RW_Access<<1))
		ORR		r1, r1, r2
		MCR 	p15, 0, r1, c6, c10, 0 					// write PRBAR4
        LDR     r1, =0xAFFFFFC0 
		BFC 	r1, #0, #6								// align to Limit to 64bytes
		LDR		r2, =((AttrIndx1<<1) | (ENable))
		ORR		r1, r1, r2
		MCR 	p15, 0, r1, c6, c10, 1 					// write PRLAR4
		
#ifdef TCM
        // Region 5 - ATCM
        LDR     r1, =Image$$ATCM$$Base 
		LDR		r2, =((Non_Shareable<<3) | (RW_Access<<1))
		ORR		r1, r1, r2
		MCR 	p15, 0, r1, c6, c10, 4 					// write PRBAR5
        LDR     r1, =Image$$ATCM$$Limit 
		BFC 	r1, #0, #6								// align to Limit to 64bytes
		LDR		r2, =((AttrIndx0<<1) | (ENable))
		ORR		r1, r1, r2
		MCR 	p15, 0, r1, c6, c10, 5 					// write PRLAR5

        // Region 6 - BTCM
        LDR     r1, =Image$$BTCM$$Base 
		LDR		r2, =((Non_Shareable<<3) | (RW_Access<<1))
		ORR		r1, r1, r2
		MCR 	p15, 0, r1, c6, c11, 0 					// write PRBAR6
        LDR     r1, =Image$$BTCM$$Limit 
		BFC 	r1, #0, #6								// align to Limit to 64bytes
		LDR		r2, =((AttrIndx0<<1) | (ENable))
		ORR		r1, r1, r2
		MCR 	p15, 0, r1, c6, c11, 1 					// write PRLAR6

        // Region 7 - CTCM
        LDR     r1, =Image$$CTCM$$Base 
		LDR		r2, =((Non_Shareable<<3) | (RW_Access<<1))
		ORR		r1, r1, r2
		MCR 	p15, 0, r1, c6, c11, 4 					// write PRBAR7
        LDR     r1, =Image$$CTCM$$Limit 
		BFC 	r1, #0, #6								// align to Limit to 64bytes
		LDR		r2, =((AttrIndx0<<1) | (ENable))
		ORR		r1, r1, r2
		MCR 	p15, 0, r1, c6, c11, 5 					// write PRLAR7

#endif

	// MAIR0 configuration
		MRC p15, 0, r0, c10, c2, 0  	// Read MAIR0 into r0
		LDR r1, =0xBB					// Normal inner/outer RW cacheable, write-through
		BFI r0, r1, #0, #8				// Update Attr0
		LDR r1, =0x04					// Device nGnRnE
		BFI r0, r1, #8, #8				// Update Attr1
		MCR p15,0,r0,c10,c2,0 			// Write r0 to MAIR0

#ifdef __TARGET_FPU_VFP
//==================================================================
// Enable access to VFP by enabling access to Coprocessors 10 and 11.
// Enables Full Access i.e. in both privileged and non privileged modes
//==================================================================

        MRC     p15, 0, r0, c1, c0, 2      // Read Coprocessor Access Control Register (CPACR)
        ORR     r0, r0, #(0xF << 20)       // Enable access to CP 10 & 11
        MCR     p15, 0, r0, c1, c0, 2      // Write Coprocessor Access Control Register (CPACR)
        ISB

//==================================================================
// Switch on the VFP hardware
//=================================================================

        MOV     r0, #0x40000000
        VMSR    FPEXC, r0                   // Write FPEXC register, EN bit set
#endif


//===================================================================
// Enable MPU and branch to C library init
// Leaving the caches disabled until after scatter loading.
//===================================================================

        MRC     p15, 0, r0, c1, c0, 0       // Read System Control Register
        ORR     r0, r0, #0x01               // Set M bit to enable MPU
        DSB                                 // Ensure all previous loads/stores have completed
        MCR     p15, 0, r0, c1, c0, 0       // Write System Control Register
        ISB                                 // Ensure subsequent insts execute wrt new MPU settings

#ifdef __ARMGNU__
//===================================================================
// Multiple sections scheme.
// 
// Between symbol address __copy_table_start__ and __copy_table_end__,
// there are array of triplets, each of which specify:
//   offset 0: LMA of start of a section to copy from
//   offset 4: VMA of start of a section to copy to
//   offset 8: size of the section to copy. Must be multiply of 4
// 
// All addresses must be aligned to 4 bytes boundary.
// 
//===================================================================
	.globl __copy_table_start__
	.globl __copy_table_end__

	ldr	r4, =__copy_table_start__
	ldr	r5, =__copy_table_end__

.L_loop0:
	cmp	r4, r5
	bge	.L_loop0_done
	ldr	r1, [r4]
	ldr	r2, [r4, #4]
	ldr	r3, [r4, #8]

.L_loop0_0:
	subs	r3, #4
	ittt	ge
	ldrge	r0, [r1, r3]
	strge	r0, [r2, r3]
	bge	.L_loop0_0

	adds	r4, #12
	b	.L_loop0

.L_loop0_done:
#endif

#ifdef __ARMGNU__
	.global _mainCRTStartup
        B       _mainCRTStartup
#endif
#ifdef __ARMCLANG__
	.global __main
        B       __main
#endif

//==================================================================
// Global Enable for Instruction and Data Caching
//==================================================================

	.global enable_caches
	.type enable_caches, %function
enable_caches:

        MRC     p15, 0, r0, c1, c0, 0       // read System Control Register
        ORR     r0, r0, #(0x1 << 12)        // enable I Cache
        ORR     r0, r0, #(0x1 << 2)         // enable D Cache
        MCR     p15, 0, r0, c1, c0, 0       // write System Control Register

        BX    lr

 
