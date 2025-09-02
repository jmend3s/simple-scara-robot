
#ifndef __SCARA_SIMPLES_ERVICE_SERVER_H__
#define __SCARA_SIMPLES_ERVICE_SERVER_H__

// #include <scara_msgs/srv/AddTwoInts.srv>
#include <rclcpp/rclcpp.hpp>
#include <memory>


class SimpleServiceServer : public rclcpp::Node
{
public:
    SimpleServiceServer() : rclcpp::Node("simple_service_server") {};

private:
    // rclcpp::Service<>::SharedPtr _service;
};

#endif