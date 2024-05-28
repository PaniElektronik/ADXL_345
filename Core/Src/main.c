/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

#include "main.h"

/**
 * ----------------------------------------------------------------
 @brief			main function
 @param[in]
 @param[out]
 @return
 * ----------------------------------------------------------------
 **/
int main(void)
{

  HAL_Init();

  /* Initialize all configured peripherals */
  SystemClock_Config();
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_SPI1_Init();

  uint8_t data[8] = {1,2,3,4,5,6,7,8};
  while (1)
  {
	  // TEST
	  if(ADXL345_SendData(8, data, data)==true)
	  {
		  HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin);
	  }
	  else
	  {
		  HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	  }
	  HAL_Delay(500);
  }

}

/**
 * ----------------------------------------------------------------
 @brief			Error Handler
 @param[in]		-
 @param[out]	-
 @return		-
 * ----------------------------------------------------------------
 **/
void Error_Handler()
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}


#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
