#include <ros/ros.h>

#include <std_msgs/String.h>

#include <sstream>

int main(int argc, char **argv)

{

  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>(
      "info", 1000); // Topic info avec une messagerie de type std_msgs::String

  ros::Rate loop_rate(0.5); // période de publication = 1/0.5 (2 sec)

  int count = 0;

  while (ros::ok())

  {

    std_msgs::String msg;

    std::stringstream ss;

    ss << "hello world " << count;

    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();

    ++count;
  }
  return 0;
}