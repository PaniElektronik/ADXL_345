/**
 * @file 	ADXL345_I2C.h
 * @brief 	Communication Handler - header
 *
 *
 * @author 	PaniElektronik
 * @date 	21.06.2024
 */

/*------------------------------ INCLUDES ------------------------------*/
#include <stdbool.h>
#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_i2c.h"
/*------------------------------ DEFINES ------------------------------*/
#define ADXL345_ADDRESS         0x53
/*------------------------------ DECLARATIONS ------------------------------*/
extern void Error_Handler(void);
void MX_I2C1_Init(void);
/*------------------------------ OTHERS ------------------------------*/
#ifndef INC_ADXL_I2C_H_
#define INC_ADXL_I2C_H_
#endif /* INC_ADXL_I2C_H_ */
