#include "ros/ros.h"

int main(int argc, char **argv)

{
    // Initialize the node and give it a name
    ros::init(argc, argv, "node_cpp");
    ros::NodeHandle n; 

    ROS_INFO("Hello, this is the first node in cpp");

    ros::Duration(3.0).sleep();

    ros::Rate loop_rate(10);

    while (ros::ok())
    {
        ROS_INFO("This is a node running in C++");
        ros::spinOnce();
        loop_rate.sleep();
    }

    ROS_INFO("Finished to execute the node, exiting now!");
}