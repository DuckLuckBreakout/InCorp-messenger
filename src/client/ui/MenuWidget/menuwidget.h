#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include <QFrame>

#include "ui/LogWidget/logwidget.h"


namespace Ui {
    class MenuWidget;
}

class MenuWidget : public QFrame, public std::enable_shared_from_this<MenuWidget> {
    Q_OBJECT

public:
    explicit MenuWidget(QWidget *parent = nullptr);
    ~MenuWidget();

    LogWidget *logWidget;
protected:
    Ui::MenuWidget *ui;

public slots:
    void on_getLogButton_clicked();
};

#endif // MENUWIDGET_H
