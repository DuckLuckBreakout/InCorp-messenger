#include "logmodel.h"
#include <memory>
#include <QDebug>
#include <unordered_set>
#include <QPixmap>
#include <ui/Callbacks/Log.h>

LogModel::LogModel(QObject *parent)
    :QAbstractListModel(parent) {}

int LogModel::rowCount(const QModelIndex &parent) const {
     return items.size();
}

QVariant LogModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (index.row() >= items.size())
        return QVariant();

    if (role == Qt::DisplayRole) {
        auto item = items.at(index.row());
        return QVariant::fromValue(item);
    }
    else
        return QVariant();
}

void LogModel::createLog(const Log& log) {
    QByteArray array;

    int row = this->rowCount();
    beginInsertRows(QModelIndex(),row,row + 1);
    if(log.text != "") {
        items.emplace_back(LogItemView(log));
    }
    endInsertRows();
    emit updateItems();
}

void LogModel::newLog(const Log& log) {
    int row = this->rowCount();
    beginInsertRows(QModelIndex(),row,row + 1);
    endInsertRows();
    emit updateItems();
}

void LogModel::setData(std::vector<Log>& logs) {
    if (!logs.empty()) {
        int row = this->rowCount();
        beginInsertRows(QModelIndex(), row, row + logs.size() - 1);
        for (auto &object : logs) {
            items.emplace_back(Log(object));
        }
        endInsertRows();
    }


    emit updateItems();
}

std::vector<LogItemView> LogModel::getItems() {
    return items;
}


void LogModel::Clear() {
    beginResetModel();
    items.clear();
    endResetModel();
}



