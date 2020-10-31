#include "config.h"

void gpio_config()
{
	GPIO_InitTypeDef gpio;

	//led
	gpio.Pin = GPIO_PIN_14 | GPIO_PIN_1;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOB, &gpio);
}
