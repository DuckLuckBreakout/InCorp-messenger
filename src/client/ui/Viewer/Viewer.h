#ifndef APPLICATION_VIEWER_H
#define APPLICATION_VIEWER_H

#include <QApplication>

#include "ui/LoginWidget/loginwidget.h"
#include "ui/MainWidget/mainwidget.h"


class Viewer : public QObject {
    Q_OBJECT
public:
    Viewer();
    void runApp();

public:
    std::shared_ptr<LoginWidget> loginWidget;
    std::shared_ptr<MainWidget> mainWidget;
};


#endif //APPLICATION_VIEWER_H
