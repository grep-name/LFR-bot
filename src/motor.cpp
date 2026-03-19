#include "motor.h"

// LEFT MOTOR
#define ENA D9
#define IN1 D10
#define IN2 D11

// RIGHT MOTOR
#define ENB D8
#define IN3 D12
#define IN4 D13

void motorInit() {
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}

void setMotor(int pwm, int in1, int in2, int speed) {
    if (speed >= 0) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
    } else {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        speed = -speed;
    }

    speed = constrain(speed, 0, 255);
    analogWrite(pwm, speed);
}

void setMotorSpeed(int left, int right) {
    setMotor(ENA, IN1, IN2, left);
    setMotor(ENB, IN3, IN4, right);
}