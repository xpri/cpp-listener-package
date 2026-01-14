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
                [this](const std_msgs::msg::String::SharedPtr MessageInTopic)
                {
                    /*
                        The following lines prints "I heard x" where x is an integer.
                        msg is the pointer to the message receieved from the topic.
                        ->data references the data package under the "topic" topic. It pulls from msg.data.
                    */
                    RCLCPP_INFO_STREAM(this->get_logger(),"I heard: '{}'", MessageInTopic.data);
                }
            );
        }
    
    private:
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ListenerSubcriber>());
    rclcpp::shutdown();

    return EXIT_SUCCESS;
}