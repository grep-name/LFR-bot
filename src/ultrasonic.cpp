#include <Arduino.h>



#define TRIG_PIN PA8
#define ECHO_PIN PA9

void setup(){
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    digitalWrite(TRIG_PIN, LOW);
    Serial.begin(9600);
    delay(1000);
}

void loop(){
        // Ensure clean trigger
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    // Send 10us pulse
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Read echo duration
    duration = pulseIn(ECHO_PIN, HIGH);

    // Convert to distance (cm)
    distance_cm = duration * 0.0343 / 2;

    // Print to terminal
    Serial.print("Distance: ");
    Serial.print(distance_cm);
    Serial.println(" cm");

    delay(200);
}