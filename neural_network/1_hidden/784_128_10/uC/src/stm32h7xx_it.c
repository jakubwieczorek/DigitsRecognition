#include "stm32h7xx_hal.h"
#include "stm32h7xx.h"
#ifdef USE_RTOS_SYSTICK
#include <cmsis_os.h>
#endif
#include "stm32h7xx_it.h"

extern UART_HandleTypeDef uart;
extern DMA_HandleTypeDef dma_uart;

void SysTick_Handler(void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
#ifdef USE_RTOS_SYSTICK
	osSystickHandler();
#endif
}

void DMA1_Stream0_IRQHandler(void)
{
  HAL_DMA_IRQHandler(&dma_uart);
}

void USART3_IRQHandler(void)
{
	HAL_UART_IRQHandler(&uart);
}
