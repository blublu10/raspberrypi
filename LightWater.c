#include<stdio.h>
#include<wiringPi.h>

#define leds 10

int pins[leds] = {0,1,2,3,4,5,6,8,9,10};

void led_on(int pin)
{
    digitalWrite(pin,LOW);

}

void led_off(int pin)
{
    digitalWrite(pin,HIGH);

}

int main(void)
{

    if(wiringPiSetup() == -1)
    {
        printf("wiringPi initialize unsuccessful \n");
        return 1;
    }

    printf("Program is starting \n");

    int i;

    for(i=0;i<leds;i++)
    {
        pinMode(pins[i], OUTPUT);
    }

    while(1)
    {
        for(i=0;i<leds;i++)
        {
            led_on(pins[i]);
            delay(100);
            led_off(pins[i]);
        }

        for(i= (leds - 1);i>=0;i--)
        {
            led_on(pins[i]);
            delay(100);
            led_off(pins[i]);
        }
    }

    return 0;
}


