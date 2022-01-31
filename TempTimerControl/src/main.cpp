#include <Arduino.h>

void setup()
{
  // put your setup code here, to run once:
  // Включаем последовательный порт
  Serial.begin(115200);
  // ждем пока принициализируется USB COM порт
  while (!Serial)
    ;
  Serial.println("Проект запущен");
}

void loop()
{
  // put your main code here, to run repeatedly:
}