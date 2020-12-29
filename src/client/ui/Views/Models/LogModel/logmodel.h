#ifndef LOGMODEL_H
#define LOGMODEL_H

#include <QAbstractListModel>
#include <memory>
#include <time.h>

#include <ChatObjects/Log.h>
#include <Controller/Controller.h>
#include "ui/UserData/UserData.h"




class LogItemView : public Log {
public:
    LogItemView() {}

    explicit LogItemView(const Log& item)
    : Log(item) {
        char buffer [100];
        strftime(buffer, 100,"%H:%M  %d.%m.%Y", localtime(&item.timeSend));
        time = QString::fromStdString(std::string(buffer));
    }

public:

    QString time;
};

Q_DECLARE_METATYPE(LogItemView);
Q_DECLARE_METATYPE(std::vector<Log>);

class LogModel : public QAbstractListModel, public std::enable_shared_from_this<LogModel>
{
    Q_OBJECT
public:
    LogModel(QObject *parent = nullptr);

    void setData(std::vector<Log>& logs);
    std::vector<LogItemView> getItems();
    void Clear();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

protected:
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

public slots:
    void createLog(const Log& log);
    void newLog(const Log& log);
signals:
    void updateItems();
public:
    std::vector<LogItemView> items;
private:
    std::optional<std::string> errString;
};


#endif // LOGMODEL_H
