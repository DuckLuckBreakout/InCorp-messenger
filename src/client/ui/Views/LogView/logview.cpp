#include "logview.h"
#include <QResizeEvent>
#include <QDebug>
#include <QPalette>

LogView::LogView(QWidget *parent) : QListView(parent) {
    this->setStyleSheet(
    "QListWidget{ outline: 0;}"
    "QListWidget::item:hover{   background-color:  rgb(240, 240, 243);selection-color: transperent;}"
    "QListWidget::item:selected{ background-color:  rgb(235, 235, 248);selection-color: transperent;}"
    );

    this->setAutoFillBackground(true);
}

void LogView::resizeEvent(QResizeEvent *event) {
    this->doItemsLayout();
    this->update();
}

void LogView::rowsInserted(const QModelIndex &parent, int start, int end) {
    this->scrollToBottom();
    QListView::rowsInserted(parent, start, end);

    for(int i = start; i < end; ++i) {
        currHeight += this->sizeHintForIndex(this->model()->index(i,0,parent)).height();
    }
//    emit insertRow(currHeight);
    currHeight = 0;
    QListView::scrollToBottom();
}

void LogView::rowsAboutToBeRemoved(const QModelIndex &parent, int start, int end) {
    this->scrollToBottom();
    QListView::rowsAboutToBeRemoved(parent,start,end);

    for(int i = start; i < end; ++i) {
        currHeight -= this->sizeHintForIndex(this->model()->index(i,0,parent)).height();
    }
//    emit insertRow(currHeight);
    currHeight = 0;
    QListView::scrollToBottom();
}

void LogView::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles) {
    this->scrollToBottom();
    QListView::dataChanged(topLeft,bottomRight,roles);
    currHeight = this->sizeHintForIndex(topLeft).height();
//    emit insertRow(currHeight);
    currHeight = 0;
    QListView::scrollToBottom();
}

void LogView::mousePressEvent(QMouseEvent *event) {
    QRegion scrollDownReg(this->size().width() - 50,this->size().height() - 50,40,40,QRegion::Ellipse);
    if (event->button() == Qt::LeftButton) {
         if( scrollDownReg.contains(event->pos())) {
             this->scrollToBottom();
         }
    }
    QListView::mousePressEvent(event);
}

void LogView::wheelEvent(QWheelEvent *e) {
    this->repaint();
}


void LogView::scrollWhileDataChanged() {
    this->scrollToBottom();
}
