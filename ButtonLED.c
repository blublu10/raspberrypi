#include<stdio.h>
#include<wiringPi.h>


#define ButtonPin 1 //define Button pin
#define ledPin 0   //define LED pin

int main(void)
{
    if(wiringPiSetup() == -1) //wiringPi initialize failed
    {
        printf("WiringPi Initialize failed /n");
        return 1;
    }

    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);

    pullUpDnControl( buttonPin, PUD_UP); //pull up to high level

    while(1)
    {
        if(digitalRead(buttonPin) == LOW) //button is pressed down turn on the LED
        {
            digitalWrite(ledPin, HIGH);
            printf("Button Pressed down turn ON LED /n");
        }
        else //button released turn off LED
        {
            digitalWrite(ledPin, LOW);
            printf("Button Released turn Off LED /n");
        }
    }
    return 0;
}
