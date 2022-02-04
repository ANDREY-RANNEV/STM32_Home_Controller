#include <Arduino.h>

#define LED 13
#define MOSFET1 3
#define MOSFET2 11

#define ValcoderA 7
#define ValcoderB 6

#define Button1 5
#define Button2 4
#define Button3 2

void I2CScan();
void OneSecondThread();
void pciSetup(byte pin);