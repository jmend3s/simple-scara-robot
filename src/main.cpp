
#include <Arduino.h>

#define SERVO1_PIN 0      // GPIO 0 on the ESP32-C3 Super Mini Pro
#define LEDC_CHANNEL_1 0   // Use LEDC Channel 0 (0-5 available on C3)

#define SERVO2_PIN 1      // GPIO 1
#define LEDC_CHANNEL_2 1

#define LEDC_TIMER 0     // Use LEDC Timer 0 (0-3 available on C3)
#define PWM_FREQ 50      // Standard servo frequency is 50 Hz
#define PWM_RESOLUTION 10 // 10 bits gives 1024 steps (0 to 1023)

int const SERVO_DUTY_MIN = 25;  // Duty for 1000us (0 degrees)
int const SERVO_DUTY_MAX = 130; // Duty for 2000us (180 degrees)

void setup()
{
    Serial.begin(460800);
    Serial.println("Starting ESP32-C3 Servo Control (LEDC)");

    ledcSetup(LEDC_CHANNEL_1, PWM_FREQ, PWM_RESOLUTION);
    ledcSetup(LEDC_CHANNEL_2, PWM_FREQ, PWM_RESOLUTION);
    ledcAttachPin(SERVO1_PIN, LEDC_CHANNEL_1);
    ledcAttachPin(SERVO2_PIN, LEDC_CHANNEL_2);
}

void setServoAngle(int channel, int angle)
{
    int duty = map(angle, 0, 180, SERVO_DUTY_MIN, SERVO_DUTY_MAX);
    ledcWrite(channel, duty);
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

    setServoAngle(LEDC_CHANNEL_1, 90 - pwm1);
    setServoAngle(LEDC_CHANNEL_2, 90 - pwm2); // 83

    delay(1000);
}
