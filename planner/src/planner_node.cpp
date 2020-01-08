#include "ros/ros.h"
#include "geometry_msgs/Pose.h"

ros::Publisher ee_pose_target;
/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void chatterCallback(const geometry_msgs::Pose::ConstPtr& msg)
{
  geometry_msgs::Pose pose_msg;
  pose_msg.position.x = msg->position.x+0.1;
  pose_msg.position.y = msg->position.y-0.2;
  pose_msg.position.z = msg->position.z+0.2;
  pose_msg.orientation.x = msg->orientation.x+0.1;
  pose_msg.orientation.y = msg->orientation.y-0.2;
  pose_msg.orientation.z = msg->orientation.z+0.1;
  pose_msg.orientation.w = msg->orientation.w-0.2;
  ee_pose_target.publish(pose_msg);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "planner");
  ros::NodeHandle n;
  ee_pose_target = n.advertise<geometry_msgs::Pose>("ee_pose_target", 1000);
  ros::Subscriber sub = n.subscribe<geometry_msgs::Pose>("ee_pose", 1000, chatterCallback);
  ros::spin();

  return 0;
}
