#ifndef REGISTRATEWIDGET_H
#define REGISTRATEWIDGET_H

#include <QWidget>
#include <QFrame>
#include <Controller/Controller.h>

#include "ui/UserData/UserData.h"



namespace Ui {
    class RegistrateWidget;
}

class RegistrateWidget : public QFrame, public std::enable_shared_from_this<RegistrateWidget>  {
    Q_OBJECT

public:
    explicit RegistrateWidget(QWidget *parent = nullptr);
    ~RegistrateWidget();

    void setErrorStatus(const QString& string);
    void setSuccessStatus(const QString& string);
    void clearStatus();

public slots:
    void on_signupButton_clicked();

private:
    Ui::RegistrateWidget *ui;
};

#endif // REGISTRATEWIDGET_H
