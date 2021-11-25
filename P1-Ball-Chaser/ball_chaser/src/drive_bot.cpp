#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "ball_chaser/DriveToTarget.h"

ros::Publisher motor_command_publisher;

bool handle_drive_request(ball_chaser::DriveToTarget::Request& req, ball_chaser::DriveToTarget::Response& res) {
    float linear_x = req.linear_x;
    float angular_z = req.angular_z;
  
	geometry_msgs::Twist motor_command;

    // Set wheel velocities
    motor_command.linear.x = linear_x;
    motor_command.angular.z = angular_z;

    // Publish angles to drive the robot
    motor_command_publisher.publish(motor_command);
	
    // Return a response message
    res.msg_feedback = "Published to wheels - linearX: " + std::to_string(linear_x) +
                       " , angularZ: " + std::to_string(angular_z);
}

int main(int argc, char** argv)
{
    // Initialize a ROS node
    ros::init(argc, argv, "drive_bot");

    // Create a ROS NodeHandle object
    ros::NodeHandle n;

    // Inform ROS master that we will be publishing a message of type geometry_msgs::Twist on the robot actuation topic with a publishing queue size of 10
    motor_command_publisher = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    ros::ServiceServer service = n.advertiseService("/ball_chaser/command_robot", handle_drive_request);

    ros::spin();

    return 0;
}
