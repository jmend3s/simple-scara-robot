
#include <Arduino.h>

#include "InverseKinematics.h"
#include "Joint.h"

uint8_t constexpr joint1Channel = 0;
uint8_t constexpr joint1Pin = 0;
Joint joint1(joint1Channel, joint1Pin);

uint8_t constexpr joint2Channel = 1;
uint8_t constexpr joint2Pin = 1;
Joint joint2(joint2Channel, joint2Pin);

void setup()
{
    joint1.setup();
    joint2.setup();
}

void loop()
{
    InverseKinematics::JointAngles const jointAngles = InverseKinematics::calculateJointAngles(3.0f, 5.0f);

    joint1.setAngle(jointAngles.theta1);
    joint2.setAngle(jointAngles.theta2);

    delay(1000);
}
