#include<stdio.h>
#include<wiringPi.h>
#include<softTone.h>
#include<math.h>

#define buzzerPin 0
#define buttonPin 1

void alertor(int pin)
{
    int x = 0;
    double sinVal, toneVal;
    for(x=0;x<360;x++)
    {
        sinVal = sin(x * (M_PI/180) );
        toneVal = 2000 + sinVal * 500;
        softToneWrite(pin, toneVal);
        delay(1);
    }
}

void stopAlertor(int pin)
{
    softToneWrite(pin, 0);
}

int main(void)
{
    if(wiringPiSetup() == -1)
    {
        printf("wiringPi initialization unsuccessful \n");
        return 1;
    }

    pinMode(buttonPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
    softToneCreate(buzzerPin);
    pullUpDnControl(buttonPin, PUD_UP);

    while(1)
    {
        if(digitalRead(buttonPin) == LOW) //Button is pressed
        {
            //Press buzzer
            alertor(buzzerPin);
            printf("alertor on ... \n");
        }
        else //Button is released
        {
            //Release buzzer
            stopAlertor(buzzerPin);
            printf("alertor off ... \n");
        }
    }
    return 0;
}
