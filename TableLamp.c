#include<stdio.h>
#include<wiringPi.h>


#define ledPin 0
#define buttonPin 1

int ledState = LOW;
int buttonState = HIGH;
int lastbuttonState = HIGH;
int reading;
int captureTime = 50; //button state stable time
int lastChangeTime; //time when button state changed

int main(void)
{
    if(wiringPiSetup() == -1)
    {
        printf("WiringPi not successful exit");
        return 1;
    }

    printf("Program is starting \n");

    pinMode(ledPin, OUTPUT);
    pinMode(buttonPin, INPUT);

    pullUpDnControl(buttonPin, PUD_UP); //pull up to high level

    while(1)
    {
       reading = digitalRead(buttonPin);

       if(reading != lastbuttonState)
       {
           lastChangeTime = millis();
       }

       if((millis() - lastChangeTime) > captureTime) //accept this as button change and not buffeting
       {


           if(buttonState != reading)
           {

               buttonState = reading;
               if(buttonState == LOW) //button is pressed
               {
                   printf("Button is pressed /n");
                   ledState = !ledState;

                   if(ledState)
                   {
                       printf("LED on \n");
                   }
                   else
                   {
                       printf("LED off \n");
                   }
               }
               else //buttonstate is HIGH meaning button is released
               {
                   printf("Button is released /n");
               }
           }

       }

       digitalWrite(ledPin, ledState);
       lastbuttonState = reading;


    }


    return 0;

}
