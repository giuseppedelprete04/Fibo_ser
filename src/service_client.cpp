#include "ros/ros.h"
#include "ros_fibo/service.h"
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int main(int argc, char** argv) {
	int index;
	int length;
	ros::init(argc, argv, "service_client");
	ros::NodeHandle _nh;
	ros::ServiceClient client = 		 		 _nh.serviceClient<ros_fibo::service>("service");
	while (ros::ok()) {
		ros_fibo::service srv;

		cout<<"Insert index: ";
		cin>>index;
		cout<<"Insert length: ";
		cin>>length;
		
		
		srv.request.index = index;
		srv.request.length = length;
		if (client.call(srv)) {
    cout << "Server response " << srv.response.fib_seq << endl;
  }
		else {
			ROS_ERROR("Failed to call service");
			return 1;
		}
		ros::spinOnce();
		}
		return 0;
}
