// #include <Thermistor.h>
// #include <NTC_Thermistor.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Thread.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#define RAlogoheight 16
#define RAlogowidth 16

static const unsigned char PROGMEM RAlogo[] = {
  B00000000,
  B00111111,
  B01111000,
  B00111111,
  B01100110,
  B01011111,
  B01100110,
  B10011111,
  B01100111,
  B00001111,
  B01100111,
  B00010111,
  B01111100,
  B11100111,
  B01101100,
  B11001011,
  B01101100,
  B11010011,
  B01101100,
  B11000001,
  B01101100,
  B11000100,
  B00001111,
  B11001000,
  B00001100,
  B11010000,
  B00001100,
  B11000000,
  B00001100,
  B11000000,
  B00001100,
  B11000000,
};

#include "Utility.h"


// #define REFERENCE_RESISTANCE 100000
// #define NOMINAL_RESISTANCE 100000
// #define NOMINAL_TEMPERATURE 25
// #define B_VALUE 3950
// GyverNTC therm0(0, 10000, 3950, 25, 10000);	// пин, R термистора, B термистора, базовая температура, R резистора
// GyverNTC therm1(0, 10000, 3950, 25, 10000);
// серый 4300
// проводной 3950


int sensorValue0 = 0;
int sensorValue1 = 0;
int potensometrValue0 = 0;
char spfBuffer[125];
// Thermistor* thermistor0;
// Thermistor* thermistor1;

Thread OneSecond = Thread();

void buttonpress(){

}
void setup() {

  pinMode(LED, OUTPUT);

  pinMode(MOSFET1, OUTPUT);
  pinMode(MOSFET2, OUTPUT);

  pinMode(ValcoderA, INPUT_PULLUP);
  pinMode(ValcoderB, INPUT_PULLUP);
  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);
  pinMode(Button3, INPUT_PULLUP);


  digitalWrite(MOSFET2, HIGH);
  digitalWrite(LED, LOW);

  Wire.begin();
  Serial.begin(115200);
  while (!Serial)
    ;
  Serial.println("Start App");
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }

  display.display();
  delay(2000);  // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
  display.drawBitmap(
    (display.width() - RAlogowidth),
    0,
    RAlogo, RAlogowidth, RAlogoheight, 1);
  display.display();
  digitalWrite(LED, HIGH);

  OneSecond.onRun(OneSecondThread);
  OneSecond.setInterval(500);
}

void loop() {
  if (OneSecond.shouldRun())
    OneSecond.run();
  // sensorValue0 = thermistor0->readCelsius();
  // sensorValue1 = thermistor0->readCelsius();
  // potensometrValue0 = analogRead(A2);
  // sprintf(spfBuffer,"T0 = %04d T1= %04d P= %04d",sensorValue0,sensorValue1,potensometrValue0);
  // Serial.println(spfBuffer);
}
