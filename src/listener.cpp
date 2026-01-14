#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class ListenerSubcriber : public rclcpp::Node
{
    public:
        ListenerSubcriber()
        : Node("listener_subscriber"), count_(0)        // Initializes count_ and sets it to a value of 0.
        {
            subscription_ = this->create_subscription<std_msgs::msg::String>
            (
                "topic",
                10,
                // LAMBDA FUNCTION STARTS HEREEEE (this is new to me so woohoo!)
                // Another helpful definition for 'this' is that it refers to the current object and can access any variable in the object.
                [this](const std_msgs::msg::String::SharedPtr MessageInTopic)
                {
                    count_++;
                    /*
                        The following lines prints "I heard x" where x is an integer.
                        msg is the pointer to the message receieved from the topic.
                        ->data references the data package under the "topic" topic. It pulls from msg.data.
                    */
                    RCLCPP_INFO(this->get_logger(),"I heard: '%s' (Total: %s times)", MessageInTopic->data.c_str(), count_);
                    // Added .c_str() modifier becuase fundamentally RCLCPP_INFO is a c based macro so it needs c based string. rip to c++ curly braces :heartbreak:
                }
            );
        }
    
    private:
        rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

        int count_ = 0; // This variable lives as long as the node does.
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ListenerSubcriber>());
    rclcpp::shutdown();

    return EXIT_SUCCESS;
}