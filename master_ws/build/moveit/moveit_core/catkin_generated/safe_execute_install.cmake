execute_process(COMMAND "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/build/moveit/moveit_core/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/build/moveit/moveit_core/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
