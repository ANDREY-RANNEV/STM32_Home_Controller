#include <main.h>
#include <utils.h>
#include <interrupt.h>

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

byte ReciveBuffer[128];
volatile long counter = 0;
volatile int stp = 0;
volatile bool dirstp = false;
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
}

void loop()
{
  delay(100);

  display.clearDisplay();
  display.setTextSize(3);              // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(30, 30);           // Start at top-left corner
  display.println(counter);
  display.display();
}