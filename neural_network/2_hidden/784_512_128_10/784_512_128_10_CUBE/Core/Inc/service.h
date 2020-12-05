#ifndef SERVICE_H_
#define SERVICE_H_

#include "stm32h7xx.h"

void switch_off_all();
void switch_0();
void switch_1();
void switch_2();
void switch_3();
void switch_4();
void switch_5();
void switch_6();
void switch_7();
void switch_8();
void switch_9();
uint8_t max_idx(double y[10]);
void display_digit(uint8_t digit);

#endif
