
#include <Arduino.h>

#include "InverseKinematics.h"
#include "Joint.h"

uint8_t constexpr joint1Channel = 0;
uint8_t constexpr joint1Pin = 0;
Joint joint1(joint1Channel, joint1Pin);

uint8_t constexpr joint2Channel = 1;
uint8_t constexpr joint2Pin = 1;
Joint joint2(joint2Channel, joint2Pin);

uint8_t constexpr joint3Channel = 2;
uint8_t constexpr joint3Pin = 10;
Joint joint3(joint3Channel, joint3Pin);

void setup()
{
    joint1.setup();
    joint2.setup();
    joint3.setup();
}

void moveTo(float x, float y)
{
    InverseKinematics::JointAngles jointAngles = InverseKinematics::calculateJointAngles(x, y);
    joint3.setAngle(110);
    joint1.setAngle(jointAngles.theta1);
    joint2.setAngle(jointAngles.theta2);

}

void loop()
{
    moveTo(8, 0);
    delay(1000);
    // moveTo(6, 5);
    // delay(1000);
}
