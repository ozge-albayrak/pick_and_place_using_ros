#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
    // Initialize the node and give it a name
    ros::init(argc, argv, "publisher_cpp");
    ros::NodeHandle n;

    // Create a publisher in C++ 
    ros::Publisher pub = n.advertise<std_msgs::String>("topic_cpp", 1000);
    ROS_INFO("This node is the publisher in C++");

    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        std_msgs::String msg;
        msg.data = "This is the message of type String that I am publishing!";

        // Now the message is published on the topic named "/topic_cpp"
        pub.publish(msg);
        ros::spinOnce;
        loop_rate.sleep();
    }
}