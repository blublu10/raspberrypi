#include<stdio.h>
#include<wiringPi.h>

#define ledPinRed 0
#define ledPinGreen 1
#define ledPinBlue 2

void ledInit(void)
{
    softPwmCreate(ledPinRed, 0, 100);
    softPwmCreate(ledPinGreen, 0, 100);
    softPwmCreate(ledPinBlue, 0, 100);
}

void ledColorSet(int r, int g, int b)
{
    softPwmWrite( ledPinRed, r);
    softPwmWrite( ledPinGreen, g);
    softPwmWrite( ledPinBlue, b);

}


int main(void)
{
    if(wiringPiSetup() == -1)
    {
        printf("wiringPi initialize unsuccessful exit \n");
        return 1;
    }

    printf("Program is starting \n");
    int r,g,b;

    ledInit();

    while(1)
    {
        r = random() % 100;
        g = random() % 100;
        b = random() % 100;

        ledColorSet(r,g,b);

        printf("r = %d, g = %d, b = %d /n",r,g,b);
        delay(300);
    }

    return 0;
}
