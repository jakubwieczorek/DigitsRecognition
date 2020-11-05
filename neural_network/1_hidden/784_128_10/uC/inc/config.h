#ifndef CONFIG_H_
#define CONFIG_H_

#include "stm32h7xx.h"

UART_HandleTypeDef uart;
DMA_HandleTypeDef dma_uart;

void gpio_config();
void nvic_config();
void dma_config();
void uart_config();

#endif
