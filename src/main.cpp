#include <Arduino.h>
#include "pid.h"
#include "motor.h"

void setup()
{
    //sensor
    pinMode(PA0,INPUT);
    pinMode(PA1,INPUT); 
    pinMode(PA2,INPUT);
    pinMode(PA3,INPUT);
    pinMode(PA4,INPUT);
    //motor driver
    pinMode(PA8,OUTPUT);
    pinMode(PA9,OUTPUT);
    //
}

int base_speed = 150;

void loop()
{   
    float position = readline()
    if (position == -1){
        setMotorSpeed(0, 0);
        // motor should stop if it's off the line
    }

    float error = position - 2;  // center is 2
    float correction = calculatePID(error);

    //if correction +ve then bot is turning left  ,left motor should speed up
    int leftSpeed = base_speed+correction;
    int righSpeed = base_speed-correction;

    leftSpeed = constrain(leftSpeed, 0, 255);
    rightSpeed = constrain(rightSpeed, 0, 255);

    setMotorSpeed(leftSpeed, rightSpeed);
}