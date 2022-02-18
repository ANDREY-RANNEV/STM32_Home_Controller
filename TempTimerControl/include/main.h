#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Thermistor.h>
#include <NTC_Thermistor.h>
#include <SmoothThermistor.h>
#include <PIDController.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

#define signal1 PA0 // пин на линии EXTI0
#define signal2 PA1 // пин на линии EXTI1
#define signal3 PA2 // пин на линии EXTI2

#define I2C_SDA PB7
#define I2C_SCL PB6

#define SENSOR_PIN1             PA2
#define SENSOR_PIN2             PA3
#define REFERENCE_RESISTANCE   10000
#define NOMINAL_RESISTANCE     100000
#define NOMINAL_TEMPERATURE    25
#define B_VALUE                3950
#define STM32_ANALOG_RESOLUTION 1023
#define SMOOTHING_FACTOR 9

extern byte ReciveBuffer[128];
extern volatile long counter;

extern Adafruit_SSD1306 display;

extern Thermistor* thermistor1;
extern Thermistor* thermistor2;

extern volatile double celsius1;
extern volatile double celsius2;

extern PIDController pid1;
extern PIDController pid2;

extern double pidSetTemp1;
extern double pidSetTemp2;

extern double pidCtrlTemp1;
extern double pidCtrlTemp2;

void setup();
void loop();
