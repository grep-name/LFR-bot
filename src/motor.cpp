#include <Arduino.h>
#include "motor.h"

// Left motor pins
#define L_IN1 PA8
#define L_IN2 PA9

// Right motor pins
#define R_IN1 PB0
#define R_IN2 PB1

void setMotorSpeed(int left, int right)
{
    // LEFT MOTOR
    if (left >= 0) {
        digitalWrite(L_IN1, HIGH);
        digitalWrite(L_IN2, LOW);
        analogWrite(L_IN1, left);
    } else {
        digitalWrite(L_IN1, LOW);
        digitalWrite(L_IN2, HIGH);
        analogWrite(L_IN2, -left);
    }

    // RIGHT MOTOR
    if (right >= 0) {
        digitalWrite(R_IN1, HIGH);
        digitalWrite(R_IN2, LOW);
        analogWrite(R_IN1, right);
    } else {
        digitalWrite(R_IN1, LOW);
        digitalWrite(R_IN2, HIGH);
        analogWrite(R_IN2, -right);
    }
}