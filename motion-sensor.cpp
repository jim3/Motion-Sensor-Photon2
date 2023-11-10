// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
// HC-SR501 PIR motion sensor
// =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#include "Particle.h"
SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);

// particle serial monitor --follow
SerialLogHandler logHandler(LOG_LEVEL_INFO);

int sensorPinInput = D0;
int led = D7;
int reading = 0;

void setup() {
    pinMode(sensorPinInput, INPUT);
    pinMode(led, OUTPUT);
}

void loop() {
    reading = digitalRead(sensorPinInput);

    // If the value is HIGH, then motion was detected
    if (reading == HIGH) {
        digitalWrite(led, HIGH);
        Particle.publish("motion-detected");
    } else {
        digitalWrite(led, LOW);
        Serial.println("Motion not detected!");
    }
    delay(5000);
}
