#include "config.h"

extern UART_HandleTypeDef uart;
extern DMA_HandleTypeDef dma_uart;

void gpio_config()
{
	GPIO_InitTypeDef gpio;

	// led
	gpio.Pin = GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_15;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOB, &gpio);

	// uart rx
	gpio.Pin = GPIO_PIN_9 | GPIO_PIN_9;
	gpio.Mode = GPIO_MODE_AF_PP;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_LOW;
	gpio.Alternate = GPIO_AF7_USART3;
	HAL_GPIO_Init(GPIOD, &gpio);

}

void uart_config()
{
	uart.Instance = USART3;
	uart.Init.BaudRate = 115200;
	uart.Init.WordLength = UART_WORDLENGTH_8B;
	uart.Init.StopBits = UART_STOPBITS_1;
	uart.Init.Parity = UART_PARITY_NONE;
	uart.Init.Mode = UART_MODE_RX;
	uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart.Init.OverSampling = UART_OVERSAMPLING_16;

	HAL_UART_Init(&uart);

//	uart.Instance = USART3;
//	uart.Init.BaudRate = 115200;
//	uart.Init.WordLength = UART_WORDLENGTH_8B;
//	uart.Init.StopBits = UART_STOPBITS_1;
//	uart.Init.Parity = UART_PARITY_NONE;
//	uart.Init.Mode = UART_MODE_TX_RX;
//	uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
//	uart.Init.OverSampling = UART_OVERSAMPLING_16;
//	uart.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
//	uart.Init.Prescaler = UART_PRESCALER_DIV1;
//	uart.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
//
//	if (HAL_UART_Init(&uart) != HAL_OK) {
//		Error_Handler();
//	}
//	if (HAL_UARTEx_SetTxFifoThreshold(&uart, UART_TXFIFO_THRESHOLD_1_8) != HAL_OK) {
//		Error_Handler();
//	}
//	if (HAL_UARTEx_SetRxFifoThreshold(&uart, UART_RXFIFO_THRESHOLD_1_8) != HAL_OK) {
//		Error_Handler();
//	}
//	if (HAL_UARTEx_DisableFifoMode(&uart) != HAL_OK) {
//		Error_Handler();
//	}
}

void dma_config()
{
	dma_uart.Instance = DMA1_Stream0;
	dma_uart.Init.Request = DMA_REQUEST_USART3_RX;
	dma_uart.Init.Direction = DMA_PERIPH_TO_MEMORY;
	dma_uart.Init.PeriphInc = DMA_PINC_DISABLE;
	dma_uart.Init.MemInc = DMA_MINC_ENABLE;
	dma_uart.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
	dma_uart.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
	dma_uart.Init.Mode = DMA_NORMAL;
	dma_uart.Init.Priority = DMA_PRIORITY_LOW;
	dma_uart.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
	HAL_DMA_Init(&dma_uart);
	__HAL_LINKDMA(&uart, hdmatx, dma_uart);
}

void nvic_config()
{
//	HAL_NVIC_SetPriority(DMA1_Stream0_IRQn, 0, 0);
//	HAL_NVIC_EnableIRQ(DMA1_Stream0_IRQn);

	HAL_NVIC_SetPriority(USART3_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(USART3_IRQn);
}
