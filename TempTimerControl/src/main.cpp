#include <Arduino.h>

void setup()
{
  // put your setup code here, to run once:
  // Включаем последовательный порт
  Serial.begin(115200);
  // ждем пока принициализируется USB COM порт
  while (!Serial)
    ;
  Serial.println("**************************************************************************");
  Serial.println("*  Проект запущен                                                        *");
  Serial.println("*  Версия 0.0.1                                                          *");
  Serial.println("**************************************************************************");
}

void loop()
{
  // put your main code here, to run repeatedly:
  delay(1000);
}