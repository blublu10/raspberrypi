#include<wiringPi.h>
#include<stdio.h>


#define ledPin 0

int main()
{
    if(wiringPiSetup() == -1) //when initializing wiring failed
    {
        printf("setup WiringPi failed");
        return 1;
    }

    //when intialing wiring successfully print message
    printf("wiringPi initialize successfully GPIO %d (wiring pin) \n", ledPin);

    pinMode(ledPin, OUTPUT);

    while(1)
    {
        digitalWrite(ledPin, HIGH); //led on
        printf("My led is shining bright...\n");
        delay(1000);
        digitalWrite(ledPin, LOW); //led off
        printf("My led is dark as night...\n");
        delay(1000);

    }

    return 0;

}
