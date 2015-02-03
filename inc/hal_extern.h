#ifndef _HAL_EXTERN_H_
#define _HAL_EXTERN_H_

void i2c0SendData(U8 addr, U16 wdata);
U16 i2c0GetData(U8 addr);
void i2c1SendData(U16 page, U32 offset, U16 wdata);
U16 i2c1GetData(U16 page, U32 offset);
void i2c1SendDataA(U32 addr, U16 wdata);
U16 i2c1GetDataA(U32 addr);
void I2C_SEC_SET(unsigned char sec);

#endif
