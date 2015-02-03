/******************************************************************************

  Copyright (C), 2011-2012, CDT Co., Ltd.

 ******************************************************************************
  File Name     : cdt1028interface.c
  Version       : Initial Draft
  Author        : ZhengJH
  Created       : 2011/4/29
  Last Modified :
  Description   : cdt1028interface.c
  Function List :
              cdtReadReg
              cdtWriteReg
              cdt_delay_ms
  History       :
  1.Date        : 2011/4/29
    Author      : ZhengJH
    Modification: Created file

******************************************************************************/
#include "cdt1028drv.h"

/*----------------------------------------------*
 * external variables                           *
 *----------------------------------------------*/

/*----------------------------------------------*
 * external routine prototypes                  *
 *----------------------------------------------*/

/*----------------------------------------------*
 * internal routine prototypes                  *
 *----------------------------------------------*/

/*----------------------------------------------*
 * project-wide global variables                *
 *----------------------------------------------*/

/*----------------------------------------------*
 * module-wide global variables                 *
 *----------------------------------------------*/

/*----------------------------------------------*
 * constants                                    *
 *----------------------------------------------*/

/*----------------------------------------------*
 * macros                                       *
 *----------------------------------------------*/
#if defined (_C51_)
#elif defined (_MIPS_)
#else
#include "platform.h"
#include "pfdriver.h"
#endif
/*----------------------------------------------*
 * routines' implementations                    *
 *----------------------------------------------*/

uint8 cdtWriteReg(uint8 chip_addr, uint8 reg_addr, uint16 Data)LARGE
{
	/*Add your iic writereg function, Data is always 16bit data,*/
  #if defined (_C51_)
  chip_addr = chip_addr;
  reg_addr = reg_addr;
  Data = Data;
  return 0;
  #elif defined (_MIPS_)
  chip_addr = chip_addr;
  reg_addr = reg_addr;
  Data = Data;  
  return 0;
  #else
	return WriteReg(chip_addr, reg_addr, Data); /*这里返回您的IIC错误码，0为IIC通讯成功，大于0则错误。
	包内函数捕获IIC错误会停止通讯，返回CDTMTV_RT_IIC_ERROR,u16记得是先送高位再送低位*/
  #endif  
}

uint8 cdtReadReg(uint8 chip_addr, uint8 reg_addr, uint16 *pData)LARGE
{
	/*Add your iic readreg function*/
  #if defined (_C51_)
  chip_addr = chip_addr;
  reg_addr = reg_addr;
  pData = pData;  
  return 0;
  #elif defined (_MIPS_)
  chip_addr = chip_addr;
  reg_addr = reg_addr;
  pData = pData;  
  return 0;
  #else
	return ReadReg(chip_addr, reg_addr, pData);
  #endif
}

/*****************************************************************************
 Prototype    : cdt_w_reg
 Description  : iic write function
 Input        : uint8 chip_addr  
                uint8* reg_addr  
                uint8 addr_size  
                uint8* Data      
                uint32 size      
 Output       : None
 Return Value : 
 Calls        : 
 Called By    : 
 
 History        :
  1.Date         : 2014/5/10
    Author       : ZhengJH
    Modification : Created function

*****************************************************************************/
uint8 cdt_w_reg(uint8 chip_addr, uint8* reg_addr, uint8 addr_size, uint8* Data,  uint32 size)LARGE
{
	/*Add your iic writereg function*/    
  #if defined (_C51_)
  chip_addr = chip_addr;
  reg_addr = reg_addr;
  addr_size = addr_size;
  Data = Data;
  size = size;
  return 0;
  #elif defined (_MIPS_)
  chip_addr = chip_addr;
  reg_addr = reg_addr;
  addr_size = addr_size;
  Data = Data;
  size = size;  
  return 0;
  #else
  return (*WriteRegWithDataLen)(chip_addr, reg_addr, addr_size, Data, size); 
  #endif
}

/*****************************************************************************
 Prototype    : cdt_r_reg
 Description  : iic read function
 Input        : uint8 chip_addr  
                uint8* reg_addr  
                uint8 addr_size  
                uint8 *pData     
                uint32 size      
 Output       : None
 Return Value : 
 Calls        : 
 Called By    : 
 
 History        :
  1.Date         : 2014/5/10
    Author       : ZhengJH
    Modification : Created function

*****************************************************************************/
uint8 cdt_r_reg(uint8 chip_addr, uint8* reg_addr, uint8 addr_size, uint8 *pData, uint32 size)LARGE
{
	/*Add your iic readreg function*/
  #if defined (_C51_)
  chip_addr = chip_addr;
  reg_addr = reg_addr;
  addr_size = addr_size;
  pData = pData;
  size = size;
  return 0;
  #elif defined (_MIPS_)
  chip_addr = chip_addr;
  reg_addr = reg_addr;
  addr_size = addr_size;
  pData = pData;
  size = size;
  return 0;
  #else 
  return (*ReadRegWithDataLen)(chip_addr, reg_addr, addr_size, pData, size);
  #endif
}

/*****************************************************************************
 Prototype    : cdt_usrSlowIIC
 Description  : Set the speed of the IIC to slow
 Input        : void * pParam  
 Output       : None
 Return Value : 
 Calls        : 
 Called By    : 
 
 History        :
  1.Date         : 2014/5/10
    Author       : ZhengJH
    Modification : Created function

*****************************************************************************/
uint8 cdt_usrSlowIIC(void * pParam)LARGE
{
    //user's codes
  #if defined (_C51_)
  pParam = pParam;
  return 0;
  #elif defined (_MIPS_)
  pParam = pParam;
  return 0;
  #else 
  //pParam = pParam;
  (*SetI2cSpeed)(20); // 20K
  
  return 0;
  #endif
}

/*****************************************************************************
 Prototype    : cdt_usrFastIIC
 Description  : Set the speed of the IIC to high
 Input        : void * pParam  
 Output       : None
 Return Value : 
 Calls        : 
 Called By    : 
 
 History        :
  1.Date         : 2014/5/10
    Author       : ZhengJH
    Modification : Created function

*****************************************************************************/
uint8 cdt_usrFastIIC(void * pParam)LARGE
{
  //user's codes
  #if defined (_C51_)
  pParam = pParam;
  return 0;
  #elif defined (_MIPS_)
  pParam = pParam;
  return 0;
  #else
  //pParam = pParam;

  (*SetI2cSpeed)(100); // 100K

  return 0;
  #endif
}

/*****************************************************************************
 Prototype    : cdt_delay_ms
 Description  : delay function
 Input        : uint8 ucMs  
 Output       : None
 Return Value : 
 Calls        : 
 Called By    : 
 
 History        :
  1.Date         : 2014/5/10
    Author       : ZhengJH
    Modification : Created function

*****************************************************************************/
void cdt_delay_ms(uint8 ucMs)LARGE
{
	/*Add your delay function*/
  #if defined (_C51_)
  ucMs = ucMs;
  #elif defined (_MIPS_)
  ucMs = ucMs;
  #else
	Sleep(ucMs);
  #endif
}

	
