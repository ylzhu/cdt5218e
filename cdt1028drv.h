/******************************************************************************

  Copyright (C), 2011-2012, CDT Co., Ltd.

 ******************************************************************************
  File Name     : cdt1028drv.h
  Version       : Initial Draft
  Author        : ZhengJH
  Created       : 2011/4/29
  Last Modified :
  Description   : cdt1028drv.h
  Function List :
  History       :
  1.Date        : 2011/4/29
    Author      : ZhengJH
    Modification: Created file

******************************************************************************/


#ifndef TUNER_RDA_H
#define TUNER_RDA_H


// ---------------------------------------------------------------
// select below option , usd in differen Platform
// ---------------------------------------------------------------
//#define _C51_
#define _MIPS_
#define _PLATFORM_KD_




#ifdef _C51_
#define LARGE large
#define XDATA xdata
#define CODE code
#elif defined(_MIPS_)
#define LARGE
#define XDATA
#define CODE
#elif defined(_X86_PLATFORM_)
#define LARGE
#define XDATA
#define CODE
#define PRINTF
#include "stdio.h"
#include "..\X86DataType.h"
#else
#define LARGE
#define XDATA
#define CODE
#define PRINTF
#endif

// ---------------------------------------------------------------------------
// BASIC TYPES DEFINITIONS
// ---------------------------------------------------------------------------
#ifndef _X86_PLATFORM_ 
#ifdef _C51_
    #ifndef uint8
    typedef unsigned char uint8;
    #endif
    
    #ifndef uint16
    typedef unsigned int uint16;
    #endif
    
    #ifndef uint32
    typedef unsigned long uint32;
    #endif
    
    #ifndef int8
    typedef signed char int8;
    #endif
    
    #ifndef int16
    typedef signed int int16;
    #endif
    
    #ifndef int32
    typedef signed long  int32;
    #endif

#elif defined(_MIPS_)
    #ifndef uint8
    typedef unsigned char uint8;
    #endif
    
    #ifndef uint16
    typedef unsigned short uint16;
    #endif
    
    #ifndef uint32
    typedef unsigned int uint32;
    #endif
    
    #ifndef int8
    typedef signed char int8;
    #endif
    
    #ifndef int16
    typedef signed short int16;
    #endif
    
    #ifndef int32
    typedef signed int  int32;
    #endif
	
#else

    #ifndef uint8
    typedef unsigned char uint8;
    #endif
    
    #ifndef uint16
    typedef unsigned short uint16;
    #endif
    
    #ifndef uint32
    typedef unsigned long int uint32;
    #endif
    
    #ifndef int8
    typedef signed char int8;
    #endif
    
    #ifndef int16
    typedef signed short int16;
    #endif
    
    #ifndef int32
    typedef signed long int int32;
    #endif

#endif
#endif

#ifndef TRUE
#define TRUE            (1 == 1)
#endif

#ifndef FALSE
#define FALSE           (0 == 1)  
#endif

#ifndef NULL
#define NULL            ((void *)0)
#endif
// ------------------------ END TYPE DEFINITIONS -----------------------------

// ---------------------------------------------------------------------------
// CDTMTV return code definitions
// ---------------------------------------------------------------------------

#define U32 uint32
#define U16 uint16
#define U8 uint8
#define S32 int32
#define S16 int16
#define S8 int8

#define RDA5880DM_PRODUCT_ID   0x5176

#define RDA5880DM_CHIP_ID_0    0xc4
#define RDA5880DM_CHIP_ID_1    0xc2
#define PAGE_DEMOD_SCU 0x008

#define RDATV_IF_FREQ           (5000)
#define TUNER_NAME              "RDA5880"

#define PAGE_AFE_SDM 0x010
#define PAGE_AGC_TUNER 0x014
#define PAGE_IQM 0x018
#define PAGE_ATV 0x00c
#define PAGE_FM_HV 0x01c

// for TV
#define TH_MIN_GAIN 77 //82    //20dbuv
#define TH_MIN_CR_FREQ 50//50
#define TH_MAX_FM_AFC 0x15
#define TH_MIN_FM_SIGNAL 0x5a
#define TH_MAX_FM_NOISE 0x50

