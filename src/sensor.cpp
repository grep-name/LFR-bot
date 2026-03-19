
#include "motor.h"
#include "pid.h"
#include "ir_sensor.h"
#define S1 D3
#define S2 D4
#define S3 D5
#define S4 D6
#define S5 D7

void sensorInit() {
    pinMode(S1, INPUT);
    pinMode(S2, INPUT);
    pinMode(S3, INPUT);
    pinMode(S4, INPUT);
    pinMode(S5, INPUT);
}

float readLine() {
    int s1 = digitalRead(S1);
    int s2 = digitalRead(S2);
    int s3 = digitalRead(S3);
    int s4 = digitalRead(S4);
    int s5 = digitalRead(S5);

    int position = (s1 * 0 + s2 * 1 + s3 * 2 + s4 * 3 + s5 * 4);
    int sum = s1 + s2 + s3 + s4 + s5;

    if (sum == 0) return -1;

    return (float)position / sum;
}