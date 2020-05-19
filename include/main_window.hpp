#ifndef qtros_MAIN_WINDOW_H
#define qtros_MAIN_WINDOW_H


#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include "qnode.hpp"
#include <QtCore>


namespace qtros 
{
    class MainWindow : public QMainWindow 
    {
        Q_OBJECT

        public:
	    MainWindow(int argc, char** argv, QWidget *parent = 0);
	    ~MainWindow();
        public:
            void timerEvent( QTimerEvent *event );
            int m_nTimerId;

        private slots:
            void on_btn1_clicked();

        private:
            QPushButton *btn1;
            QNode qnode;
    };
}

#endif
