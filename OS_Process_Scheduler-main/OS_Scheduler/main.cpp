#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    a.setWindowIcon(QIcon(":/img.ico"));
    w.setWindowTitle("OS Scheduler");
    w.show();
    return a.exec();
}
