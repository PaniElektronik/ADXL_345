/**
 * @file 	SSD1306_I2C.c
 * @brief 	Communication (I2C) Handler
 *
 *
 * @author 	PaniElektronik
 * @date 	28.06.2024
 */

/*------------------------------ INCLUDES ------------------------------*/
#include "stm32f7xx_hal.h"
#include "SSD1306.h"
/*------------------------------ DECLARATIONS ------------------------------*/
I2C_HandleTypeDef hi2c2;
/*------------------------------ FUNCTIONS ------------------------------*/
/**
 * @name			MX_I2C2_Init(void)
 * @brief			I2C Communication configuration
 *
 * @param[in]		-
 * @param[in,out]	-
 * @param[out]		-
 * @return			-
 */
void MX_I2C2_Init(void)
{
  hi2c2.Instance = I2C2;
  hi2c2.Init.Timing = 0x00101319;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}


