#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
const double tau = 2 * M_PI;

int main(int argc, char **argv)
{
    // node definition and spinner (keeping the node alive)
    ros::init(argc, argv, "move_group_interface");
    ros::NodeHandle nh; 
    ros::AsyncSpinner spinner(1);
    spinner.start();
    sleep(2.0);
    
    // instantiate the moveit object MoveGroupInterface PlanningSceneInterface
    moveit::planning_interface::MoveGroupInterface group("arm");
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    
    //publisher
    ros::Publisher display_publisher;
    display_publisher = nh.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);
    moveit_msgs::DisplayTrajectory display_trajectory;

    // modify the object 

    //setup the target position
    group.setPoseReferenceFrame("base_link");
    // create an object of type geomerty_msgs
    geometry_msgs::Pose target_pose1;

    tf2::Quaternion orientation;
    orientation.setRPY(-3.019,0.009,-1.644);
    // convert orientation in roll, pitch and yaw in quaternion
    target_pose1.orientation = tf2::toMsg(orientation);

    // setup the target position x, y and z
    target_pose1.position.x = 0.622;
    target_pose1.position.y = 0.008;
    target_pose1.position.z = 0.430;

    group.setPoseTarget(target_pose1, "picking_point");

    // visualize the planning
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    moveit::planning_interface::MoveItErrorCode success = group.plan(my_plan);
    ROS_INFO("Visualizing plan %s", success.val ? "": "FAILED");


    // execution 
    group.move();

    ros::shutdown();
    return 0;
}