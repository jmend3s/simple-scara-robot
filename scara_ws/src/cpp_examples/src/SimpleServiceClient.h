
#ifndef __SCARA_SIMPLE_SERVICE_CLIENT_H__
#define __SCARA_SIMPLE_SERVICE_CLIENT_H__

#include <scara_msgs/srv/add_two_ints.hpp>

#include <rclcpp/rclcpp.hpp>

#include <memory>


class SimpleServiceClient : public rclcpp::Node
{
public:
    SimpleServiceClient(int a, int b);

private:
    void responseCallback(rclcpp::Client<scara_msgs::srv::AddTwoInts>::SharedFuture future);

    rclcpp::Client<scara_msgs::srv::AddTwoInts>::SharedPtr _client;
};

#endif