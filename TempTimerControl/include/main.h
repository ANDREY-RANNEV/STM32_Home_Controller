#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

#define signal1 PA0 // пин на линии EXTI0
#define signal2 PA1 // пин на линии EXTI1
#define signal3 PA2 // пин на линии EXTI2

#define I2C_SDA PB7
#define I2C_SCL PB6

extern byte ReciveBuffer[128];
extern long counter;

extern Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup();
void loop();
void func_interrup_3();
void func_interrup_2();
void func_interrup_1();
void I2C_Test();