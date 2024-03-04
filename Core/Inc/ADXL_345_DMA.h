
#include "stm32f7xx.h"
#include "stm32f7xx_hal.h"
#include "stdbool.h"


static void DMA_Init();
static void SPI_Init();

void ADXL_345_Communication_Init();
void SPI_ReceiveData(uint8_t data[], uint8_t addr[]);
bool SPI_SendData(uint8_t data[], uint8_t addr[]);






