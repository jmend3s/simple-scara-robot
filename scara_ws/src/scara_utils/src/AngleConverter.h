
#ifndef __SCARA_ANGLECONVERTER_H__
#define __SCARA_ANGLECONVERTER_H__

#include <scara_msgs/srv/euler_to_quaternion.hpp>
#include <scara_msgs/srv/quaternion_to_euler.hpp>

#include <rclcpp/rclcpp.hpp>


class AngleConverter : public rclcpp::Node
{
public:
    AngleConverter();

private:
    void eulerToQuaternionCallback(scara_msgs::srv::EulerToQuaternion::Request::SharedPtr const request,
                             scara_msgs::srv::EulerToQuaternion::Response::SharedPtr const response);

    void quaternionToEulerCallback(scara_msgs::srv::QuaternionToEuler::Request::SharedPtr const request,
                             scara_msgs::srv::QuaternionToEuler::Response::SharedPtr const response);

    rclcpp::Service<scara_msgs::srv::EulerToQuaternion>::SharedPtr _eulerToQuaternion;
    rclcpp::Service<scara_msgs::srv::QuaternionToEuler>::SharedPtr _quaternionToEuler;
};

#endif