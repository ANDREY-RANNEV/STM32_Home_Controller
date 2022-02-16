#include <main.h>
#include <utils.h>
#include <interrupt.h>

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

byte ReciveBuffer[128];
long counter = 0;

void setup()
{
  // put your setup code here, to run once:
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

  // pinMode(signal1, INPUT_PULLDOWN);
  // pinMode(signal2, INPUT_PULLDOWN);
  // // pinMode(signal3, INPUT_PULLDOWN);

  // pinMode(LED_BUILTIN, OUTPUT);                      // PC13
  // attachInterrupt(signal1, func_interrup_1, RISING); // инициализация первого прерывания
  // attachInterrupt(signal2, func_interrup_2, FALLING); // инициализация второго прерывания
  // attachInterrupt(signal3, func_interrup_3, CHANGE);  // инициализация третьего прерывания

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

  display.clearDisplay();
  display.setTextSize(1);              // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);             // Start at top-left corner
  display.println(F("Hello, world!"));
  display.display();
}

void loop()
{
  // put your main code here, to run repeatedly:
  delay(1000);
  // Serial.println(counter);
}