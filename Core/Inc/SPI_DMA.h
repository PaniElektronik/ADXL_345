
#include "stm32f7xx.h"
#include "stm32f7xx_hal_spi.h"
#include "stm32f7xx_hal.h"
#include "stm32f7xx_it.h"
#include "stm32f7xx_hal_dma.h"
#include "stdbool.h"



bool SPI_ReceiveData(uint16_t size, uint8_t data[size]);
bool SPI_SendData(int size, uint8_t sendData[size]);






