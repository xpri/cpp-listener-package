#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class ListenerSubcriber : public rclcpp::Node
{
    public:
        ListenerSubcriber()
        : Node("listener_subscriber")
        {
            subscription_ = this->create_subscription<std_msgs::msg::String>
            (
                "topic",
                10,
                // LAMBDA FUNCTION STARTS HEREEEE (this is new to me so woohoo!)
                [this](const std_msgs::msg::String::SharedPtr msg)
                {
                    
                }
            )
        }
}