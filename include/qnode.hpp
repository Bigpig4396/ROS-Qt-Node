#ifndef qtros_QNODE_HPP_
#define qtros_QNODE_HPP_

#include <ros/ros.h>
#include <string>
#include <QThread>
#include <QStringListModel>
#include "sensor_msgs/Imu.h"
#include <fstream>
#include <iostream>

namespace qtros 
{
    class QNode : public QThread 
    {
        Q_OBJECT
        public:
	    QNode(int argc, char** argv );
	    virtual ~QNode();
	    bool init();
	    void run();

        Q_SIGNALS:
            void rosShutdown();
        private:
	    int init_argc;
	    char** init_argv;
	    ros::Publisher chatter_publisher;
    };
}

#endif
