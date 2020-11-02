#include "config.h"

void gpio_config()
{
	GPIO_InitTypeDef gpio;

	//led
	gpio.Pin = GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_1 | GPIO_PIN_2 |
			GPIO_PIN_15;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOB, &gpio);
}
