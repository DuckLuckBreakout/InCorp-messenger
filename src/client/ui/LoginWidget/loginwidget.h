#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QMainWindow>
#include <QStackedWidget>
#include <QLineEdit>
#include <QStyle>
#include <QDebug>
#include <QMovie>
#include <iostream>
#include <memory>

#include <ChatObjects/Authorization.h>
#include <Controller/Controller.h>
#include <CallbacksHolder/Callback/BaseCallback.h>


namespace Ui {
class LoginWidget;
}

class LoginWidget : public QStackedWidget, public std::enable_shared_from_this<LoginWidget> {
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget() override;
    void login(const QString &login,const QString &password);


private slots:
    void on_loginButton_clicked();
    void showMainWidget();

signals:
    void openMainWidget();


public:
    friend class LoginCallback;
private:
    Ui::LoginWidget *ui;
};


#endif // LOGINWIDGET_H
