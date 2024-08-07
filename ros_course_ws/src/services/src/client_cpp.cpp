#include <ros/ros.h>
#include <rospy_tutorials/AddTwoInts.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "add_two_ints_service_client");
    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<rospy_tutorials::AddTwoInts>("/add_two_ints");
    rospy_tutorials::AddTwoInts service;

    service.request.a = 15;
    service.request.b = 5;

    // client.call(service) --> 
    // equivalant from command line to: rosservice call /add_two_ints "a: 15 b:18"

    // response is going to update directly the object service

    if (client.call(service))
    {
        ROS_INFO("Returned sum = %d", (int)service.response.sum);
    }
    else
    {
        ROS_WARN("Service failed!");
    }
}