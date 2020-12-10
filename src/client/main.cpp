#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QDebug>
#include <QtWidgets/QGridLayout>
#include "ui/LoginWidget/loginwidget.h"
#include "ui/Viewer/Viewer.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Viewer viewer;
    viewer.runApp();

    return a.exec();
}