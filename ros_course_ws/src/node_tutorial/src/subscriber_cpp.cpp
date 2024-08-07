#include "ros/ros.h"
#include "std_msgs/String.h"

void Callback_function(const std_msgs::String& msg)
{
    ROS_INFO("I heard this: %s", msg.data.c_str());
}

int main(int argc, char **argv)

{
    // Initialize the node and give it a name
    ros::init(argc, argv, "subscriber_cpp");
    ros::NodeHandle n;

    // Create a subscriber in C++ 
    ros::Subscriber sub = n.subscribe("topic_cpp", 1000, Callback_function);
    ros::spin();
    return 0;

}