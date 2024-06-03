/**
 * ----------------------------------------------------------------
 @file		ADXL345.h
 @anchor	ADXL345.c
 @brief		ADXL345 Header File
 @author	Alicja Gackowiec (PaniElektronik)
 @version	v1.0
 * ----------------------------------------------------------------
 **/

/*---------------------------	Includes	---------------------------*/
#include "SPI_DMA.h"
#include "ADXL_345_ADDR_REG.h"
#include "stdbool.h"
#include "stm32f7xx_hal.h"

/*---------------------------	Variables	---------------------------*/


/*---------------------------	Functions	---------------------------*/
void ADXL345_Init();
bool ADXL345_WriteReg(uint8_t data, uint8_t addr);
bool ADXL345_ReadReg(uint8_t data, uint8_t addr);
void ADXL345_Reset();


//#ifndef SRC_ADXL345_H_
//#define SRC_ADXL345_H_
//#endif /* SRC_ADXL345_H_ */



