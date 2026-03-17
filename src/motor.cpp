#include <Arduino.h>
#include "motor.h"

void setMotorSpeed(int left,int right)
{
    analogWrite(PA8,left);
    analogWrite(PA9,right);
}