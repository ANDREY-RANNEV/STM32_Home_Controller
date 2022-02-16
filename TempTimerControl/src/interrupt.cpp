#include <main.h>
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

void I2C_Test()
{
    byte error, address;
    int nDevices;

    Serial.println("Scanning...");

    nDevices = 0;
    for (address = 8; address < 127; address++)
    {
        Wire.beginTransmission(address);
        error = Wire.endTransmission();

        if (error == 0)
        {
            Serial.print("I2C device found at address 0x");
            if (address < 16)
                Serial.print("0");
            Serial.print(address, HEX);
            Serial.println(" !");

            nDevices++;
        }
        else if (error == 4)
        {
            Serial.print("Unknow error at address 0x");
            if (address < 16)
                Serial.print("0");
            Serial.println(address, HEX);
        }
    }
    if (nDevices == 0)
        Serial.println("No I2C devices found\n");
    else
    {
        Serial.print("done\nwasfound ");
        Serial.print(nDevices);
        Serial.print(" devices\n");
    }
}