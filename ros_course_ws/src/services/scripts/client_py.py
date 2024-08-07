#!/usr/bin/env python3
import rospy
from rospy_tutorials.srv import AddTwoInts

if __name__=='__main__':
    rospy.init_node("add_two_ints_services_client")
    rospy.wait_for_service("/add_two_ints")

    try:
        add_two_ints_service = rospy.ServiceProxy("/add_two_ints", AddTwoInts)
        # This is equivalent to call the service via command line rosservice call /add_two_ints a:15, b:3

        response = add_two_ints_service(15,3)
        rospy.loginfo("The sum is: " + str(response.sum))
    except rospy.ServiceException as ex:
        rospy.logwarn("Service failed!" + str(ex))