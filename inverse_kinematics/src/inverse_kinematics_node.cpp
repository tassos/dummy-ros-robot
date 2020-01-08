#include "ros/ros.h"
#include "geometry_msgs/Pose.h"
#include "robot_msgs/joints.h"

ros::Publisher joints_command;
/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void chatterCallback(const geometry_msgs::Pose::ConstPtr& msg)
{
  robot_msgs::joints joints_msg;
  joints_msg.q1 = msg->position.x/2;
  joints_msg.q2 = msg->position.y*2;
  joints_msg.q3 = msg->position.z*4;
  joints_command.publish(joints_msg);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "inverse_kinematics");
  ros::NodeHandle n;
  joints_command = n.advertise<robot_msgs::joints>("joints_command", 1000);
  ros::Subscriber sub = n.subscribe<geometry_msgs::Pose>("ee_pose_target", 1000, chatterCallback);
  ros::spin();

  return 0;
}
