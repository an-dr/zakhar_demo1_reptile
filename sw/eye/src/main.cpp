#include <Arduino.h>
#include <Wire.h>
#define BUILTIN_LED 13
int sensorPin = A3;  // select the input pin
int sensorValue = 0; // variable to store the value coming from the sensor


void requestEvent() {
    Serial.println("I2c request!");
    Wire.write(sensorValue);
    Wire.write(sensorValue>>8);
                                 // as expected by master
}

void setup() {

    Wire.begin(0x2b);             // join i2c bus with address #43
    Wire.onRequest(requestEvent); // register event
    pinMode(BUILTIN_LED, OUTPUT); // Initialize the BUILTIN_LED pin as an output
    pinMode(A2, OUTPUT); // Initialize the BUILTIN_LED pin as an output
    digitalWrite(A2, HIGH); // Initialize the BUILTIN_LED pin as an output
    Serial.begin(9600);
}

void loop() {
    sensorValue = analogRead(sensorPin);
    Serial.println(sensorValue, HEX); //debug
    if (sensorValue <= 120) {
        digitalWrite(BUILTIN_LED, HIGH); //led off
        delay(1000);
    }
    digitalWrite(BUILTIN_LED, LOW); //led on - default
}