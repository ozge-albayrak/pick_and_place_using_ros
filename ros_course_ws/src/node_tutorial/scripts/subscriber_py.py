#!/usr/bin/env python3
import rospy
from std_msgs.msg import String

def Callback_py(msg):
    rospy.loginfo("This is what I hear: ")
    rospy.loginfo(msg.data)

if __name__=='__main__':
    # Initialize the node and give it a name
    rospy.init_node("subscriber_py")

    sub = rospy.Subscriber("topic_py", String, Callback_py)
    rospy.spin()