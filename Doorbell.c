#include<stdio.h>
#include<wiringPi.h>

#define buzzerPin 0
#define buttonPin 1

int main(void)
{
    if(wiringPiSetup() == -1)
    {
        printf("Wiring pi initialize unsuccessful exit \n");
        return 1;
    }

    printf("Program is starting \n");

    pinMode(buzzerPin, OUTPUT);
    pinMode(buttonPin, INPUT);

    pullUpDnControl( buttonPin, PUD_UP);

    while(1)
    {
        if(digitalRead(buttonPin) == LOW) //Button is pressed so Press Buzzer
        {
            digitalWrite(buzzerPin, HIGH);
            printf("buzzer ON.....\n");
        }
        else //Button released
        {
            digitalWrite(buzzerPin, LOW);
            printf("buzzer OFF......\n");
        }
    }

    return 0;
}
