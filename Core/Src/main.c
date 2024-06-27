/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#include "main.h"



int main(void)
{
	int16_t x, y, z;
	bool isADXL345Init = false;
	HAL_Init();
	SystemClock_Config();
	MX_GPIO_Init();
	MX_I2C1_Init();

  if(ADXL345_Init() == ADXL345_INIT_OK)
  {
	  isADXL345Init = true;
  }

  if(isADXL345Init == true)
  {
	  while (1)
	  {
		  if(ADXL345_ReadData(&x, &y, &z) == true)
		  {
			  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
			  HAL_Delay(500);
		  }
	  }
  }
}

