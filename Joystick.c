#include<wiringPi.h>
#include<pfc8591.h>
#include<stdio.h>
#include<softPwm.h>

#define address 0x48
#define pinbase 64
#define A0 pinbase+0
#define A1 pinbase+1
#define A2 pinbase+2
#define A3 pinbase+3
#define Z_Pin 1

int main(void)
{
    if(wiringPiSetup() == -1)
    {
        printf("WiringPi initialize failed\n");
        return 1;
    }

    int valX,valY,valZ;

    pinMode(Z_Pin,INPUT);
    pullUpDnControl(Z_Pin, PUD_UP);
    pcf8591Setup(pinbase, address);

    while(1)
    {
        valZ = digitalRead(Z_Pin);
        valY = analogRead(A0);
        valZ = analogRead(A1);
        printf("val_X : %d, /tval_Y : %d, /tval_Z : %d\n",valX,valY,valZ);
        delay(100);
    }
    return 0;
}
