/**
 * @file 	ADXL345_Error.c
 * @brief 	Error Handler
 *
 *
 * @author 	PaniElektronik
 * @date 	21.06.2024
 */

/*------------------------------ INCLUDES ------------------------------*/
#include "ADXL345_Error.h"

/*------------------------------ FUNCTIONS ------------------------------*/
/**
 * @name			Error_Handler(void)
 * @brief			Error Handler function (with IRQ)
 *
 * @param[in]		-
 * @param[in,out]	-
 * @param[out]		-
 * @return			-
 */
void Error_Handler(void)
{

  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }

}
