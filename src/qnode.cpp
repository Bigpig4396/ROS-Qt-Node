
#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include "../include/qnode.hpp"

namespace qtros 
{
    QNode::QNode(int argc, char** argv) :
            init_argc(argc),
            init_argv(argv) 
    {
    }

    QNode::~QNode() 
    {
        if (ros::isStarted()) 
        {
            ros::shutdown(); // explicitly needed since we use ros::start();
            ros::waitForShutdown();
        }
        wait();
    }

    bool QNode::init() 
    {
        ros::init(init_argc, init_argv, "qtros");
        if (!ros::master::check()) 
        {
            return false;
        }
        ros::start();
        ros::NodeHandle n;
        chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);
        start();
        return true;
    }

    void QNode::run() 
    {
        ros::Rate loop_rate(1);
        int count = 0;
        while (ros::ok()) 
        {
            ros::spinOnce();
            loop_rate.sleep();
            ++count;
        }
        std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
        Q_EMIT rosShutdown();
    }

}
