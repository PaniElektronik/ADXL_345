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
/*------------------------------ DEFINES ------------------------------*/
#define ADXL345_REG_DEVID       0x00
#define ADXL345_REG_POWER_CTL   0x2D
#define ADXL345_REG_DATA_FORMAT 0x31
#define ADXL345_REG_BW_RATE     0x2C
#define ADXL345_REG_FIFO_CTL    0x38
#define ADXL345_REG_DATAX0      0x32
#define ADXL345_REG_TAP_AXES  	0x2A
#define ADXL345_REG_THRESH_TAP  0x1D
#define ADXL345_REG_DUR  		0x21
#define ADXL345_REG_LATENT  	0x22
#define ADXL345_REG_WINDOW  	0x23

#define GRAVITY 				9.81
#define RANGE 					2.0
#define MAX_RAW_VALUE 			32768.0 // 16-bit signed integer has a range from -32768 to 32767
#define SCALE_FACTOR 			0.0039  // 4mg/LSB for ±16g range (assuming 16g range)
#define SAMPLE_PERIOD 			0.01  // Próbkujemy co 10 ms (100 Hz)
/*------------------------------ DECLARATIONS ------------------------------*/
extern I2C_HandleTypeDef hi2c1;
typedef enum {
    ADXL345_INIT_OK,
    POWER_CTL_ERR,
    DATA_FORMAT_ERR,
    BW_RATE_ERR,
    FIFO_CTL_ERR,
    TAP_AXES_ERR,
    THRESH_TAP_ERR,
    DUR_ERR,
    LATENT_ERR,
    WINDOW_ERR
} ADXL345_RegInit;


ADXL345_RegInit ADXL345_Init(void);
bool ADXL345_ReadData(int16_t* x, int16_t* y, int16_t* z);
uint8_t ADXL345_ReadRegister(uint8_t regAddr, uint8_t *regData);
bool ADXL345_WriteRegister(uint8_t regAddr, uint8_t regData);
bool ADXL345_ReadMultiRegister(uint8_t regAddr, uint8_t *regData, uint16_t regDataSize);

void ConvertToMS2(int16_t raw, float* ms2);
bool CalculateDisplacement(void);
/*------------------------------ OTHERS ------------------------------*/
#ifndef INC_ADXL345_H_
#define INC_ADXL345_H_
#endif /* INC_ADXL345_H_ */
