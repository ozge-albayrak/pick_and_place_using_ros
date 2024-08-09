#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Pose2D.h"
#include "turtlesim/Pose.h"
#include "turtlesim/TeleportAbsolute.h"
#include "std_srvs/Empty.h"
#include "rumba_msg/TargetPosition.h"
#include <iostream>

// The Class named "RumbaController"
class RumbaController
{
// Public section of this class, that are accessable from everywhere
public:
    // Create Class constructor
    RumbaController()
    {
        // Creating a publisher that will publish a message type of geomerty_msgs/Twist on the topic named /turtle1/cmd_vel and the queue size of 1000
        // This is the publisher object that we'll use in callback function of the subscriber
        pub_cmd_vel_ = n_.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
        // Create subscriber object that subscribes to the topic "/turtle1/pose" 
        // The subscriber elaborates the data that it gets as an output in the callback_fuction
        sub_pose_ = n_.subscribe("/turtle1/pose", 1000, &RumbaController::callback, this);
        // Create a client that asks a request to type of turtlesim::TeleportAbsolute 
        // Name of this service is "/turtle1/teleport_absolute"
        client_pose_ = n_.serviceClient<turtlesim::TeleportAbsolute>("/turtle1/teleport_absolute");
        // Create another client to clear the path and type of the service is std_srvs::Empty
        // Name of the service is "/clear"
        client_clear_ = n_.serviceClient<std_srvs::Empty>("/clear");
        // Create a service client that is asking a request to service of type TargetPosition
        client_target_pose = n_.serviceClient<rumba_msg::TargetPosition>("/go_to_position");

    }
    // Create a function for distance calculation between two points in 2D 
    double getDistance()
    {
        return sqrt(pow(target_position.request.target_x - current_pose.x, 2) + pow(target_position.request.target_y - current_pose.y, 2));
    }

    double distance = getDistance();

    // Create callback function (a method of Class "RumbaController")
    // as an imput the callback function gets "turtlesim::Pose" message
    void callback(const turtlesim::Pose::ConstPtr &pos)
    {
        // Using pointers to assign to an object of type Pose2D in x and y position of the rumba robot
        // Assign the current pose x to object "pos" which is type of turtlesim::Pose
        current_pose.x = pos->x;
        // Assign the current pose y to object "pos" which is type of turtlesim::Pose
        current_pose.y = pos->y;
        current_pose.theta = pos->theta;

        // Rise a request to teleport the turtle in x, y and theta (x=1, y=1, zero orientation)
        teleport_pose.request.x = 1.0;
        teleport_pose.request.y = 1.0;
        teleport_pose.request.theta = 0.0;

        // Set the request of the service by giving target position in x, y and orientation theta
        target_position.request.target_x = 3.0;
        target_position.request.target_y = 3.0;
        target_position.request.target_theta = 0.0;

        // If the client rises the request, the turtle should do:
        if (client_target_pose.call(target_position))
        {
            // Print the response of the service 
            ROS_INFO("Service is called.");
            std::cout<< target_position.response.message << std::endl;

            // Set the threshold
            // float threshold = 0.05;
            float threshold;
            // use the fuction getParam(), name of the parameter "/threshold_parameter", associated with parameter called "threshold"
            n_.getParam("/threshold_parameter", threshold);


            // Calculate the difference value between the current theta angle and angle theta value that the server has calculated
            float diff = current_pose.theta - target_position.response.angular_z;
            // Calculate the difference between current theta angle and target angle 
            float diff_theta = current_pose.theta - target_position.request.target_theta;
            std::cout << " diff theta = " << diff << std::endl;
            // Create an object to calculate the distance between the current position and the target position in x and y direction
            double distance = getDistance();

            // Rotate until the turtle is reached the target theta value
            if (std::abs(diff) > threshold)
            {
                //Spin at the angular speed of 1 counter clockwise
                cmd.linear.x = 0.0;
                cmd.angular.z = 1.0;

                // need a condition for stopping the turtle when reaching the target theta
                if (std::abs(diff_theta) < threshold and distance < threshold)
                {
                    cmd.linear.x = 0.0;
                    cmd.angular.z = 0.0;
                    ROS_INFO("Target position reached!");
                    client_clear_.call(clear_pathway);
                }
            }
            // Condition if the difference is less than the threshold then stop spinning and move straight
            else if (std::abs(diff) < threshold)
            {
                cmd.linear.x = target_position.response.linear_x;
                cmd.angular.z = 0.0;

            }
        }


        if (current_pose.x > 10.0)
        {
            // Ask the robot to turn left
            cmd.linear.x = 0.8;
            cmd.angular.z = 1.2;
        }
        else if (current_pose.x < 1.0)
        {
            // Ask the robot to turn right
            cmd.linear.x = 0.8;
            cmd.angular.z = -1.2; 
        }
        // If the turtle reaches the top edge of the environment
        else if (current_pose.y > 10.0)
        {
            // call the service teleport_pose that contains the request to teleport the turtle in x, y and theta
            client_pose_.call(teleport_pose);
            // call the service clear_pathway to clear the map 
            client_clear_.call(clear_pathway);
        }
        else 
        {
            // Ask the robot to go straight
            cmd.linear.x = 3.5;
            cmd.angular.z = 0.0;

        }

        // Publish on topic /turtle1/cmd_vel of type geometry_msgs::Twist
        pub_cmd_vel_.publish(cmd);
    }
// Private section of this class 
private:
    // Create NodeHandle object
    ros::NodeHandle n_;
    // Create publisher object that we will put inside the Constructor -> it will publish a message of geometry_msgs/Twist on the topic /turtle1/pose
    ros::Publisher pub_cmd_vel_;
    // Create subscriber to subscribe the topic /turtle1/pose
    ros::Subscriber sub_pose_;
    // Create Geometry message Pose object 
    geometry_msgs::Pose2D current_pose;
    // Create Geometry message Twist object
    geometry_msgs::Twist cmd;
    // Create a client that asks to teleport the turtle to certain position
    ros::ServiceClient client_pose_;
    // Create a client that asks to clean the turtle's pathway 
    ros::ServiceClient client_clear_;
    // Create a turtlesim::TeleportAbsolute object
    turtlesim::TeleportAbsolute teleport_pose;
    // Create a standard services (std_srvs) empty object
    std_srvs::Empty clear_pathway;
    // create a client object that rise a request to go_to_position service that is of type /TargetPosition
    ros::ServiceClient client_target_pose;
    // Initialize the service object 
    rumba_msg::TargetPosition target_position;

};

// Create the main fuction 
int main (int argc, char **argv)
{
    // Initialize the node and give it a name e.g."pathway"
    ros::init(argc, argv, "pathway");
    // Callinng the Class "RumbaController"
    RumbaController Controller;
    // Keep the node running by using "spin" function
    ros::spin();
    return 0;
}