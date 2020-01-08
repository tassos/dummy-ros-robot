#include "ros/ros.h"
#include "geometry_msgs/Pose.h"
#include "robot_msgs/joints.h"

ros::Publisher ee_pose;
/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void chatterCallback(const robot_msgs::joints::ConstPtr& msg)
{
  geometry_msgs::Pose pose_msg;
  ee_pose.publish(pose_msg);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "direct_geometric_model");
  ros::NodeHandle n;
  ee_pose = n.advertise<geometry_msgs::Pose>("ee_pose", 1000);
  ros::Subscriber sub = n.subscribe("joints_state", 1000, chatterCallback);
  ros::spin();

  return 0;
}
