#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include <QFrame>

#include "ui/LogWidget/logwidget.h"
#include "ui/RegistrateWidget/registratewidget.h"


namespace Ui {
    class MenuWidget;
}

class MenuWidget : public QFrame, public std::enable_shared_from_this<MenuWidget> {
    Q_OBJECT

public:
    explicit MenuWidget(QWidget *parent = nullptr);
    ~MenuWidget();

    void setRoleFunctions(const std::string& role);

    LogWidget *logWidget;
    RegistrateWidget *registrateWidget;
protected:
    Ui::MenuWidget *ui;

public slots:
    void on_getLogButton_clicked();
    void on_addUserButton_clicked();
//    void on_createChatButton_clicked();
};

#endif // MENUWIDGET_H
