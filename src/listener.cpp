#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class ListenerSubcriber : public rclcpp::Node
{
    public:
        ListenerSubcriber()
        : Node("listener_subscriber")
        {

        }
}