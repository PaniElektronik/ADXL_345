/**
 * ----------------------------------------------------------------
 @file		SPI_DMA.c
 @anchor	GPIO_Config.c
 @brief		Communication Module
 @author	Alicja Gackowiec (PaniElektronik)
 @version	v1.0
 * ----------------------------------------------------------------
 **/
#include "SPI_DMA.h"

/*---------------------------	Variables	---------------------------*/
SPI_HandleTypeDef hspi1;
DMA_HandleTypeDef hdma_spi1_rx;
DMA_HandleTypeDef hdma_spi1_tx;


/**
 * ----------------------------------------------------------------
 @brief			SPI Communication config
 @param[in]
 @param[out]
 @return
 * ----------------------------------------------------------------
 **/
void MX_SPI1_Init()
{
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_4BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_HARD_OUTPUT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 7;
  hspi1.Init.CRCLength = SPI_CRC_LENGTH_DATASIZE;
  hspi1.Init.NSSPMode = SPI_NSS_PULSE_ENABLE;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }

}

/**
 * ----------------------------------------------------------------
 @brief			DMA Communication config
 @param[in]
 @param[out]
 @return
 * ----------------------------------------------------------------
 **/
void MX_DMA_Init()
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA2_Stream0_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);
  /* DMA2_Stream3_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream3_IRQn);

}

/**
 * ----------------------------------------------------------------
 @brief			Receive data from ADXL funcion
 @param[in]		size - size of data
 	 	 	 	data - sample to receive
 @param[out]
 @return		isReceive - procedure's flag
 * ----------------------------------------------------------------
 **/
bool SPI_ReceiveData(uint8_t data)
{
	bool isReceive = false;

	if(HAL_SPI_Receive_DMA(&hspi1, &data, sizeof(data))==HAL_OK)
	{
		isReceive = true;
	}
		return isReceive;
}
/**
 * ----------------------------------------------------------------
 @brief			Send data to ADXL funcion
 @param[in]		size - size of data
 	 	 	 	data - sample to send
 @param[out]
 @return		isSend - procedure's flag
 * ----------------------------------------------------------------
 **/
bool SPI_SendData(uint8_t sendData)
{
	bool isSend = false;
	uint32_t Timeout = 1000;
	uint32_t tickstart = HAL_GetTick();


	if(HAL_SPI_Transmit_DMA(&hspi1, &sendData, sizeof(sendData))==HAL_OK)
	{
		isSend = true;
	}


	return isSend;
}


