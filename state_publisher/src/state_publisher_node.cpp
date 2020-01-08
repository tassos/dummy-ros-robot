#include "ros/ros.h"
#include "robot_msgs/joints.h"
#include "sstream"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "state_publisher");
  ros::NodeHandle n;
  ros::Publisher state_pub = n.advertise<robot_msgs::joints>("joints_state", 1000);

  ros::Rate loop_rate(10);

  int count = 0;
  while (ros::ok())
  {
    robot_msgs::joints msg;

    msg.q1.data = cos(count);
    msg.q2.data = sin(count);
    msg.q3.data = 0.5*cos(count*2);
    msg.q4.data = 0.5*cos(count/2);

    state_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }
  return 0;
}
