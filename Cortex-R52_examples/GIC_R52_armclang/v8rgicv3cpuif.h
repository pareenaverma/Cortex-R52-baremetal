// ****************************************************************************
// ****************************************************************************
//
// Project Name:	 Cortex-R52 example
//
// Date:				$Date: 2015-12-14 17:02:06 +0000 (Mon, 14 Dec 2015) $
// Version: 			$Revision: 14193 $
// Author(s):			$Author: micbis01 $
// URL:					
//
// Company:				ARM
// Processor:			Cortex-R52
// Compiler:			armclang
//
// ****************************************************************************
// ****************************************************************************

#ifndef V8RGICV3CPUIF_H_
#define V8RGICV3CPUIF_H_

void setICC_SRE(unsigned int value);
unsigned int getICC_SRE(void);
void setICC_HSRE(unsigned int value);
unsigned int getICC_HSRE(void);
void setICC_MSRE(unsigned int value);
unsigned int getICC_MSRE(void);
void enableGroup0Ints(void);
void disableGroup0Ints(void);
void enableGroup1Ints(void);
void disableGroup1Ints(void);
void enableNSGroup1Ints(void);
void disableNSGroup1Ints(void);
unsigned int getICC_MCTLR(void);
void setICC_MCTLR(unsigned int value);
unsigned int getICC_CTLR(void);
void setICC_CTLR(unsigned int value);
unsigned int getICH_HCR(void);
void setICH_HCR(unsigned int value);
unsigned int readIntAck(void);
void writeEOI(unsigned int ID);
void writeDIR(unsigned int ID);
unsigned int readAliasedIntAck(void);
void writeAliasedEOI(unsigned int ID);
void setPriorityMask(unsigned int ID);
unsigned int getBinaryPoint(void);
void setBinaryPoint(unsigned int ID);
unsigned int getAliasedBinaryPoint(void);
void setAliasedBinaryPoint(unsigned int ID);
unsigned int getRunningPriority(void);
void sendGroup0SGI(unsigned int ID, unsigned int mode, unsigned target_list);
void sendGroup1SGI(unsigned int ID, unsigned int mode, unsigned target_list);
void sendOtherGroup1SGI(unsigned int ID, unsigned int mode, unsigned target_list);
void setICH_AP1R0(unsigned int value);
unsigned int getICH_AP1R0(void);
void setICH_AP0R0(unsigned int value);
unsigned int getICH_AP0R0(void);
void setICH_LR0(unsigned int value);
unsigned int getICH_LR0(void);
void setICH_LRC0(unsigned int value);
unsigned int getICH_LRC0(void);
void setICH_LR1(unsigned int value);
unsigned int getICH_LR1(void);
void setICH_LRC1(unsigned int value);
unsigned int getICH_LRC1(void);
void setICH_LR2(unsigned int value);
unsigned int getICH_LR2(void);
void setICH_LRC2(unsigned int value);
unsigned int getICH_LRC2(void);
void setICH_LR3(unsigned int value);
unsigned int getICH_LR3(void);
void setICH_LRC3(unsigned int value);
unsigned int getICH_LRC3(void);

#endif /* V8RGICV3CPUIF_H_ */