// for fm
#define TH_MAX_FM_FM_AFC  25// 32  // 0x14 -> 20
#define TH_FM_FM_SIGNAL_NOISE 3  // 0x4E ->78  
//#define TH_MAX_FM_FM_NOISE 73   // 3c->60


//#define REENTRANT reentrant



#define SEEK_DEBUG

#ifdef SEEK_DEBUG
#define SCU_RAM_SEEK_FLT_VGA_GAIN                                           0x831E80
#define SCU_RAM_SEEK_DIG_GAIN                                               0x831E81
#define SCU_RAM_SEEK_CR_FREQ                                                0x831E82
#define SCU_RAM_SEEK_CR_LOCK                                                0x831E83
#define SCU_RAM_SEEK_LINE_NUM                                               0x831E84
#define SCU_RAM_SEEK_VID_STATUS                                             0x831E85
#define SCU_RAM_SEEK_AUD_STATUS                                             0x831E86
#define SCU_RAM_SEEK_FM_BASE                                                0x831E87
#define SCU_RAM_SEEK_FM_AFC0                                                0x831E87
#define SCU_RAM_SEEK_FM_SIG0                                                0x831E88
#define SCU_RAM_SEEK_FM_NIS0                                                0x831E89
#define SCU_RAM_SEEK_FM_PRI0                                                0x831E8a
#define SCU_RAM_SEEK_FM_AFC1                                                0x831E8b
#define SCU_RAM_SEEK_FM_SIG1                                                0x831E8c
#define SCU_RAM_SEEK_FM_NIS1                                                0x831E8d
#define SCU_RAM_SEEK_FM_PRI1                                                0x831E8e
#define SCU_RAM_SEEK_FM_AFC2                                                0x831E8f
#define SCU_RAM_SEEK_FM_SIG2                                                0x831E90
#define SCU_RAM_SEEK_FM_NIS2                                                0x831E91
#define SCU_RAM_SEEK_FM_PRI2                                                0x831E92
#define SCU_RAM_SEEK_FM_AFC3                                                0x831E93
#define SCU_RAM_SEEK_FM_SIG3                                                0x831E94
#define SCU_RAM_SEEK_FM_NIS3                                                0x831E95
#define SCU_RAM_SEEK_FM_PRI3                                                0x831E96
#endif


typedef enum
{
    CDTMTV_RT_SUCCESS = 0,
    CDTMTV_RT_IIC_ERROR,
    CDTMTV_RT_SCAN_FAIL,
    CDTMTV_RT_SCAN_DONE,
    CDTMTV_RT_SCAN_TIMEOUT,
    CDTMTV_RT_SCAN_IN_AFCWIN,
    CDTMTV_RT_SCAN_GOT_YSIGN,
    CDTMTV_RT_SCAN_EMPTY_CH,
    #ifdef DEBUG_SCAN
    CDTMTV_RT_SCAN_YSNR_FAIL,
    CDTMTV_RT_SCAN_FMC_FAIL,   
    CDTMTV_RT_SCAN_HV_FAIL,
    #endif	
    CDTMTV_RT_ERROR
} TV_RES;

// ---------------------------------------------------------------------------
// Commonly used video formats and FM mode are included here.  
// ---------------------------------------------------------------------------
 typedef enum {
    CDTMTV_VSTD_M, 
    CDTMTV_VSTD_M_X, 		
    CDTMTV_VSTD_N,
    CDTMTV_VSTD_N_X,
    CDTMTV_VSTD_BG,
    CDTMTV_VSTD_BG_X,
    CDTMTV_VSTD_I,
    CDTMTV_VSTD_I_X,
    CDTMTV_VSTD_DK,
    CDTMTV_VSTD_DK_X,
    CDTMTV_VSTD_L,

    CDTMTV_VSTD_FM,
    CDTMTV_VSTD_NONE        = 255   // No Video Standard Specified
}STD_T;

typedef enum
{
    LINE_525,
    LINE_625,
    LINE_NOTSTD,
    LINE_NULL
}RDA_SCAN_LINE_NUM;

