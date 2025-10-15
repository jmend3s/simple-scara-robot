
#include "Joint.h"

#include <Arduino.h>


Joint::Joint(uint8_t const channel, uint8_t const pin)
    : _channel(channel)
    , _pin(pin)
{
}

void Joint::setup() const
{
    uint32_t constexpr pwmFrequency = 50;
    uint8_t constexpr pwmResolution = 10;

    ledcSetup(_channel, pwmFrequency, pwmResolution);
    ledcAttachPin(_pin, _channel);
}

void Joint::setAngle(int const angle) const
{
    int constexpr dutyMinimum = 25;
    int constexpr dutyMaximum = 130;

    int const duty = map(angle, 0, 180, dutyMinimum, dutyMaximum);
    ledcWrite(_channel, duty);
}
