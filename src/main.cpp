
#include <Arduino.h>

#include "Joint.h"

uint8_t constexpr joint1Channel = 0;
uint8_t constexpr joint1Pin = 0;
Joint joint1(joint1Channel, joint1Pin);

uint8_t constexpr joint2Channel = 1;
uint8_t constexpr joint2Pin = 1;
Joint joint2(joint2Channel, joint2Pin);

void setup()
{
    Serial.begin(460800);

    joint1.setup();
    joint2.setup();
}

void loop()
{
    float x = 3.0f;
    float y = 5.0f;

    float xSqr = x * x;
    float ySqr = y * y;

    float L1 = 6.0f;
    float L2 = 4.7f;
    float L3 = 0.1f;
    float L4 = 2.8f;

    float L1Sqr = L1 * L1;
    float L2Sqr = L2 * L2;

    float preBeta = (L1Sqr + L2Sqr - xSqr - ySqr) / (2 * L1 * L2);
    float beta = acos(preBeta);
    float preAlpha = (xSqr + ySqr + L1Sqr - L2Sqr) / (2 * L1 * sqrt(xSqr + ySqr));
    float alpha = acos(preAlpha);
    float phi = atan2(y, x);

    float endEffectorAngle = atan2(L4, L2 + L3);

    float theta1 = phi - alpha;
    float theta2 = M_PI - beta;
    theta2 = theta2 - endEffectorAngle;

    int pwm1 = constrain(round(theta1 / M_PI * 180.0), 0, 180);
    int pwm2 = constrain(round(theta2 / M_PI * 180.0), 0, 180);

    joint1.setAngle(90 - pwm1);
    joint2.setAngle(90 - pwm2); // 83

    delay(1000);
}
