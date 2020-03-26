#include "ros/ros.h"
#include "ros_fibo/service.h"
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

bool service_callback (ros_fibo::service::Request &req, ros_fibo::service::Response &res) {
	int index = req.index;
	int length = req.length;
	int vec[2];
	vec[0]=0;
	vec[1]=1;
	int sum = 0; 
	if(length<=0 || index <0) {
		cout<<"Couldn't answer to request, please control that 			all the values are correct!";
	}
	else {
		for (int i=0; i<(index+length-1); i++) {
			
			if(i>=index-1) {
				char info[50];
				sprintf(info,"f[%d] = %d\n", i+1,sum);
				res.fib_seq =res.fib_seq+info;
				}
			sum= vec[0]+vec[1];
			vec[0]=vec[1];
			vec[1]=sum;
			}
		}
	  ROS_INFO("Requested: index[%d], length[%d].\n %s ", req.index, req.length, res.fib_seq.c_str());
		
	 
	return true;
}

int main(int argc, char **argv) {
	ros::init(argc, argv, "service_server");
	ros::NodeHandle nh;
	ros::ServiceServer service = nh.advertiseService("service", 		service_callback);
	ROS_INFO("Ready to receive from client.");
	ros::spin();
	return 0;
}
