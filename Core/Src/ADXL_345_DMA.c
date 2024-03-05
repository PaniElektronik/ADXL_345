/*
 * ADXL_345_DMA.c
 *
 *  Created on: Jan 29, 2024
 *      Author: algac
 *      Communication: SPI 4-Wire
 *      8x Address Bits & 8x Data Bits (Send or Receive)
 */

#include "ADXL_345_DMA.h"


SPI_HandleTypeDef hspi1;
DMA_HandleTypeDef hdma_spi1_rx;
DMA_HandleTypeDef hdma_spi1_tx;


void SPIError_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
static void SPI_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
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
    SPIError_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void DMA_Init(void)
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

void ADXL_345_Communication_Init()
{
	SPI_Init();
	DMA_Init();
}


bool SPI_ReceiveData(uint8_t data[], uint8_t addr[])
{
	bool isReceive = false;
	bool isSend = false;
	if (sizeof(&data) ==8 && sizeof(&addr)==8)
	{
		if(HAL_SPI_Transmit_DMA(&hspi1, addr, sizeof(&addr))==HAL_OK)
		{
			isSend = true;
		}
		if (isSend == true)
		{
			if(HAL_SPI_Receive_DMA(&hspi1, data, sizeof(&data))==HAL_OK)
			{
				isReceive = true;
			}
		}
	}
		return isReceive;
}

bool SPI_SendData(uint8_t data[], uint8_t addr[])
{
	bool isOutOfData = true;
	bool isSend = false;
	uint8_t sendData[16];
	//
	/*
	 * Below is method of connect two array of data:
	 * address register + data to register
	 * That's a frame protocol SPI,
	 * described in datasheet ADXL_345
	 */
	if (sizeof(&data) ==8 && sizeof(&addr)==8)
	{
		int i;
		for (i = 0; i < 8; i++)
		{
			sendData[i] = addr[i];
			sendData[i+8] = data[i];
		}
		if (i>=16)
		{
			isOutOfData = true;
			isSend = false;
		}
	}
	else
	{
		isOutOfData = true;

	}
	if (isOutOfData == false)
	{
		if(HAL_SPI_Transmit_DMA(&hspi1, sendData, sizeof(&sendData))==HAL_OK)
		{
			isSend = true;
		}
	}
	else
	{
		isSend = false;
	}

	return isSend;
}
