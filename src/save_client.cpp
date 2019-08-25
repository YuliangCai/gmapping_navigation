#include <ros/ros.h>
#include <gmapping_navigation/mark_location.h>
#include <iostream>
#include <std_msgs/String.h>

//the code is to create a subscriber/sericeclient to save the input location and data

//define a serviceclient pointer to use in the callback 
ros::ServiceClient *clientPtr;

//subscriber callback 
void callback(const std_msgs::String::ConstPtr& msg)
{
	//create a service message object 
	gmapping_navigation::mark_location srv;

	//send the user input to message
	srv.request.location = msg->data.c_str();

	//put the service client in main here
	ros::ServiceClient client = (ros::ServiceClient)*clientPtr;

	//run the client and check status
	if(client.call(srv))
	{
		ROS_INFO("success");
		ros::shutdown();
	}
	else
	{
		ROS_ERROR("Failed");
		ros::shutdown();
	}

}

int main(int argc, char **argv)
{
	//initialize a subscriber node and nodehandle
	ros::init(argc, argv, "location_client");
	ros::NodeHandle n;

	//create a serviceclient
	ros::ServiceClient save_location = n.serviceClient<gmapping_navigation::mark_location>("/save_location");

	//copy the address of service client to global variable
	clientPtr = & save_location;

	//create a subscriber to get the user input
	ros::Subscriber sub = n.subscribe<std_msgs::String>("/chatter", 1000, callback);

	ros::spin();

	return 0;


}


