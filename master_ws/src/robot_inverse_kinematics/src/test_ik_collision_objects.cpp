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
    moveit::planning_interface::MoveGroupInterface group("manipulator");
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

    // tf2::Quaternion orientation;
    // orientation.setRPY(-3.019,0.009,-1.644);
    // // convert orientation in roll, pitch and yaw in quaternion
    // target_pose1.orientation = tf2::toMsg(orientation);

    // // setup the target position x, y and z
    // target_pose1.position.x = 0.622;
    // target_pose1.position.y = 0.008;
    // target_pose1.position.z = 0.430;

    tf2::Quaternion orientation;
    orientation.setRPY(0,0,0);
    // convert orientation in roll, pitch and yaw in quaternion
    target_pose1.orientation = tf2::toMsg(orientation);

    // setup the target position x, y and z
    target_pose1.position.x = 0.5;
    target_pose1.position.y = 0.5;
    target_pose1.position.z = 0.5;

    group.setPoseTarget(target_pose1, "tool0");

    // collision object
    std::vector<moveit_msgs::CollisionObject> collision_objects;
    // resizing the base object under the robot arm
    collision_objects.resize(4);

    // add the first conveyour 
    collision_objects[0].id = "table1";
    collision_objects[0].header.frame_id = "world";

    // Define primitive dimension, position of the table 1
    collision_objects[0].primitives.resize(1);
    collision_objects[0].primitives[0].type = collision_objects[0].primitives[0].BOX;
    collision_objects[0].primitives[0].dimensions.resize(3);
    // resizing the shape in [W], [L], [H] in meters
    collision_objects[0].primitives[0].dimensions[0] = 0.608;
    collision_objects[0].primitives[0].dimensions[1] = 2;
    collision_objects[0].primitives[0].dimensions[2] = 1;
    // give the pose of table 1
    collision_objects[0].primitive_poses.resize(1);
    collision_objects[0].primitive_poses[0].position.x = 0.75;
    collision_objects[0].primitive_poses[0].position.y = 0;
    collision_objects[0].primitive_poses[0].position.z = 0.5;
    collision_objects[0].primitive_poses[0].orientation.w = 1.0;
    // add the table 1 to the scene
    collision_objects[0].operation = collision_objects[0].ADD;

    // Add the second table
    collision_objects[1].id = "table2";
    collision_objects[1].header.frame_id = "world";

    // Define primitive dimension, position of the table 2
    collision_objects[1].primitives.resize(1);
    collision_objects[1].primitives[0].type = collision_objects[1].primitives[0].BOX;
    collision_objects[1].primitives[0].dimensions.resize(3);
    // resizing the shape in [W], [L], [H] in meters
    collision_objects[1].primitives[0].dimensions[0] = 1.3;
    collision_objects[1].primitives[0].dimensions[1] = 0.8;
    collision_objects[1].primitives[0].dimensions[2] = 1;
    // give the pose of table 2
    collision_objects[1].primitive_poses.resize(1);
    collision_objects[1].primitive_poses[0].position.x = 0;
    collision_objects[1].primitive_poses[0].position.y = 1;
    collision_objects[1].primitive_poses[0].position.z = 0.5;
    collision_objects[1].primitive_poses[0].orientation.w = 1.0;
    // add the table 2 to the scene
    collision_objects[1].operation = collision_objects[1].ADD;

    // add the base
    collision_objects[2].id = "base";
    collision_objects[2].header.frame_id = "world";

    // Define primitive dimension, position of the base
    collision_objects[2].primitives.resize(1);
    collision_objects[2].primitives[0].type = collision_objects[2].primitives[0].CYLINDER;
    collision_objects[2].primitives[0].dimensions.resize(2);
    collision_objects[2].primitives[0].dimensions[0] = 0.8;
    collision_objects[2].primitives[0].dimensions[1] = 0.2;
    
    // pose of robot arm base
    collision_objects[2].primitive_poses.resize(1);
    collision_objects[2].primitive_poses[0].position.x = 0;
    collision_objects[2].primitive_poses[0].position.y = 0;
    collision_objects[2].primitive_poses[0].position.z = 0.4;
    collision_objects[2].primitive_poses[0].orientation.w = 1.0;
    // Add the base to the scene
    collision_objects[2].operation = collision_objects[2].ADD;

    // Add the grabbing object 
    collision_objects[3].id = "object";
    collision_objects[3].header.frame_id = "world";

    // Define primitive dimension, position of the object
    collision_objects[3].primitives.resize(1);
    collision_objects[3].primitives[0].type = collision_objects[3].primitives[0].BOX;
    collision_objects[3].primitives[0].dimensions.resize(3);
    collision_objects[3].primitives[0].dimensions[0] = 0.02;
    collision_objects[3].primitives[0].dimensions[1] = 0.02;
    collision_objects[3].primitives[0].dimensions[2] = 0.2;
    
    // pose the object
    collision_objects[3].primitive_poses.resize(1);
    collision_objects[3].primitive_poses[0].position.x = 0.642;
    collision_objects[3].primitive_poses[0].position.y = -0.031;
    collision_objects[3].primitive_poses[0].position.z = 1.1;
    collision_objects[3].primitive_poses[0].orientation.w = 1.0;

    // Add the object to the scene
    collision_objects[3].operation = collision_objects[3].ADD;

    // add the objects to the scene
    planning_scene_interface.applyCollisionObjects(collision_objects);


    // visualize the planning
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    moveit::planning_interface::MoveItErrorCode success = group.plan(my_plan);
    ROS_INFO("Visualizing plan %s", success.val ? "": "FAILED");


    // execution 
    group.move();

    ros::shutdown();
    return 0;
}