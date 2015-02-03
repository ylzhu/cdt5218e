#ifndef _COMMON_H_
#define _COMMON_H_

#include "Cdt1028drv.h"

#define U32 uint32
#define U16 uint16
#define U8 uint8
#define S32 int32
#define S16 int16
#define S8 int8

//#define	RDATV_TEST
#define RA_INTERFACE extern
#ifdef _C51_
#define mrom code
#else
#define mrom 
#endif
#ifdef _C51_
#define REENTRANT reentrant
//#elif definded(_MIPS_)
//#define REENTRANT reentrant
#else
#define REENTRANT 
#endif
#endif
