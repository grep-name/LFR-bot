#include "pid.h"

float Kp = 18;
float Ki = 0;
float Kd = 12;

float prevError = 0;
float integral = 0;

float calculatePID(float error)
{
    integral += error;

    float derivative = error - prevError;

    float output = (Kp * error) + (Ki * integral) + (Kd * derivative);

    prevError = error;

    return output;
}