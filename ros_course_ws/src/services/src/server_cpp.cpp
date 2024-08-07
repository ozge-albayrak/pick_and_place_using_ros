#include <ros/ros.h>
#include <rospy_tutorials/AddTwoInts.h>

bool handle_callback(rospy_tutorials::AddTwoInts::Request &req, rospy_tutorials::AddTwoInts::Response &res)
{
    int result_sum = req.a + req.b;
    ROS_INFO("%d + %d = %d", (int)req.a, (int)req.b, (int)result_sum);
    res.sum = result_sum;
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "add_two_ints_service_server");
    ros::NodeHandle nh;

    ros::ServiceServer server = nh.advertiseService("/add_two_ints", handle_callback);
    ros::spin();

}