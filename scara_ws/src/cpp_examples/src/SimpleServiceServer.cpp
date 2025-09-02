
    #include "SimpleServiceServer.h"


    SimpleServiceServer::SimpleServiceServer()
        : rclcpp::Node("simple_service_server")
    {
        _service = create_service<scara_msgs::srv::AddTwoInts>("add_two_ints",
            [this](scara_msgs::srv::AddTwoInts::Request::SharedPtr const request,
                            scara_msgs::srv::AddTwoInts::Response::SharedPtr const response)
            {
                service_callback(request, response);
            });

        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Service callback executed");
    }

    void SimpleServiceServer::service_callback(scara_msgs::srv::AddTwoInts::Request::SharedPtr const request,
                                                scara_msgs::srv::AddTwoInts::Response::SharedPtr const response)
    {
        RCLCPP_INFO_STREAM(rclcpp::get_logger("rclcpp"),
            "New request received a: " << request->a << " b: " << request->b);
        response->sum += request->a + request->b;
        RCLCPP_INFO_STREAM(rclcpp::get_logger("rclcpp"), "Returning sum: " << response->sum);
    }


    int main(int argc, char **argv)
    {
        rclcpp::init(argc, argv);
        auto node = std::make_shared<SimpleServiceServer>();
        rclcpp::spin(node);
        rclcpp::shutdown();
        return 0;
    }