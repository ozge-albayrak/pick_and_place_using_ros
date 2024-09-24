// add the object to the scene --> DONE
// use tf fuction to get the position and orientation of the EEF w.r.t. base link from picking and placing --> DONE
// test motion planning
// add the closure of the gripper and the opening

#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
const double tau = 2 * M_PI;

void close_gripper(moveit::planning_interface::MoveGroupInterface& move_gripper)
{
    move_gripper.setJointValueTarget("finger_right_joint", 0.05);
    move_gripper.move();
}

void open_gripper(moveit::planning_interface::MoveGroupInterface& move_gripper)
{
    move_gripper.setJointValueTarget("finger_right_joint", 0.0);
    move_gripper.move();
}

void pick(moveit::planning_interface::MoveGroupInterface& move_group)
{
    //setup the target position
    move_group.setPoseReferenceFrame("base_link");
    // create an object of type geomerty_msgs
    geometry_msgs::Pose target_pick;

    tf2::Quaternion orientation;
    orientation.setRPY(-tau/4 ,0 , -tau/2);
    // convert orientation in roll, pitch and yaw in quaternion
    target_pick.orientation = tf2::toMsg(orientation);
    // setup the target position x, y and z
    target_pick.position.x = 0.651;
    target_pick.position.y = -0.025;
    target_pick.position.z = 0.319;

    move_group.setPoseTarget(target_pick, "picking_point");

    move_group.move();
}

void place(moveit::planning_interface::MoveGroupInterface& move_group_place)
{
    //setup the target position
    move_group_place.setPoseReferenceFrame("base_link");
    // create an object of type geomerty_msgs
    geometry_msgs::Pose target_place;

    tf2::Quaternion orientation;
    orientation.setRPY(-tau/4 ,0 , 0);
    // convert orientation in roll, pitch and yaw in quaternion
    target_place.orientation = tf2::toMsg(orientation);
    // setup the target position x, y and z
    target_place.position.x = 0;
    target_place.position.y = 0.8;
    target_place.position.z = 0.5;

    move_group_place.setPoseTarget(target_place, "picking_point");

    move_group_place.move();
    
}


void addCollisionObject(moveit::planning_interface::PlanningSceneInterface& planning_scene_interface)
{
    // collision object
    std::vector<moveit_msgs::CollisionObject> collision_objects;
    // creating n number of objects in the scene
    collision_objects.resize(3);

    // add the first conveyour 
    collision_objects[0].id = "table1";
    collision_objects[0].header.frame_id = "world";

    // Define primitive dimension, position of the TABLE 1
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

    // Define primitive dimension, position of the TABLE 2
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

    // Define primitive dimension, position of the BASE
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

    // add the red cube to grab
    // collision_objects[3].id = "object";
    // collision_objects[3].header.frame_id = "world";

    // // Define primitive dimension, position of the object 
    // collision_objects[3].primitives.resize(1);
    // collision_objects[3].primitives[0].type = collision_objects[3].primitives[0].BOX;
    // collision_objects[3].primitives[0].dimensions.resize(3);
    // collision_objects[3].primitives[0].dimensions[0] = 0.02;
    // collision_objects[3].primitives[0].dimensions[1] = 0.02;
    // collision_objects[3].primitives[0].dimensions[2] = 0.2;
    
    // // pose of the object
    // collision_objects[3].primitive_poses.resize(1);
    // collision_objects[3].primitive_poses[0].position.x = 0.642;
    // collision_objects[3].primitive_poses[0].position.y = -0.031;
    // collision_objects[3].primitive_poses[0].position.z = 1.1;
    // collision_objects[3].primitive_poses[0].orientation.w = 1.0;
    // // Add the object to the scene
    // collision_objects[3].operation = collision_objects[3].ADD;

    // add the object to the scene
    planning_scene_interface.applyCollisionObjects(collision_objects);

}

int main(int argc, char **argv)
{

    ros::init(argc, argv, "cobot_pick_and_place");
    ros::NodeHandle nh;
    ros::AsyncSpinner spinner(1);
    spinner.start();

    ros::WallDuration(1.0).sleep();
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    moveit::planning_interface::MoveGroupInterface group("arm");
    moveit::planning_interface::MoveGroupInterface gripper("gripper");
    group.setPlanningTime(45.0);

    addCollisionObject(planning_scene_interface);
    ros::WallDuration(1.0).sleep();

    pick(group);
    ros::WallDuration(1.0).sleep();
    close_gripper(gripper);
    ros::WallDuration(1.0).sleep();
    place(group);
    ros::WallDuration(1.0).sleep();
    open_gripper(gripper);

    ros::waitForShutdown();
    return 0;


    // // node definition and spinner (keeping the node alive)
    // ros::init(argc, argv, "move_group_interface");
    // ros::NodeHandle nh; 
    // ros::AsyncSpinner spinner(1);
    // spinner.start();
    // sleep(2.0);
    
    // // instantiate the moveit object MoveGroupInterface PlanningSceneInterface
    // moveit::planning_interface::MoveGroupInterface group("arm");
    // moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    
    // //publisher
    // ros::Publisher display_publisher;
    // display_publisher = nh.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);
    // moveit_msgs::DisplayTrajectory display_trajectory;


    // // visualize the planning
    // moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    // moveit::planning_interface::MoveItErrorCode success = group.plan(my_plan);
    // ROS_INFO("Visualizing plan %s", success.val ? "": "FAILED");


    // // execution 
    // group.move();

    // ros::shutdown();
    // return 0;
}