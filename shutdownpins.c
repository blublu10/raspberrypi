#include<stdio>
#include<wiringPi>

#define leds 10
int pins[leds] = {0,1,2,3,4,5,6,8,9,10};

void led_off(int pin)
{
    digitalWrite(pin,LOW);

}

int main(void)
{
if(wiringPiSetup() == -1)
    {
        printf("wiringPi initialize unsuccessful \n");
        return 1;
    }

    printf("Program is starting \n");

    for(i=0;i<leds;i++)
    {
        pinMode(pins[i], OUTPUT);
    }
    int i;
    while(1)
    {
        for(i=0;i<leds;i++)
        {
            led_off(pins[i]);
        }
    }

    return 0;
}
