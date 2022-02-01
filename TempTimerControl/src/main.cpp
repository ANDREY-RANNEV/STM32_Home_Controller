#include <main.h>
byte ReciveBuffer[128];
long counter = 0;

void setup()
{
  // put your setup code here, to run once:
  // Включаем последовательный порт
  Serial.begin(115200);
  // ждем пока принициализируется USB COM порт
  while (!Serial)
    ;

  pinMode(signal1, INPUT_PULLDOWN);
  pinMode(signal2, INPUT_PULLDOWN);
  // pinMode(signal3, INPUT_PULLDOWN);

  pinMode(LED_BUILTIN, OUTPUT);                      // PC13
  attachInterrupt(signal1, func_interrup_1, RISING); // инициализация первого прерывания
  // attachInterrupt(signal2, func_interrup_2, FALLING); // инициализация второго прерывания
  // attachInterrupt(signal3, func_interrup_3, CHANGE);  // инициализация третьего прерывания

  Serial.println("**************************************************************************");
  Serial.println("*  Проект запущен                                                        *");
  Serial.println("*  Версия 0.0.1                                                          *");
  Serial.println("**************************************************************************");
}

void loop()
{
  // put your main code here, to run repeatedly:
  delay(1000);
  Serial.println(counter);
}