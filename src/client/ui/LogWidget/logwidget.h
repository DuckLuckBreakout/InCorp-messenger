#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QWidget>
#include <QFrame>

#include "ui/Views/Models/LogModel/logmodel.h"
#include "ui/Views/Delegates/LogDelegate/logdelegate.h"


namespace Ui {
    class LogWidget;
}

class LogWidget : public QFrame {
    Q_OBJECT

public:
    explicit LogWidget(QWidget *parent = nullptr);
    ~LogWidget();


public:
    std::shared_ptr<LogModel> logModel;
private:
    Ui::LogWidget *ui;
    LogDelegate *logDelegate;
};

#endif // LOGWIDGET_H
