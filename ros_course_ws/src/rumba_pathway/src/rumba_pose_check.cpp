#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Pose2D.h"
#include "turtlesim/Pose.h"
#include <iostream>

// Use the standard namespace
using namespace std;

// Create Pose2D object with name "current_pose"
// This object has a structure of x any y 
geometry_msgs::Pose2D current_pose;

// Create callback function to process the data coming from "turtle1/pose"
// The fuction receives a message as an input of type turtlesim::Pose
void callback_function(const turtlesim::Pose::ConstPtr &pos)
{
    // Using pointers to assign to an object of type Pose2D in x and y position of the rumba robot
    // Assign the current pose x to object "pos" which is type of turtlesim::Pose
    current_pose.x = pos->x;
    // Assign the current pose y to object "pos" which is type of turtlesim::Pose
    current_pose.y = pos->y;
    // Display on terminal the current position x and y values:
    cout << " Current x = " << current_pose.x;
    cout << " Current y = " << current_pose.y << endl;
}

// Create main fuction 
int main(int argc, char **argv)
{
    // Initialize the node and give it a name "rumba_pose"
    ros::init(argc, argv, "rumba_pose");
    // Create NodeHandle object, useful to work with different type of nodes e.g. subscriber and publisher
    ros::NodeHandle n;
    // Initialize the pose object to use it in callback function
    turtlesim::Pose pos;
    // Create subscriber object, it will subscribe to the topic "turtle1/pose" with queue size of 1000 and a callback_function to process the data 
    // The topic will be type of "pose"
    ros::Subscriber sub = n.subscribe("turtle1/pose", 1000, callback_function);

    // Spin function to keep the node alive (running continuosly)
    ros::spin();
    return 0;
}

