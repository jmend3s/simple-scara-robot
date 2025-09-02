
#ifndef __SCARA_SIMPLE_SERVICE_SERVER_H__
#define __SCARA_SIMPLE_SERVICE_SERVER_H__

#include <scara_msgs/srv/add_two_ints.hpp>
#include <rclcpp/rclcpp.hpp>
#include <memory>


class SimpleServiceServer : public rclcpp::Node
{
public:
    SimpleServiceServer();

private:
    void service_callback(scara_msgs::srv::AddTwoInts::Request::SharedPtr const request,
                             scara_msgs::srv::AddTwoInts::Response::SharedPtr const response);

    rclcpp::Service<scara_msgs::srv::AddTwoInts>::SharedPtr _service;
};

#endif