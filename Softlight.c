#include<stdio.h>
#include<wiringPi.h>
#include<pcf8591.h>
#include<softPwm.h>

#define address 0x48
#define pinbase 64
#define A0 pinbase + 0
#define A1 pinbase + 1
#define A2 pinbase + 2
#define A3 pinbase + 3

#define ledPin 0

int main(void)
{
    if(wiringPiSetup() == -1)
    {
        printf("wiringPi initialization unsuccessful \n");
        return 1;
    }

    pin8591Setup(pinbase, address);
    softPwmCreate(ledPin,0,100);

    int value;
    float voltage;

    while(1)
    {
        value = analogRead(A0); //read A0 pin
        softPwmWrite(ledPin, value * 100/255); //convert to duty cycle
        voltage = (float)value /255.0 * 3.3; //calculate voltage
        printf("ADC value : %d, \tVoltage : %.2f \n",value,voltage);
        delay(100);
    }

    return 0;
}

