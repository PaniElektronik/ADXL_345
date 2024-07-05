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
#define ST7735S_CS_SOFT_Pin GPIO_PIN_4
#define ST7735S_CS_SOFT_GPIO_Port GPIOA
#define ST7735S_SCK_Pin GPIO_PIN_5
#define ST7735S_SCK_GPIO_Port GPIOA
#define ST7735S_MISO_Pin GPIO_PIN_6
#define ST7735S_MISO_GPIO_Port GPIOA
#define ST7735S_MOSI_Pin GPIO_PIN_7
#define ST7735S_MOSI_GPIO_Port GPIOA
#define ST7735S_DC_Pin GPIO_PIN_1
#define ST7735S_DC_GPIO_Port GPIOB
#define ST7735S_RST_Pin GPIO_PIN_2
#define ST7735S_RST_GPIO_Port GPIOB
#define LED_ORANGE_Pin GPIO_PIN_0
#define LED_ORANGE_GPIO_Port GPIOG
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
