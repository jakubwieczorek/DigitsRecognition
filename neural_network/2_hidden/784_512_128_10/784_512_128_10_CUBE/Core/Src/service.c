#include "service.h"
#include "stm32h7xx.h"

#define YELLOW GPIO_PIN_1
#define BLUE   GPIO_PIN_2
#define VIOLET GPIO_PIN_11
#define GREY   GPIO_PIN_12
#define RED    GPIO_PIN_5
#define ORANGE GPIO_PIN_14
#define GREEN  GPIO_PIN_15

#define RED_PORT GPIOF

void switch_off_all()
{
	HAL_GPIO_WritePin(GPIOB, YELLOW, GPIO_PIN_RESET); // yellow
	HAL_GPIO_WritePin(GPIOB, BLUE, GPIO_PIN_RESET); // blue
	HAL_GPIO_WritePin(GPIOB, VIOLET, GPIO_PIN_RESET); // violet
	HAL_GPIO_WritePin(GPIOB, GREY, GPIO_PIN_RESET); // grey
	HAL_GPIO_WritePin(RED_PORT, RED, GPIO_PIN_RESET); // red
	HAL_GPIO_WritePin(GPIOB, ORANGE, GPIO_PIN_RESET); // orange
	HAL_GPIO_WritePin(GPIOB, GREEN, GPIO_PIN_RESET); // green
}

void switch_0()
{
	HAL_GPIO_WritePin(GPIOB, YELLOW, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, BLUE, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOB, VIOLET, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GREY, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED_PORT, RED, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, ORANGE, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GREEN, GPIO_PIN_SET);
}

void switch_1()
{
//	HAL_GPIO_WritePin(GPIOB, YELLOW, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOB, BLUE, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOB, VIOLET, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOB, GREY, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED_PORT, RED, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOB, ORANGE, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GREEN, GPIO_PIN_SET);
}

void switch_2()
{
	HAL_GPIO_WritePin(GPIOB, YELLOW, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, BLUE, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, VIOLET, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOB, GREY, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(RED_PORT, RED, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, ORANGE, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GREEN, GPIO_PIN_SET);
}

void switch_3()
{
//	HAL_GPIO_WritePin(GPIOB, YELLOW, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, BLUE, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, VIOLET, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOB, GREY, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED_PORT, RED, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, ORANGE, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GREEN, GPIO_PIN_SET);
}

void switch_4()
{
	//	HAL_GPIO_WritePin(GPIOB, YELLOW, GPIO_PIN_SET);
	//	HAL_GPIO_WritePin(GPIOB, BLUE, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, VIOLET, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, GREY, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RED_PORT, RED, GPIO_PIN_SET);
	//	HAL_GPIO_WritePin(GPIOB, ORANGE, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, GREEN, GPIO_PIN_SET);
}

void switch_5()
{
//	HAL_GPIO_WritePin(GPIOB, YELLOW, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, BLUE, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, VIOLET, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GREY, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED_PORT, RED, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, ORANGE, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOB, GREEN, GPIO_PIN_SET);
}

void switch_6()
{
	HAL_GPIO_WritePin(GPIOB, YELLOW, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, BLUE, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, VIOLET, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GREY, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED_PORT, RED, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, ORANGE, GPIO_PIN_SET);
//	HAL_GPIO_WritePin(GPIOB, GREEN, GPIO_PIN_SET);
}

void switch_7()
{
	//	HAL_GPIO_WritePin(GPIOB, YELLOW, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, BLUE, GPIO_PIN_SET);
	//	HAL_GPIO_WritePin(GPIOB, VIOLET, GPIO_PIN_SET);
	//	HAL_GPIO_WritePin(GPIOB, GREY, GPIO_PIN_SET);
		HAL_GPIO_WritePin(RED_PORT, RED, GPIO_PIN_SET);
	//	HAL_GPIO_WritePin(GPIOB, ORANGE, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, GREEN, GPIO_PIN_SET);
}

void switch_8()
{
	HAL_GPIO_WritePin(GPIOB, YELLOW, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, BLUE, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, VIOLET, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GREY, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED_PORT, RED, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, ORANGE, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GREEN, GPIO_PIN_SET);
}

void switch_9()
{
//	HAL_GPIO_WritePin(GPIOB, YELLOW, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, BLUE, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, VIOLET, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GREY, GPIO_PIN_SET);
	HAL_GPIO_WritePin(RED_PORT, RED, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, ORANGE, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GREEN, GPIO_PIN_SET);
}

uint8_t max_idx(double y[10]) {
	uint8_t max_idx = 0;
	double max = y[0];

	for(int i = 0; i < 10; i++) {
		if(y[i] > max) {
			max = y[i];
			max_idx = i;
		}
	}

	return max_idx;
}

void display_digit(uint8_t digit) {
	switch_off_all();
	switch(digit) {
		case 0: switch_0(); break;
		case 1: switch_1(); break;
		case 2: switch_2(); break;
		case 3: switch_3(); break;
		case 4: switch_4(); break;
		case 5: switch_5(); break;
		case 6: switch_6(); break;
		case 7: switch_7(); break;
		case 8: switch_8(); break;
		case 9: switch_9(); break;
	}
}
