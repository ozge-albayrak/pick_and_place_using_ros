# Install script for directory: /mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gazebo_msgs/msg" TYPE FILE FILES
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/msg/ContactsState.msg"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/msg/ContactState.msg"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/msg/LinkState.msg"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/msg/LinkStates.msg"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/msg/ModelState.msg"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/msg/ModelStates.msg"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/msg/ODEJointProperties.msg"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/msg/ODEPhysics.msg"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/msg/PerformanceMetrics.msg"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/msg/SensorPerformanceMetric.msg"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/msg/WorldState.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gazebo_msgs/srv" TYPE FILE FILES
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/ApplyBodyWrench.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/DeleteModel.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/DeleteLight.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetLinkState.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetPhysicsProperties.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetJointProperties.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetModelConfiguration.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/SpawnModel.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/ApplyJointEffort.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetJointProperties.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetModelProperties.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetWorldProperties.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetLinkProperties.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetModelState.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/BodyRequest.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetLinkProperties.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetModelState.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/JointRequest.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetLinkState.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetPhysicsProperties.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetJointTrajectory.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/GetLightProperties.srv"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/srv/SetLightProperties.srv"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gazebo_msgs/cmake" TYPE FILE FILES "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/build/gazebo_ros_pkgs/gazebo_msgs/catkin_generated/installspace/gazebo_msgs-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/devel/include/gazebo_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/devel/share/roseus/ros/gazebo_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/devel/share/common-lisp/ros/gazebo_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/devel/share/gennodejs/ros/gazebo_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python3" -m compileall "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/devel/lib/python3/dist-packages/gazebo_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/devel/lib/python3/dist-packages/gazebo_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/build/gazebo_ros_pkgs/gazebo_msgs/catkin_generated/installspace/gazebo_msgs.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gazebo_msgs/cmake" TYPE FILE FILES "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/build/gazebo_ros_pkgs/gazebo_msgs/catkin_generated/installspace/gazebo_msgs-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gazebo_msgs/cmake" TYPE FILE FILES
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/build/gazebo_ros_pkgs/gazebo_msgs/catkin_generated/installspace/gazebo_msgsConfig.cmake"
    "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/build/gazebo_ros_pkgs/gazebo_msgs/catkin_generated/installspace/gazebo_msgsConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gazebo_msgs" TYPE FILE FILES "/mnt/c/Users/CUBE-AdminMobile/Documents/ros_course/master_ws/src/gazebo_ros_pkgs/gazebo_msgs/package.xml")
endif()

