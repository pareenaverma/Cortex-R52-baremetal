// ****************************************************************************
// ****************************************************************************
//
// Project Name:		Cortex-R52 example
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

#ifndef GENERICTIMER_H_
#define GENERICTIMER_H_

void setCNTFRQ(unsigned int value);
unsigned int getCNTFRQ(void);
unsigned long long getCNTPCT(void);
void setCNTP_TVAL(unsigned int value);
unsigned int getCNTP_TVAL(void);
void setCNTV_TVAL(unsigned int value);
unsigned int getCNTV_TVAL(void);
void enablePhyTimer(void);
void disablePhyTimer(void);
void enableVirtualTimer(void);
void disableVirtualTimer(void);
void setCNTP_CVAL(unsigned long long value);
unsigned long long getCNTP_CVAL(void);
void setCNTV_CVAL(unsigned long long value);
unsigned long long getCNTV_CVAL(void);
void setCNTHP_TVAL(unsigned int value);
unsigned int getCNTHP_TVAL(void);
void enableHypTimer(void);
void disableHypTimer(void);
void setCNTHP_CVAL(unsigned long long value);
unsigned long long getCNTHP_CVAL(void);

#endif /*GENERICTIMER_H_ */
