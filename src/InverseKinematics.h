
#ifndef __INVERSE_KINEMATICS_H__
#define __INVERSE_KINEMATICS_H__


class InverseKinematics
{
public:
    struct JointAngles { int theta1; int theta2; };
    static JointAngles calculateJointAngles(float x, float y);
};

#endif
