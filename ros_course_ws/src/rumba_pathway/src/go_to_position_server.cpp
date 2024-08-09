#include <ros/ros.h>
#include <rumba_msg/TargetPosition.h>
#include <geometry_msgs/Pose2D.h>
#include <turtlesim/Pose.h>
#include <iostream>
#include <math.h>

class PositionServer
{
    public:
    PositionServer()
    {
        // Class constructor
        sub_pose_ = n_.subscribe("/turtle1/pose", 1000, &PositionServer::sub_callback, this);
        server = n_.advertiseService("/go_to_position", &PositionServer::server_callback, this);

    }

    // Create callback function of the subscriber
    void sub_callback(const turtlesim::Pose::ConstPtr &pos)
    {
        current_pose.x = pos->x;
        current_pose.y = pos->y;
        current_pose.theta = pos->theta;
    }

    // Create server callback function that receives a service request and responses
    bool server_callback(rumba_msg::TargetPosition::Request &req, rumba_msg::TargetPosition::Response &res)
    {
        // Calculate the steering angle that the turtle needs to get to reach the goal position
        float theta = atan2(current_pose.y - req.target_y, current_pose.x - req.target_x);
        // Associate the angle to response
        res.angular_z = theta;
        ROS_INFO("Service is working!");
        // Print the calculated angle value 
        std::cout << " Target theta = " << res.angular_z << std::endl;
        res.linear_x = -1.0;
        res.feedback = true;
        res.message = "Service is called successfully.";
        return true;

    }
    private:
    ros::NodeHandle n_;
    ros::Subscriber sub_pose_;
    ros::ServiceServer server;
    geometry_msgs::Pose2D current_pose;
    turtlesim::Pose pose;
    rumba_msg::TargetPosition target_position;


};

// Create the main fuction 
int main(int argc, char **argv)
{
    ros::init(argc, argv, "position_server");
    PositionServer Server;
    ros::spin();
    return 0;
}