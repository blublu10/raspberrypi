#include<stdio.h>
#include<wiringPi.h>

#define address 0x48  //pcf8591 default address (I2C address)
#define pinbase 64    //any number above 64
#define A0 pinbase + 0
#define A1 pinbase + 1
#define A2 pinbase + 2
#define A3 pinbase + 3

int main(void)
{
    if(wiringPiSetup() == -1)
    {
        printf("WringPi initialization unsuccessful /n");
        return 1;
    }

    pcf8591Setup(pinbase, address);

    float voltage;
    int value;

    while(1)
    {
        value = analogRead(A0); //read A0 pin
        analogWrite(pinbase+0,value);
        voltage = (float)value / 255.0 * 3.3; //calculate voltage
        printf("ADC value : %d, \tVoltage : %.2fV \n",value,voltage);
        delay(100);
    }

    return 0;


}
