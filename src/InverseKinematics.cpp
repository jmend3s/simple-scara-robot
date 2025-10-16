
#include "InverseKinematics.h"

#include <Arduino.h>
#include <cmath>


InverseKinematics::JointAngles InverseKinematics::calculateJointAngles(float const x, float const y)
{
    float const xSqr = x * x;
    float const ySqr = y * y;

    float constexpr L1 = 6.0f;
    float constexpr L2 = 4.7f;
    float constexpr L3 = 0.1f;
    float constexpr L4 = 2.8f;

    float constexpr L1Sqr = L1 * L1;
    float constexpr L2Sqr = L2 * L2;

    float cos_beta = (L1Sqr + L2Sqr - xSqr - ySqr) / (2 * L1 * L2);
    float const beta = acos(cos_beta);
    float cos_alpha = (xSqr + ySqr + L1Sqr - L2Sqr) / (2 * L1 * sqrt(xSqr + ySqr));
    float const alpha = acos(cos_alpha);
    float const phi = atan2(y, x);

    Serial.print("cos_beta = "); Serial.println(cos_beta);
    Serial.print("cos_alpha = "); Serial.println(cos_alpha);

    float const endEffectorAngle = atan2(L4, L2 + L3);

    float const theta1 = phi - alpha;
    float theta2 = M_PI - beta;
    theta2 = theta2 - endEffectorAngle;

    int const pwm1 = constrain(round(theta1 / M_PI * 180.0), -90, 90);
    int const pwm2 = constrain(round(theta2 / M_PI * 180.0), -90, 90);

    int constexpr realAngleOffset = 90;
    int const servo1 = realAngleOffset - pwm1;
    int const servo2 = realAngleOffset + pwm2;

    return { servo1, servo2 };
}
