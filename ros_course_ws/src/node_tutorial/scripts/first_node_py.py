#!/usr/bin/env python3
import rospy

if __name__=='__main__':
    # Initialize the node and give it a name
    rospy.init_node("node_python")

    rospy.loginfo("Hello, this is the first node in Python")

    rospy.sleep(3)

    rate = rospy.Rate(10)

    while not rospy.is_shutdown():
        rospy.loginfo("This is a node running in Python")
        rate.sleep()

    rospy.loginfo("Finished executing the node, exiting now!")