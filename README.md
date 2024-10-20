# Learning ROS for Robotics Programming 

## Overview
This project is focused on learning and implementing various concepts in Robot Operating System (ROS). Through this project, I explored the creation and configuration of custom robots, along with performing a pick-and-place task using the MoveIt plugin.

## Features
- Installed ROS Noetic and learning creating packages
- Created a custom robot model
- Implemented a pick-and-place task
- Configured a Universal Robot
- Attached an end effector to the robot
- Learned how to put Robotiq Finger Gripper on UR5
- How to simulate UR5 in Gazebo and code Inverse Kinematics 
- Developed collision-free path planning using MoveIt

## Getting Started

### Prerequisites
Before you begin, ensure you have met the following requirements:
- ROS installed (specify the version, e.g., ROS Noetic)
- Ubuntu (specify the version, e.g., Ubuntu 20.04)
- MoveIt installed

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/ozge-albayrak/ros_course.git

2. Navigate to the project directory:
    ```bash
    cd master_ws

3. Build the package
    ```bash 
    catkin_make

4. Source the workspace:
    ```bash
    source devel/setup.bash

### Usage
To launch the simulation of the custom robot and perform the pick-and-place task, run:

1. Run the launch file:
    ```bash
    roslaunch custom_robot_moveit_config demo.launch

2. Run the pick-and-place node:
    ```bash
    rosrun robot_inverse_kinematics pick_and_place_class

### Acknowledgments
- Thanks to the ROS community for the resources and documentation.
- Special mention to the developers of MoveIt for their powerful toolset.