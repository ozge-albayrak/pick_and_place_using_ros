execute_process(COMMAND "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/build/gazebo_ros_pkgs/gazebo_ros/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/build/gazebo_ros_pkgs/gazebo_ros/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
