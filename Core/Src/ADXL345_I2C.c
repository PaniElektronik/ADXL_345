/**
 * @file 	ADXL345_I2C.c
 * @brief 	Communication (I2C) Handler
 *
 *
 * @author 	PaniElektronik
 * @date 	21.06.2024
 */

/*------------------------------ INCLUDES ------------------------------*/
#include "ADXL345_I2C.h"
#include "stm32f7xx_hal.h"
/*------------------------------ DECLARATIONS ------------------------------*/
I2C_HandleTypeDef hi2c1;
/*------------------------------ FUNCTIONS ------------------------------*/
/**
 * @name			MX_I2C1_Init(void)
 * @brief			I2C Communication configuration
 *
 * @param[in]		-
 * @param[in,out]	-
 * @param[out]		-
 * @return			-
 */
void MX_I2C1_Init(void)
{
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x00101319;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }

  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }

}
