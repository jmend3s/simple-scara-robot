
#include <Arduino.h>
#include <ESP32Servo.h>


Servo servo1;

void setup()
{
    servo1.attach(1);
}


void loop() {
    servo1.write(80);    // 0 degrees
    delay(500);
    servo1.write(90);   // middle
    delay(500);
    servo1.write(100);  // max
    delay(500);
}
