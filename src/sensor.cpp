#include "sensor.h"
#include <Arduino.h>

int s1,s2,s3,s4,s5;

void readSensors()
{
    s1 = digitalRead(PA0);
    s2 = digitalRead(PA1);
    s4 = digitalRead(PA3);
    s3 = digitalRead(PA2);
    s5 = digitalRead(PA4);
}

int getError()
{
    if(s1) return -4;
    if(s2) return -2;
    if(s3) return 0;
    if(s4) return 2;
    if(s5) return 4;

    return 0;
}