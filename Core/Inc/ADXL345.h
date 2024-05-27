/*
 * ADXL345.h
 *
 *  Created on: Jan 27, 2024
 *      Author: AliszjaElectron
 */

#include "SPI_DMA.h"
#include "ADXL_345_ADDR_REG.h"
#include "stdbool.h"
#include "stm32f7xx_hal.h"


bool ADXL345_SendData(uint16_t size, uint8_t data[size], uint8_t addr[size]);
bool ADXL345_ReceiveData(uint16_t size, uint8_t data[size], uint8_t addr[size]);
void ADXL345_Reset();

#ifndef SRC_ADXL345_H_
#define SRC_ADXL345_H_
#endif /* SRC_ADXL345_H_ */



