
#include "AngleConverter.h"

#include "tf2/utils.h"

AngleConverter::AngleConverter()
    : rclcpp::Node("angles_conversion_service")
{
    _eulerToQuaternion = create_service<scara_msgs::srv::EulerToQuaternion>("euler_to_quaternion",
        [this](scara_msgs::srv::EulerToQuaternion::Request::SharedPtr const request,
                        scara_msgs::srv::EulerToQuaternion::Response::SharedPtr const response)
        {
            eulerToQuaternionCallback(request, response);
        });

    _quaternionToEuler = create_service<scara_msgs::srv::QuaternionToEuler>("quaternion_to_euler",
    [this](scara_msgs::srv::QuaternionToEuler::Request::SharedPtr const request,
                    scara_msgs::srv::QuaternionToEuler::Response::SharedPtr const response)
    {
        quaternionToEulerCallback(request, response);
    });

    RCLCPP_INFO(rclcpp::get_logger("simple_service_server"), "Angle conversion services are ready");
}

void AngleConverter::eulerToQuaternionCallback(scara_msgs::srv::EulerToQuaternion::Request::SharedPtr const request,
                                            scara_msgs::srv::EulerToQuaternion::Response::SharedPtr const response)
{
    RCLCPP_INFO_STREAM(rclcpp::get_logger("angle_converter"),
        "New request to convert euler angles roll: " << request->roll <<
        " pitch: " << request->pitch <<
        " yaw: " << request->yaw << " into quaternion");

    tf2::Quaternion quaternion;
    quaternion.setRPY(request->roll, request->pitch, request->yaw);
    response->x = quaternion.getX();
    response->y = quaternion.getY();
    response->z = quaternion.getZ();
    response->w = quaternion.getW();

    RCLCPP_INFO_STREAM(rclcpp::get_logger("angle_converter"),
        "Corresponding quaternion x: " << response->x <<
        " y: " << response->y <<
        " z: " << response->z <<
        " w: " << response->w);
}

void AngleConverter::quaternionToEulerCallback(scara_msgs::srv::QuaternionToEuler::Request::SharedPtr const request,
                                                scara_msgs::srv::QuaternionToEuler::Response::SharedPtr const response)
{
    RCLCPP_INFO_STREAM(rclcpp::get_logger("angle_converter"),
        "New request to convert quaternion x: " << request->x <<
        " y: " << request->y <<
        " z: " << request->z <<
        " w: " << request->w);

    tf2::Quaternion quaternion(request->x, request->y, request->z, request->w);
    tf2::Matrix3x3 rotationMatrix(quaternion);
    rotationMatrix.getRPY(response->roll, response->pitch, response->yaw);

    RCLCPP_INFO_STREAM(rclcpp::get_logger("angle_converter"),
        "Corresponding euler angles roll: " << response->roll <<
        " pitch: " << response->pitch <<
        " yaw: " << response->yaw);
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AngleConverter>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
