#include <Arduino.h>
#include "pid.h"
#include "sensor.h"
#include "motor.h"

int baseSpeed = 350;

void setup()
{
    pinMode(PA0,INPUT);
    pinMode(PA1,INPUT);
    pinMode(PA2,INPUT);
    pinMode(PA3,INPUT);
    pinMode(PA4,INPUT);

    pinMode(PA8,OUTPUT);
    pinMode(PA9,OUTPUT);
}

void loop()
{
    readSensors();

    int error = getError();

    float correction = calculatePID(error);

    int leftSpeed = baseSpeed + correction;
    int rightSpeed = baseSpeed - correction;

    setMotorSpeed(leftSpeed,rightSpeed);
}