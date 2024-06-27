/**
 * @file 	GPIOConfig.h
 * @brief 	General Purpose Input/Output Configuration header.
 *
 *
 * @author 	PaniElektronik
 * @date 	21.06.2024
 */

/*------------------------------ INCLUDES ------------------------------*/
#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_gpio.h"
/*------------------------------ DEFINES ------------------------------*/
#define LED_RED_Pin GPIO_PIN_14
#define LED_RED_GPIO_Port GPIOB
#define LED_BLUE_Pin GPIO_PIN_7
#define LED_BLUE_GPIO_Port GPIOB
/*------------------------------ DECLARATIONS ------------------------------*/
extern void Error_Handler(void);
void MX_GPIO_Init(void);
/*------------------------------ OTHERS ------------------------------*/
#ifndef INC_GPIOCONFIG_H_
#define INC_GPIOCONFIG_H_
#endif /* INC_GPIOCONFIG_H_ */
