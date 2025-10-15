
#ifndef __JOINT_H__
#define __JOINT_H__

#include <cstdint>


class Joint
{
public:
    Joint(uint8_t channel, uint8_t pin);

    void setup() const;
    void setAngle(int angle) const;

private:
    uint8_t _channel;
    uint8_t _pin;
};

#endif