#include "grouplistview.h"
#include <QResizeEvent>
#include <QDebug>

GroupListView::GroupListView(QWidget *parent) : QListView(parent) {
    this->setStyleSheet(                      
        "QListWidget{ outline: 0;}"
        "QListWidget::item:hover{   background-color:  rgb(240, 240, 243);selection-color: transperent;}"
        "QListWidget::item:selected{ background-color:  rgb(235, 235, 248);selection-color: transperent;}"
    );
    this->installEventFilter(this);
}

void GroupListView::resizeEvent(QResizeEvent *e) {
    rowWidth = e->size().width();
}

int GroupListView::getRowWidth() const {
    return rowWidth;
}
