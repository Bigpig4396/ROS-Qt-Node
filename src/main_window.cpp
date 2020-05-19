/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../include/main_window.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace qtros 
{
    using namespace Qt;
    MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
    : QMainWindow(parent)
    , qnode(argc,argv)
    {
        setWindowIcon(QIcon(":/images/icon.png"));
        QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));
        qnode.init();
        m_nTimerId = startTimer(1000);
        setFixedSize(640, 480);

        // btn1
        this->btn1 = new QPushButton("My Button", this);
        this->btn1->setGeometry(QRect(QPoint(100, 100), QSize(200, 50)));
        connect(this->btn1, SIGNAL (clicked()), this, SLOT (on_btn1_clicked()));
        this->btn1->setText("Example");
        this->btn1->resize(100,100);
    }

    MainWindow::~MainWindow() 
    {
    }

    void qtros::MainWindow::timerEvent( QTimerEvent *event )
    {
      ROS_INFO("timer");
      update();
    }

    void qtros::MainWindow::on_btn1_clicked()
    {
        ROS_INFO("click 1");
        update();
    }
}
