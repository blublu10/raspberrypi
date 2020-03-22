#include<stdio.h>
#include<wiringPi.h>

#define ledPin 1

int main(void)
{
    if(wiringPiSetup() == -1)
    {
        printf("wiringPi initialize unsuccessful exit \n");
        return 1;
    }

    printf("Program is starting \n");

    int i;

    pinMode(ledPin, PWM_OUTPUT);

    while(1)
    {
        for( i = 0;i < 1024; i++)
        {
            pwmWrite(ledPin, i);
            delay(2);
        }

        delay(300);


        for( i = 1023;i >= 0 ; i--)
        {
            pwmWrite(ledPin, i);
            delay(2);
        }

        delay(300);

    }

    return 0;


}
