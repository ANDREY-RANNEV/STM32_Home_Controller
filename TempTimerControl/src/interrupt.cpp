#include <main.h>
#include <utils.h>

void func_interrup_1() // обработчик первого прерывания
{
    bool p12 = digitalRead(PB12);
    bool p13 = digitalRead(PB13);

    if (!p13 && !p12)
        encoder2_UP();
    if (!p13 && p12)
        encoder2_DOWN();
}

void func_interrup_3() // обработчик третьего прерывания
{
    bool p12 = digitalRead(PB12);
    bool p13 = digitalRead(PB13);

    if (!p13 && !p12)
        encoder2_UP();
    if (!p13 && p12)
        encoder2_DOWN();
}

void func_interrup_2() // обработчик второго прерывания
{
    bool p10 = digitalRead(PB10);
    bool p11 = digitalRead(PB11);

    if (!p11 && p10)
        encoder1_UP();
    if (!p11 && !p10)
        encoder1_DOWN();
}

void func_interrup_4() // обработчик второго прерывания
{
    bool p10 = digitalRead(PB10);
    bool p11 = digitalRead(PB11);

    if (!p11 && p10)
        encoder1_UP();
    if (!p11 && !p10)
        encoder1_DOWN();
}
void button1()
{

}
void button2()
{
    
}