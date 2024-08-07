#!/usr/bin/env python3
import rospy
from std_msgs.msg import String

if __name__=='__main__':
    # Initialize the node and give it a name
    rospy.init_node("publisher_py")

    pub = rospy.Publisher("topic_py", String, queue_size=1000)

    rospy.loginfo("The publisher node in Python has started.")

    rate = rospy.Rate(10)

    while not rospy.is_shutdown():
        msg = String()
        msg.data = "This is the message of type String that I am publishing!"
        pub.publish(msg)
        rate.sleep()