/**
 * @file 	ADXL345.h
 * @brief 	ADXL345 Header
 *
 *
 * @author 	PaniElektronik
 * @date 	21.06.2024
 */

/*------------------------------ INCLUDES ------------------------------*/
#include "ADXL345_I2C.h"
#include "stm32f7xx_hal.h"
/*------------------------------ DEFINES ------------------------------*/
#define ADXL345_REG_DEVID       0x00
#define ADXL345_REG_POWER_CTL   0x2D
#define ADXL345_REG_DATA_FORMAT 0x31
#define ADXL345_REG_BW_RATE     0x2C
#define ADXL345_REG_FIFO_CTL    0x38
#define ADXL345_REG_DATAX0      0x32

#define G 9.81
#define RANGE 2.0
#define MAX_RAW_VALUE 32768.0 // 16-bit signed integer has a range from -32768 to 32767
/*------------------------------ DECLARATIONS ------------------------------*/
extern I2C_HandleTypeDef hi2c1;
typedef enum
{
	ADXL345_INIT_OK,
	POWER_CTL_ERR,
	DATA_FORMAT_ERR,
	BW_RATE_ERR,
	FIFO_CTL_ERR,
}ADXL345_RegInit;

ADXL345_RegInit ADXL345_Init(void);
bool ADXL345_ReadData(int16_t* x, int16_t* y, int16_t* z);
uint8_t ADXL345_ReadRegister(uint8_t regAddr, uint8_t *regData);
bool ADXL345_WriteRegister(uint8_t regAddr, uint8_t regData);
bool ADXL345_ReadMultiRegister(uint8_t regAddr, uint8_t *regData, uint16_t regDataSize);
/*------------------------------ OTHERS ------------------------------*/
#ifndef INC_ADXL345_H_
#define INC_ADXL345_H_
#endif /* INC_ADXL345_H_ */
