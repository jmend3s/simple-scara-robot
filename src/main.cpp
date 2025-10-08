
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
    Serial.begin(460800);
    while (!Serial) {}
}

void loop()
{
    int x = 4;
    int y = 4;

    float constexpr a2 = 5.975;
    float constexpr a4 = 4.6975;

    float const r1 = sqrt(x*x + y*y);
    Serial.print("r1 = ");
    Serial.println(r1);

    float val1 = (a4*a4 - a2*a2 - r1*r1) / (-2.0f * a2 * r1);
    if (val1 < -1.0f) val1 = -1.0f;
    if (val1 >  1.0f) val1 =  1.0f;
    float phi1 = acos(val1);
    Serial.print("phi1 = ");
    Serial.println(phi1);

    float const phi2 = atan2(y, x);
    Serial.print("phi2 = ");
    Serial.println(phi2);

    float const theta1 = phi2 - phi1;
    Serial.print("theta1 = ");
    Serial.println(theta1);

    float val2 = (r1 * r1 - a2 * a2 - a4 * a4) / (-2 * (a2 * a4));
    if (val2 < -1.0f) val2 = -1.0f;
    if (val2 >  1.0f) val2 =  1.0f;
    float const phi3 = acos(val2);
    Serial.print("phi3 = ");
    Serial.println(phi3);

    float const theta2 = M_PI - phi3;
    Serial.print("theta2 = ");
    Serial.println(theta2);

    float const pwm1 = theta1 * 180.0f / M_PI;
    float const pwm2 = theta2 * 180.0f / M_PI;

    int constexpr homePositionJoint1 = 95;
    int constexpr homePositionJoint2 = 85;

    Serial.print("pwm1 = ");
    Serial.println(pwm1);
    Serial.print("pwm2 = ");
    Serial.println(pwm2);
    Serial.println("----------------------------------------");

    joint1.write(homePositionJoint1 + static_cast<int>(pwm1 - 90));
    joint2.write(homePositionJoint2 + static_cast<int>(pwm2 - 90));

    joint3.write(60); // 82
}
