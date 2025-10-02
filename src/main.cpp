
#include <Arduino.h>
#include <ESP32Servo.h>


Servo joint1;
Servo joint2;
Servo joint3;

void setup()
{
    joint1.attach(0);
    joint2.attach(1);
    joint3.attach(10);
}

void loop()
{
    joint1.write(95);
    joint2.write(85);
    joint3.write(82);
}
