#include <ros/ros.h>
#include <std_msgs/String.h>
#include <iostream>

//the code allows user to input the name of the marked location and send it to "chatter" topic

int main(int argc, char **argv)
{	
	//initialize a publisher node 
	ros::init(argc, argv, "user_input");

	//initialize nodehandle
	ros::NodeHandle n;

	//initialize a publisher
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
	ros::Rate loop_rate(10);

	//user input 
	std::string input;
	std::cout << "please enter the location name" << std::endl;
	std::cin >> input;

	//keep publishing the name to the topic 
	while(ros::ok())
	{	
		std_msgs::String msg;
		msg.data = input;
		chatter_pub.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
   	}
	return 0;

}

