#include "logdelegate.h"
#include <QApplication>
#include <QMouseEvent>
#include <QFontMetrics>
#include <QDebug>
#include <QTextLine>
#include <QLabel>
#include <QLineEdit>

#include "ui/Views/Models/LogModel/logmodel.h"

LogDelegate::LogDelegate(QWidget *parent)
    : QStyledItemDelegate(parent) {
    showPicture.move(parent->pos().x() + parent->size().width()/(4),
                     parent->pos().y() + parent->size().height()/(4));
    showPicture.setWindowFlag(Qt::Popup);
    showPicture.resize(900,600);

}

QSize LogDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    LogItemView item = index.model()->data(index).value<LogItemView>();
    QRect MessageRect = option.rect;
    MessageRect.setY( mainMessageTopOffset + option.rect.y());
    MessageRect.setX(textOffset);
    MessageRect.setWidth(option.widget->width() - 80);
    QFontMetrics fMetrics(option.font);
    int height = fMetrics.boundingRect(QRect(0,0,
                                             option.widget->width() - MessageRect.x() - 35,0),
                                       Qt::TextWordWrap,QString::fromStdString(item.text)).height();

    if (height <= 45)
        return QSize(option.widget->width(),baseItemHeight);
    else
         return QSize(option.widget->width(),height + 15);
}

void LogDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    LogItemView item = index.model()->data(index).value<LogItemView>();
    QStyleOptionViewItem myOpt = option;
    myOpt.displayAlignment =  Qt::AlignVCenter;
    painter->save();
    painter->setClipping(true);

    QRect rect(myOpt.rect);
    rect.setWidth(option.widget->width());
    rect.setHeight(sizeHint(option,index).height());

    const QPalette &palette(myOpt.palette);
    QFont f(myOpt.font);
    painter->fillRect(rect, myOpt.state & QStyle::State_Selected ?
                             palette.highlight().color() :
                             palette.light().color());
    painter->setFont(myOpt.font);

    int width = sizeHint(option,index).width();
    QFontMetrics font(f);

    painter->restore();

    painter->save();
    QRect NameRect = myOpt.rect;
    NameRect.setHeight(baseTextHeight);
    NameRect.setX(textOffset);
    NameRect.setWidth(width - rightMessageOffset);

    painter->setFont(f);
    painter->setPen(QColor(76,148,224));
    painter->drawText(NameRect, Qt::TextSingleLine,
                      (QString::fromStdString(item.operation)));

    QRect TimeRect = myOpt.rect;
    TimeRect.setHeight(baseTextHeight);
    TimeRect.setX(myOpt.widget->width() - 120);
    TimeRect.setWidth(width - rightMessageOffset);
    painter->drawText(TimeRect, Qt::TextSingleLine,
                      item.time);

    QRect MessageRect = myOpt.rect;
    MessageRect.setY(MessageRect.y() + mainMessageTopOffset);
    MessageRect.setX(textOffset);
    MessageRect.setWidth(width - rightMessageOffset - 5);

    painter->setFont(f);
    painter->setPen(palette.text().color());
    painter->drawText(MessageRect,  Qt::AlignLeft | Qt::TextWordWrap,
                   QString::fromStdString(item.text));

    painter->restore();
    painter->save();

    painter->restore();
}
