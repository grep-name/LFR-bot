#include <Arduino.h>
#include "pid.h"
#include "motor.h"
#include "ir_sensor.h"

int base_speed = 150;

void setup()
{
    motorInit();
    sensorInit();
}

void loop()
{   
    float position = readLine();

    // If line is lost → stop
    if (position == -1) {
        setMotorSpeed(0, 0);
        return;
    }

    // Center = 2 (for 5 sensors: 0–4)
    float error = position - 2.0;

    float correction = computePID(error);

    int leftSpeed  = base_speed + correction;
    int rightSpeed = base_speed - correction;

    // Limit PWM range
    leftSpeed  = constrain(leftSpeed, -255, 255);
    rightSpeed = constrain(rightSpeed, -255, 255);

    setMotorSpeed(leftSpeed, rightSpeed);
}