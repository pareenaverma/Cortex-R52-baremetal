// ****************************************************************************
// ****************************************************************************
//
// Project Name:		R52 example
//
// Date:				$Date: $
// Version: 			$Revision: $
// Author(s):			$Author: $
// URL:					$HeadURL: $
//
// Company:				ARM
// Processor:			Cortex-R52
// Compiler:			armclang
//
// ****************************************************************************
// ****************************************************************************

//==================================================================
	.section  generictimer,"ax"
#ifdef __THUMB__
	.thumb
#endif
	.balign 4
	.global setCNTFRQ
	.type setCNTFRQ, %function
setCNTFRQ:							// Arguments: system counter clock frequency, in Hz
  mcr p15, 0, r0, c14, c0, 0 		// Write r0 to CNTFRQ
  bx lr

	.balign 4
	.global getCNTFRQ
	.type getCNTFRQ, %function
getCNTFRQ:							// Return: system counter clock frequency, in Hz
  mrc p15, 0, r0, c14, c0, 0		// Read CNTFRQ into r0
  bx lr

	.balign 4
	.global getCNTPCT
	.type getCNTPCT, %function
getCNTPCT:							// Return: low and high word
  mrrc p15, 0, r0, r1, c14 			// Read 64-bit CNTPCT into r0 (low word) and r1 (high word)
  bx lr

	.balign 4
	.global setCNTP_TVAL
	.type setCNTP_TVAL, %function
setCNTP_TVAL:						// Arguments: physical timer value
  mcr p15, 0, r0, c14, c2, 0 		// Write r0 to CNTP_TVAL
  bx lr

	.balign 4
	.global getCNTP_TVAL
	.type getCNTP_TVAL, %function
getCNTP_TVAL:						// Return: physical timer value
  mrc p15, 0, r0, c14, c2, 0		// Read CNTP_TVAL into r0
  bx lr

  .balign 4
	.global setCNTV_TVAL
	.type setCNTV_TVAL, %function
setCNTV_TVAL:						// Arguments: virtual timer value
  mcr p15, 0, r0, c14, c3, 0 		// Write r0 to CNTV_TVAL
  bx lr

	.balign 4
	.global getCNTV_TVAL
	.type getCNTV_TVAL, %function
getCNTV_TVAL:						// Return: virtual timer value
  mrc p15, 0, r0, c14, c3, 0		// Read CNTV_TVAL into r0
  bx lr

	.balign 4
	.global enablePhyTimer
	.type enablePhyTimer, %function
enablePhyTimer:
  ldr r0, =0x1						// Enable timer
  mcr p15, 0, r0, c14, c2, 1  		// Write r0 to CNTP_CTL
  bx lr

	.balign 4
	.global disablePhyTimer
	.type disablePhyTimer, %function
disablePhyTimer:
  ldr r0, =0x0						// Disable timer
  mcr p15, 0, r0, c14, c2, 1  		// Write r0 to CNTP_CTL
  bx lr

	.balign 4
	.global enableVirtualTimer
	.type enableVirtualTimer, %function
enableVirtualTimer:
  ldr r0, =0x1						// Enable timer
  mcr p15, 0, r0, c14, c3, 1 		// Write r0 to CNTV_CTL
  bx lr

	.balign 4
	.global disableVirtualTimer
	.type disableVirtualTimer, %function
disableVirtualTimer:
  ldr r0, =0x1						// Disable timer
  mcr p15, 0, r0, c14, c3, 1 		// Write r0 to CNTV_CTL
  bx lr

	.balign 4
	.global setCNTP_CVAL
	.type setCNTP_CVAL, %function
setCNTP_CVAL:						// Arguments: low and high word
  mcrr p15, 2, r0, r1, c14			// Write r0 (low word) and r1 (high word) to 64-bit CNTP_CVAL
  bx lr

	.balign 4
	.global getCNTP_CVAL
	.type getCNTP_CVAL, %function
getCNTP_CVAL:						// Return: low and high word
  mrrc p15, 2, r0, r1, c14			// Read 64-bit CNTP_CVAL into r0 (low word) and r1 (high word)
  bx lr

	.balign 4
	.global setCNTV_CVAL
	.type setCNTV_CVAL, %function
setCNTV_CVAL:						// Arguments: low and high word
  mcrr p15, 3, r0, r1, c14			// Write r0 (low word) and r1 (high word) to 64-bit CNTV_CVAL
  bx lr

	.balign 4
	.global getCNTV_CVAL
	.type getCNTV_CVAL, %function
getCNTV_CVAL:						// Return: low and high word
  mrrc p15, 3, r0, r1, c14			// Read 64-bit CNTV_CVAL into r0 (low word) and r1 (high word)
  bx lr

	.balign 4
	.global setCNTVOFF
	.type setCNTVOFF, %function
setCNTVOFF:							// Arguments: low and high word
  mcrr p15, 4, r0, r1, c14			// Write r0 (low word) and r1 (high word) to 64-bit CNTVOFF
  bx lr

	.balign 4
	.global getCNTVOFF
	.type getCNTVOFF, %function
getCNTVOFF:							// Return: low and high word
  mrrc p15, 4, r0, r1, c14			// Read 64-bit CNTVOFF into r0 (low word) and r1 (high word)
  bx lr

  .balign 4
	.global setCNTHP_TVAL
	.type setCNTHP_TVAL, %function
setCNTHP_TVAL:						// Arguments: virtual timer value
  mcr p15, 4, r0, c14, c2, 0 		// Write r0 to CNTHP_TVAL
  bx lr

	.balign 4
	.global getCNTHP_TVAL
	.type getCNTHP_TVAL, %function
getCNTHP_TVAL:						// Return: virtual timer value
  mrc p15, 4, r0, c14, c2, 0		// Read CNTHP_TVAL into r0
  bx lr

	.balign 4
	.global enableHypTimer
	.type enableHypTimer, %function
enableHypTimer:
  ldr r0, =0x1						// Enable timer
  mcr p15, 4, r0, c14, c1, 0  		// Write r0 to CNTHP_CTL
  bx lr

	.balign 4
	.global disableHypTimer
	.type disableHypTimer, %function
disableHypTimer:
  ldr r0, =0x0						// Disable timer
  mcr p15, 4, r0, c14, c1, 0  		// Write r0 to CNTHP_CTL
  bx lr

	.balign 4
	.global setCNTHP_CVAL
	.type setCNTHP_CVAL, %function
setCNTHP_CVAL:						// Arguments: low and high word
  mcrr p15, 6, r0, r1, c14			// Write r0 (low word) and r1 (high word) to 64-bit CNTHP_CVAL
  bx lr

	.balign 4
	.global getCNTHP_CVAL
	.type getCNTHP_CVAL, %function
getCNTHP_CVAL:						// Return: low and high word
  mrrc p15, 6, r0, r1, c14			// Read 64-bit CNTHP_CVAL into r0 (low word) and r1 (high word)
  bx lr

