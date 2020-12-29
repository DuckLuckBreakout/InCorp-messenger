#include "chatview.h"
#include <QResizeEvent>
#include <QDebug>
#include <QPalette>

ChatView::ChatView(QWidget *parent) : QListView(parent) {
    this->setStyleSheet(
    "QListWidget{ outline: 0;}"
    "QListWidget::item:hover{   background-color:  rgb(240, 240, 243);selection-color: transperent;}"
    "QListWidget::item:selected{ background-color:  rgb(235, 235, 248);selection-color: transperent;}"
    );

    this->setAutoFillBackground(true);
}

void ChatView::resizeEvent(QResizeEvent *event) {
    this->doItemsLayout();
    this->update();
}

void ChatView::rowsInserted(const QModelIndex &parent, int start, int end) {
    this->scrollToBottom();
    QListView::rowsInserted(parent, start, end);

    for(int i = start; i < end; ++i) {
        currHeight += this->sizeHintForIndex(this->model()->index(i,0,parent)).height();
    }
    emit insertRow(currHeight);
    currHeight = 0;
    QListView::scrollToBottom();
}

void ChatView::rowsAboutToBeRemoved(const QModelIndex &parent, int start, int end) {
    this->scrollToBottom();
    QListView::rowsAboutToBeRemoved(parent,start,end);

    for(int i = start; i < end; ++i) {
        currHeight -= this->sizeHintForIndex(this->model()->index(i,0,parent)).height();
    }
    emit insertRow(currHeight);
    currHeight = 0;
    QListView::scrollToBottom();
}

void ChatView::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles) {
    this->scrollToBottom();
    QListView::dataChanged(topLeft,bottomRight,roles);
    currHeight = this->sizeHintForIndex(topLeft).height();
    emit insertRow(currHeight);
    currHeight = 0;
    QListView::scrollToBottom();
}

void ChatView::mousePressEvent(QMouseEvent *event) {
    QRegion scrollDownReg(this->size().width() - 50,this->size().height() - 50,40,40,QRegion::Ellipse);
    if (event->button() == Qt::LeftButton) {
         if( scrollDownReg.contains(event->pos())) {
             this->scrollToBottom();
         }
    }
    QListView::mousePressEvent(event);
}

void ChatView::wheelEvent(QWheelEvent *e) {
    this->repaint();
}


void ChatView::scrollWhileDataChanged() {
    this->scrollToBottom();
}