typedef enum
{
    VID_EMPTY_STA,
    VID_NOTFINDPIC_STA,        
    VID_NEEDRETUNE_STA,
    VID_YLOCKED_STA,
    VID_FINDPIC_STA
}RDA_SCAN_VIDEO_STATUS;

typedef enum
{
    AUD_FALSE,
    AUD_TRUE
}RDA_SCAN_AUDIO_STATUS;

typedef enum
{
    RDA_DK = 0,
    RDA_I,    // 1
    RDA_GH,
    RDA_B,
    RDA_N,
    RDA_M,
    RDA_L,
    RDA_L1,
    RDA_ATV_SEEK = 0x07,
    RDA_DTV_6M,    //8
    RDA_DTV_7M,
    RDA_DTV_8M,
    RDA_FM,
    RDA_TV_MODE_QTY=13
}RDA_TV_MODE;

typedef enum
{
	FM_DK,
	FM_I,
	FM_BGH,
	FM_MN,
	FM_NULL
}RDA_FM_STARD;

typedef struct rda_scan_ch_res_t
{
    RDA_SCAN_VIDEO_STATUS vid_sta;
    RDA_SCAN_AUDIO_STATUS aud_sta;

    RDA_SCAN_LINE_NUM line_num;
    RDA_FM_STARD fm_stand;
    int32 seek_incr;
    uint32 u32Freq;
}rda_scan_ch_res;


typedef struct RDA_CH_HV_TYPE
{
   	uint16 cnt_times_ntsc;
    uint16 cnt_times_pal;
}rda_ch_hv_type;

typedef struct rda_tuner_cfg_t
{
    uint8 xtal_mode;
    uint8 freq_lo_index;
    uint8 freq_adc_index;
    uint8 chip_mode;
    uint8 tv_mode_index;
    uint8 lna_index;
    uint8 demod_mach;
    uint8 lna_mode;
    uint8 adc_mode;

    uint16 lna_cap;
    uint16 xtal;
    uint16 i2vth_dtvh;
    uint16 i2vth_dtvl;
    uint16 i2vth_atvh;
    uint16 i2vth_atvl;
    uint32 freq;
    uint32 freq_lo;
    uint32 freq_vco_core;
    uint32 mdll_n;
    uint32 freq_if_out;
	rda_ch_hv_type hv_type_data;  // add data type to record HV type.
}rda_tuner_cfg;

/*init*/
/*TV module*/
/*enter TV mode*/
uint8 CDT1028_ENTER_TV(void)LARGE;

/*set working mode*/
void CDT1028_SetSystemMode(uint8 SystemMode)LARGE;

/*get working mode*/
uint8 CDT1028_GetSystemMode(void)LARGE;

/*TV set freq*/
void CDT1028_FreqSet(uint32 dwVFreq)LARGE;

/*TV scan freq point*/
uint8 CDT1028_ScanChAllMode(uint32 dwVFreq )LARGE;

/*FM module*/
/*enter FM mode*/
uint8 CDT1028_ENTER_FM(void)LARGE;

/*TV set freq*/
void CDT1028_FM_FreqSet(uint32 dwVFreq)LARGE;

/*FM scan freq point*/
uint8 CDT1028_FM_ScanChannel(uint32 dwVFreq )LARGE;


/*others*/
void CDT1028_SetVolume(uint8 nValue)LARGE;

/*Get driver verison*/
uint32 CDT1028_GetVersion(void) LARGE;
/*Get device iD*/
uint16 CDT1028_GetDevice(void)LARGE;

/*only api as rda5218, no option for device*/
uint8 CDT1028_Tuning(void) LARGE;
uint8 CDT1028_Seek(void) LARGE;
void CDT1028_FM_Afcabs(uint8 ucValue) LARGE;  // 0x07 - 0x1A good:0x17

/* if off == 1 set mute, 0 release */ 
void CDT1028_SetMute(uint8 off) LARGE;

uint8 CDT1028_SetPDN(uint8 on) LARGE; 

#endif /* end __CDTMTVIF_H__ */
