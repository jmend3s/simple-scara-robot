#include <Arduino.h>
#include <ESP32Servo.h>

Servo myservo;  // create servo object to control a servo
// a maximum of eight servo objects can be created

int pos = 0;    // variable to store the servo position

void setup()
{
    myservo.attach(1);  // attaches the servo on pin 20
}


void loop()
{
    myservo.write(90);              // tell servo to go to position in variable 'pos'

}