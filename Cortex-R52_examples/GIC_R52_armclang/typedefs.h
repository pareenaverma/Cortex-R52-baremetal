// ****************************************************************************
// ****************************************************************************
//
// Project Name:		Cortex-R52 example
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

#ifndef _TYPEDEFS_H_
#define _TYPEDEFS_H_


/* This is needed for compilers that don't have a stdint.h file */

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef volatile signed char vint8_t;
typedef volatile unsigned char vuint8_t;

typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef volatile signed short vint16_t;
typedef volatile unsigned short vuint16_t;

typedef signed int int32_t;
typedef unsigned int uint32_t;
typedef volatile signed int vint32_t;
typedef volatile unsigned int vuint32_t;

typedef signed long long int64_t;
typedef unsigned long long uint64_t;
typedef volatile signed long long vint64_t;
typedef volatile unsigned long long vuint64_t;

#define bus_write_32(addr,data) ((*(uint32_t *)addr) = data)
#define bus_read_32(address) *((uint32_t *)(address))

#endif
