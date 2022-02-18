#include <main.h>
#include <interrupt.h>

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

void encoder2_UP()
{
    pidSetTemp2+=1;
    pid2.setpoint(pidSetTemp2);
}

void encoder2_DOWN()
{
    pidSetTemp2-=1;
    pid2.setpoint(pidSetTemp2);
}

void encoder1_UP()
{
    pidSetTemp1+=1;
    pid1.setpoint(pidSetTemp1);
}

void encoder1_DOWN()
{
    pidSetTemp1-=1;
    pid1.setpoint(pidSetTemp1);
}