#include "pid.h"

float Kp = 25.0;
float Ki = 0.0;
float Kd = 15.0;

float lastError = 0;
float integral = 0;

float computePID(float error)
{
    integral += error;
    float derivative = error - lastError;

    float output = (Kp * error) + (Ki * integral) + (Kd * derivative);

    lastError = error;

    return output;
}