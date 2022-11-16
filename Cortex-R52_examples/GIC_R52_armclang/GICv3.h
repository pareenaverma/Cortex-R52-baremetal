// ****************************************************************************
// ****************************************************************************
//
// Project Name:		R52 example
//
// Date:				$Date: 2015-11-19 16:27:02 +0000 (Thu, 19 Nov 2015) $
// Version: 			$Revision: 13894 $
// Author(s):			$Author: micbis01 $
// URL:					
//
// Company:				ARM
// Processor:			Cortex-R52
// Compiler:			armclang
//
// ****************************************************************************
// ****************************************************************************

#ifndef GICV3_H_
#define GICV3_H_

struct GICv3_dist_if
{
        vuint32_t CTLR;              // +0x0000 - RW - Distributor Control Register
  const vuint32_t TYPRE;             // +0x0004 - RO - Interrupt Controller Type Register
  const vuint32_t IIDR;              // +0x0008 - RO - Distributor Implementer Identification Register

  const vuint32_t padding0;               // +0x000C - RESERVED

        vuint32_t STATUSR;           // +0x0010 - RW - ????

  const vuint32_t padding1[3];            // +0x0014 - RESERVED

        vuint32_t IMP_DEF[8];             // +0x0020 - RW - Implementation defined registers

        vuint32_t SETSPI_NSR;        // +0x0040 - WO - Non-Secure Set SPI Pending (Used when SPI is signalled using MSI)
  const vuint32_t padding2;               // +0x0044 - RESERVED
        vuint32_t CLRSPI_NSR;        // +0x0048 - WO - Non-Secure Clear SPI Pending (Used when SPI is signalled using MSI)
  const vuint32_t padding3;               // +0x004C - RESERVED
        vuint32_t SETSPI_SR;         // +0x0050 - WO - Secure Set SPI Pending (Used when SPI is signalled using MSI)
  const vuint32_t padding4;               // +0x0054 - RESERVED
        vuint32_t CLRSPI_SR;         // +0x0058 - WO - Secure Clear SPI Pending (Used when SPI is signalled using MSI)

  const vuint32_t padding5[3];            // +0x005C - RESERVED

        vuint32_t SEIR;              // +0x0068 - WO - System Error Interrupt Register (Note: This was recently removed from the spec)

  const vuint32_t padding6[5];            // +0x006C - RESERVED

        vuint32_t IGROUPR[32];       // +0x0080 - RW - Interrupt Group Registers (Security Registers in GICv1)

        vuint32_t ISENABLER[32];     // +0x0100 - RW - Interrupt Set-Enable Registers
        vuint32_t ICENABLER[32];     // +0x0180 - RW - Interrupt Clear-Enable Registers
        vuint32_t ISPENDR[32];       // +0x0200 - RW - Interrupt Set-Pending Registers
        vuint32_t ICPENDR[32];       // +0x0280 - RW - Interrupt Clear-Pending Registers
        vuint32_t ISACTIVER[32];     // +0x0300 - RW - Interrupt Set-Active Register
        vuint32_t ICACTIVER[32];     // +0x0380 - RW - Interrupt Clear-Active Register

        vuint8_t  IPRIORITYR[1024];  // +0x0400 - RW - Interrupt Priority Registers
        vuint32_t ITARGETSR[256];    // +0x0800 - RW - Interrupt Processor Targets Registers
        vuint32_t ICFGR[64];         // +0x0C00 - RW - Interrupt Configuration Registers
        vuint32_t GRPMODR[32];       // +0x0D00 - RW - ????
  const vuint32_t padding7[32];           // +0x0D80 - RESERVED
        vuint32_t NSACR[64];         // +0x0E00 - RW - Non-Secure Access Control Register

        vuint32_t SGIR;              // +0x0F00 - WO - Software Generated Interrupt Register

  const vuint32_t padding8[3];            // +0x0F04 - RESERVED

        vuint32_t CPENDSGIR[4];      // +0x0F10 - RW - ???
        vuint32_t SPENDSGIR[4];      // +0x0F20 - RW - ???

  const vuint32_t padding9[52];           // +0x0F30 - RESERVED
  const vuint32_t padding10[5120];        // +0x1000 - RESERVED

        vuint64_t ROUTER[1024];      // +0x6000 - RW - Controls SPI routing when ARE=1
};

