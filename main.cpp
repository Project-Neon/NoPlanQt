#include <QCoreApplication>
#include <QtGui>
#include <QApplication>

#include "detection/robocup_ssl_client.h"
#include "detection/data_manager.h"
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <QTextStream>

//int main(int argc, char **argv) {

//    QApplication app(argc, argv);
//    SSLVisionClientThread thread;

//    thread.start();

//    while(true) {

//        sleep(1);
//        out << "oi, eu sou o goku! " << endl;
//        float teste = thread.detection.yellow_robots[0].orientation();
//        out << teste << endl;

//    }

//}
