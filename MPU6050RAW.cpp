#include<stdio.h>
#include<stdint.h>
#include<unistd.h>
#include "I2Cdev.h"
#include "MPU6050.h"

MPU6050 accelgyro; //instantiate MPU6050 class object

int16_t ax, ay, az;
int16_t gx,  gy, gz;

void setup()
{
    //initialize device
    printf("Initializing I2 devices \n");
    accelgyro.initialize();

    //verify connection
    printf("Testing device connection \n");

    printf(accelgyro.testconnection() ? "MPU6050 connection successful \n" : "MPU6050 connection failed \n");
}

void loop()
{
    //read raw accel/gyro measurements from device
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    printf("a/g: %6hd %6hd %6hd    %6hd %6hd %6hd\n",ax,ay,az,gx,gy,gz);
    printf("a/g: %.2f g %.2f g %.2f g     %.2f d.s %.2f d/s %.2f d/s\n",(float)ax/16384,(float)ay/16384,(float)az/16384,(float)gx/131,(float)gy/131,(float)gz/131);
}

int main()
{
    setup();
    while(1)
    {
        loop();
    }
    return 0;
}
