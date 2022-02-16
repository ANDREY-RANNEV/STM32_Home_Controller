#include <main.h>
#include <utils.h>

void func_interrup_1() // обработчик первого прерывания
{
    // bool A = digitalRead(signal1);
    bool B = digitalRead(signal2);
    if (B)
    {
        counter++;
    }
    else
    {
        counter--;
    }

}

void func_interrup_2() // обработчик второго прерывания
{

    // bool A = digitalRead(signal1);
    // // bool B = digitalRead(signal2);
    // if (!A)
    // {
    //     counter--;
    //     Serial.println(counter);
    // }
}

void func_interrup_3() // обработчик третьего прерывания
{
    //   if(state3 == HIGH) state3 = LOW;
    //   else state3 = HIGH;
    //   digitalWrite(LED_BUILTIN, state3);
}

