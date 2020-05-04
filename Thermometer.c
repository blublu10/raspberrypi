#include<stdio.h>
#include<wiringPi.h>
#include<pcf8591.h>
#include<math.h>

#define address 0x48
#define pinbase 64
#define A0 pinbase+0
#define A1 pinbase+1
#define A2 pinbase+2
#define A3 pinbase+3

int main(void)
{
    if(!wiringPiSetup())
    {
        printf("Wiring Pi initialize failed exit\n");
        return 1;
    }
    int adcval;
    float voltage, It, Rt;
    float tempK,tempC;

    pcf8951Setup(pinbase,address);

    while(1)
    {
        adcval = analogRead(A0);
        voltage = (float)adcval /255.0*3.3;
        It = (3.3 - voltage)/10;//current across series circuit
        Rt = voltage/It; //Resitance of thermometer;
        tempK = 1/(1/(273.15 + 25) + log(Rt/10)/3950.0);
        tempC = tempK - 273.15;
        printf("ADC value : %d, \tVoltage : %.2f, \tTemperature : %.2fC\n",adcval,voltage,tempC);
        delay(100);
    }
    return 0;
}