struct GICv3_sgiist_if
{
  const vuint32_t padding1[32];          // +0x0000 - RESERVED
        vuint32_t IGROUPR0;          // +0x0080 - RW - Interrupt Group Registers (Security Registers in GICv1)
  const vuint32_t padding2[31];          // +0x0084 - RESERVED
        vuint32_t ISENABLER0;        // +0x0100 - RW - Interrupt Set-Enable Registers
  const vuint32_t padding3[31];          // +0x0104 - RESERVED
        vuint32_t ICENABLER;        // +0x0180 - RW - Interrupt Clear-Enable Registers
  const vuint32_t padding4[31];          // +0x0184 - RESERVED
        vuint32_t ISPENDR;          // +0x0200 - RW - Interrupt Set-Pending Registers
  const vuint32_t padding5[31];          // +0x0204 - RESERVED
        vuint32_t ICPENDR;          // +0x0280 - RW - Interrupt Clear-Pending Registers
  const vuint32_t padding6[31];          // +0x0284 - RESERVED
        vuint32_t ISACTIVER;        // +0x0300 - RW - Interrupt Set-Active Register
  const vuint32_t padding7[31];          // +0x0304 - RESERVED
        vuint32_t ICACTIVER;        // +0x0380 - RW - Interrupt Clear-Active Register
  const vuint32_t padding8[31];          // +0x0184 - RESERVED
        vuint8_t  IPRIORITYR[32];   // +0x0400 - RW - Interrupt Priority Registers
  const vuint32_t padding9[504];         // +0x0420 - RESERVED
        vuint32_t ICFGR[2];         // +0x0C00 - RW - Interrupt Configuration Registers
  const vuint32_t padding10[62];		     // +0x0C08 - RESERVED
        vuint32_t GRPMODR;          // +0x0D00 - RW - ????
  const vuint32_t padding11[63];	       // +0x0D04 - RESERVED
        vuint32_t NSACR;            // +0x0E00 - RW - Non-Secure Access Control Register

};

struct GICv3_rdist_if
{
        vuint32_t CTLR;             // +0x0000 - RW - Redistributor Control Register
  const vuint32_t IIDR;             // +0x0004 - RO - Redistributor Implementer Identification Register
  const vuint32_t TYPER[2];         // +0x0008 - RO - ???
        vuint32_t STATUSR;          // +0x0010 - RW - ???
        vuint32_t WAKER;            // +0x0014 - RW - ???
  const vuint32_t padding1[10];          // +0x0018 - RESERVED
        vuint64_t SETLPIR;          // +0x0040 - WO -
        vuint64_t CLRLPIR;          // +0x0048 - WO -
  const vuint32_t padding2[6];           // +0x0058 - RESERVED
        vuint32_t SEIR;             // +0x0068 - WO - ??? (Note: This was recently removed from the spec)
  const vuint32_t padding3;              // +0x006C - RESERVED
        vuint64_t PROPBASER;        // +0x0070 - RW - ???
        vuint64_t PENDBASER;        // +0x0078 - RW - ???
  const vuint32_t padding4[8];           // +0x0080 - RESERVED
        vuint64_t INVLPIR;          // +0x00A0 - WO - ???
  const vuint32_t padding5[2];           // +0x00A8 - RESERVED
        vuint64_t INVALLR;          // +0x00B0 - WO - ???
  const vuint32_t padding6[2];           // +0x00B8 - RESERVED
        vuint64_t SYNCR;            // +0x00C0 - WO - ???
  const vuint32_t padding7[2];           // +0x00C8 - RESERVED
  const vuint32_t padding8[12];          // +0x00D0 - RESERVED
        vuint64_t MOVLPIR;          // +0x0100 - WO - ??? (Note: This is a GIC-500 IMPDEF register)
  const vuint32_t padding9[2];           // +0x0108 - RESERVED
        vuint64_t MOVALLR;          // +0x0110 - WO - ???
  const vuint32_t padding10[2];          // +0x0118 - RESERVED (Note: This is a GIC-500 IMPDEF register)
};

// +0 from ITS_BASE
struct GICv3_its_ctlr_if
{
        vuint32_t CTLR;             // +0x0000 - RW - ITS Control Register
  const vuint32_t IIDR;             // +0x0004 - RO - Implementer Identification Register
  const vuint64_t TYPER;            // +0x0008 - RO - ???
  const vuint32_t padding1[4];           // +0x0010 - RESERVED
        vuint32_t IMPDEF[8];        // +0x0020 - RW - IMP DEF registers
  const vuint32_t padding2[16];          // +0x0040 - RESERVED
        vuint64_t CBASER;           // +0x0080 - RW - ???
        vuint64_t CWRITER;          // +0x0088 - RW - ???
        vuint64_t CREADR;           // +0x0090 - RW - ???
  const vuint32_t padding3[2];           // +0x0098 - RESERVED
  const vuint32_t padding4[24];          // +0x00A0 - RESERVED
        vuint64_t BASER[8];         // +0x0100 - RW -
};

// +0x010000 from ITS_BASE
struct GICv3_its_int_if
{
  const vuint32_t padding1[16];          // +0x0000 - RESERVED
        vuint32_t TRANSLATER;       // +0x0040 - RW - ???
};

#define GICD		(*(volatile struct GICv3_dist_if *)	0xAF000000)
#define ITS			(*(volatile struct GICv3_its_ctlr_if *)	0xAF020000)
#define GICR_RD		(*(volatile struct GICv3_rdist_if *)	0xAF100000)
#define GICR_SGI	(*(volatile struct GICv3_sgiist_if *)	0xAF110000)

#endif /* GICV3_H_ */
