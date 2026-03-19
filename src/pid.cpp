#include "pid.h"
#include <Arduino.h>

int sensor[5];

float Kp = 18;
float Ki = 0;
float Kd = 12;

int error = 0;
float lastError = 0;
float integral = 0;

void readSensors()
{
    sensor[1] = (digitalRead(PA0)<750)?1:0;
    sensor[2] = (digitalRead(PA1)<750)?1:0;
    sensor[3] = (digitalRead(PA3)<750)?1:0;
    sensor[4] = (digitalRead(PA2)<750)?1:0;
    sensor[5] = (digitalRead(PA4)<750)?1:0;
}



int calculatePID(error)
{   
    error = {sensor[2]*2+sensor[3]*0+sensor[4]*-2};

    integral += error;

    float derivative = error - lastError;

    float output = (Kp * error) + (Ki * integral) + (Kd * derivative);

    prevError = error;

    return output;
}