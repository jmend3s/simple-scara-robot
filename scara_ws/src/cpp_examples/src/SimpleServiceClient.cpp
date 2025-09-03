
#include "SimpleServiceClient.h"

#include <chrono>


SimpleServiceClient::SimpleServiceClient(int a, int b)
    : Node("simple_client")
{
    _client = create_client<scara_msgs::srv::AddTwoInts>("add_two_ints");
    auto const request = scara_msgs::srv::AddTwoInts::Request::SharedPtr();
    request->a = a;
    request->b = b;

    while (!_client->wait_for_service(std::chrono::seconds(1)))
    {
        RCLCPP_ERROR(rclcpp::get_logger("simple_service_client"), "Waiting for service...");
        if (!rclcpp::ok())
        {
            RCLCPP_ERROR(rclcpp::get_logger("simple_service_client"), "Interrupted while waiting for service");
            return ;
        }
    }
    auto result = _client->async_send_request(request,
        [this](rclcpp::Client<scara_msgs::srv::AddTwoInts>::SharedFuture const future)
        {
            responseCallback(future);
        });
}

void SimpleServiceClient::responseCallback(rclcpp::Client<scara_msgs::srv::AddTwoInts>::SharedFuture future)
{
    if (future.valid())
    {
        RCLCPP_INFO_STREAM(rclcpp::get_logger("simple_client"), "Service response " << future.get()->sum);
    }
    else
    {
        RCLCPP_ERROR(rclcpp::get_logger("simple_client"), "Service response failed");
    }
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    if (argc != 3)
    {
        RCLCPP_ERROR(rclcpp::get_logger("simple_client"), "Wrong number of arguments, use simple_server_client A B");
        return -1;
    }
    auto node = std::make_shared<SimpleServiceClient>(atoi(argv[1]), atoi(argv[2]));
    rclcpp::shutdown();
}
