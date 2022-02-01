#include <Arduino.h>

#define signal1 PA0 // пин на линии EXTI0
#define signal2 PA1 // пин на линии EXTI1
#define signal3 PA2 // пин на линии EXTI2

extern byte ReciveBuffer[128];
extern long counter;



void setup();
void loop();
void func_interrup_3();
void func_interrup_2();
void func_interrup_1();