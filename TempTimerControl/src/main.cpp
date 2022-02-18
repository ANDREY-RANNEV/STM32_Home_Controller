#include <main.h>
#include <utils.h>
#include <interrupt.h>

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

byte ReciveBuffer[128];
volatile long counter = 0;
volatile int stp = 0;
volatile bool dirstp = false;
volatile double celsius1;
volatile double celsius2;

Thermistor *thermistor1;
Thermistor *thermistor2;

PIDController pid1;
PIDController pid2;

double pidSetTemp1 = 15;
double pidSetTemp2 = 15;

double pidCtrlTemp1;
double pidCtrlTemp2;

void setup()
{
  pinMode(PC13, OUTPUT);
  pinMode(PA8, OUTPUT);
  pinMode(PA9, OUTPUT);
  pinMode(PA10, OUTPUT);

  pinMode(PB10, INPUT);
  pinMode(PB11, INPUT);
  pinMode(PB12, INPUT);
  pinMode(PB13, INPUT);
  pinMode(PB14, INPUT);
  pinMode(PB15, INPUT);

  digitalWrite(PC13, HIGH);

  digitalWrite(PA8, LOW);
  digitalWrite(PA9, LOW);
  digitalWrite(PA10, LOW);
  // Включаем последовательный порт
  Serial.begin(115200);
  // ждем 5 sec или пока принициализируется USB COM порт
  counter = 0;
  while (!Serial)
  {
    delay(100);
    counter++;
    if (counter == 50)
      break;
  };

  attachInterrupt(PB13, func_interrup_1, CHANGE); // инициализация первого прерывания
  attachInterrupt(PB11, func_interrup_2, CHANGE); // инициализация второго прерывания
  attachInterrupt(PB13, func_interrup_3, CHANGE); // инициализация третьего прерывания
  attachInterrupt(PB11, func_interrup_4, CHANGE); // инициализация второго прерывания
  attachInterrupt(PB14, button1, RISING);         // инициализация второго прерывания
  attachInterrupt(PB15, button2, RISING);         // инициализация второго прерывания

  Serial.println("**************************************************************************");
  Serial.println("*  Проект запущен                                                        *");
  Serial.println("*  Версия 0.0.1                                                          *");
  Serial.println("**************************************************************************");

  // Wire.begin();
  // I2C_Test();

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }

  display.display();
  delay(2000); // Pause for 2 seconds

  // display.clearDisplay();
  // display.setTextSize(1);              // Normal 1:1 pixel scale
  // display.setTextColor(SSD1306_WHITE); // Draw white text
  // display.setCursor(0, 0);             // Start at top-left corner
  // display.println(F("Hello, world!"));
  // display.display();

  thermistor1 = new SmoothThermistor(new NTC_Thermistor(
                                         SENSOR_PIN1,
                                         REFERENCE_RESISTANCE,
                                         NOMINAL_RESISTANCE,
                                         NOMINAL_TEMPERATURE,
                                         B_VALUE,
                                         STM32_ANALOG_RESOLUTION),
                                     SMOOTHING_FACTOR);
  thermistor2 = new SmoothThermistor(new NTC_Thermistor(
                                         SENSOR_PIN2,
                                         REFERENCE_RESISTANCE,
                                         NOMINAL_RESISTANCE,
                                         NOMINAL_TEMPERATURE,
                                         B_VALUE,
                                         STM32_ANALOG_RESOLUTION),
                                     SMOOTHING_FACTOR);

  pid1.begin();
  pid2.begin();
  pid1.setpoint(pidSetTemp1);
  pid2.setpoint(pidSetTemp2);
  pid1.tune(2, 10, 1); // Tune the PID, arguments: kP, kI, kD
  pid1.limit(0.0, 255.0); // Limit the PID output between 0 and 255, this is important to get rid of integral windup!
  pid2.tune(2, 10, 1); // Tune the PID, arguments: kP, kI, kD
  pid2.limit(0.0, 255.0); // Limit the PID output between 0 and 255, this is important to get rid of integral windup!
}

void loop()
{
  delay(500);

  celsius1 = thermistor1->readCelsius();
  celsius2 = thermistor2->readCelsius();

  pidCtrlTemp1 = pid1.compute(celsius1);
  pidCtrlTemp2 = pid2.compute(celsius2);

  analogWrite(PA8, pidCtrlTemp1);
  analogWrite(PA9, pidCtrlTemp2);

  display.clearDisplay();
  // display.setTextSize(3);              // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(20, 0);             // Start at top-left corner
  // display.println(counter);

  display.setTextSize(1);

  display.print(celsius1);
  display.print(" ");
  display.print(pidSetTemp1);display.println("");
  display.print(celsius2);
  display.print(" ");
  display.print(pidSetTemp2);display.println("");
  display.setTextSize(2);
  display.print(pidCtrlTemp1);
  display.print(" ");
  display.print(pidCtrlTemp2);

  display.display();

}