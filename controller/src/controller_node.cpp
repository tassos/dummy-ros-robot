#include "ros/ros.h"
#include "robot_msgs/joints.h"
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>

using namespace robot_msgs;

void chatterCallback(const robot_msgs::joints::ConstPtr& state, const robot_msgs::joints::ConstPtr& command)
{
  // Here we implement our controller and send the commands to the actual motors
  // This depends on the hardware of the robot
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "controller");
  ros::NodeHandle n;

  message_filters::Subscriber<joints> state_sub(n, "joints_state", 1);
  message_filters::Subscriber<joints> command_sub(n, "joints_command", 1);

  typedef message_filters::sync_policies::ApproximateTime<joints, joints> MySyncPolicy;
  // ApproximateTime takes a queue size as its constructor argument, hence MySyncPolicy(10)
  message_filters::Synchronizer<MySyncPolicy> sync(MySyncPolicy(10), state_sub, command_sub);
  sync.registerCallback(boost::bind(&chatterCallback, _1, _2));

  ros::spin();

  return 0;
}
