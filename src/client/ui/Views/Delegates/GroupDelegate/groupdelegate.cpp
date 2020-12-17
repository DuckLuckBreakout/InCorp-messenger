#include "groupdelegate.h"
#include <QDebug>

GroupDelegate::GroupDelegate(QObject *parent)
    : QStyledItemDelegate(parent) {
    groupIcon =  new QPixmap("src/client/ui/inc/images/chat.png");
}

void GroupDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    GroupView item = index.model()->data(index).value<GroupView>();
    QStyleOptionViewItem myOpt = option;
    myOpt.displayAlignment = Qt::AlignLeft;

    const QRect &rect(myOpt.rect);
    painter->save();
    painter->setClipping(true);

    const QPalette &palette(myOpt.palette);
    QFont f(myOpt.font);

    painter->fillRect(rect, myOpt.state & QStyle::State_Selected ?
                             qRgb(230,230,230)  :
                             palette.light().color());
    painter->setFont(myOpt.font);
    int width = sizeHint(option,index).width();

    QFontMetrics font(f);
    QPixmap scaled = groupIcon->scaled(groupIconSize,
                                       Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

    QBrush brush(scaled);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setBrush(brush);
    painter->translate(QPointF(rect.topLeft() + offset));
    painter->drawRoundedRect(QRect(QPoint(0,0), groupIconSize), groupIconRadius, groupIconRadius);
    painter->restore();

    painter->save();

    QRect GroupNameRect = myOpt.rect;
    GroupNameRect.setY(GroupNameRect.y() + textTopOffset);
    GroupNameRect.setX(groupIconSize.width() + textLeftOffset);
    GroupNameRect.setWidth(width - textRigthOffset);

    f.setBold(true);
    painter->setFont(f);
    painter->setPen(palette.text().color());
    painter->drawText(GroupNameRect, Qt::TextSingleLine,
                      font.elidedText(QString::fromStdString(item.chatName),Qt::ElideRight,width - textRigthOffset));
    int nameWidth = 0;
    if (item.lastMessage.text != "") {
        QFontMetrics metr(f);
        nameWidth = metr.horizontalAdvance(item.lastMessage.firstName + item.lastMessage.lastName + 1);
        nameWidth += 5;
        QRect LastMessageNick = QRect(groupIconSize.width() + textLeftOffset,
                                   GroupNameRect.y() + lastMessageTopOffset,nameWidth,baseTextHeigth);

        painter->setPen(QColor(76,148,224));
        painter->drawText(LastMessageNick, Qt::TextSingleLine,
                      font.elidedText(item.lastMessage.firstName + " " + item.lastMessage.lastName + ':',
                                      Qt::ElideRight,width - textRigthOffset));
    }

    f.setBold(false);
    QRect LastMessageRect = QRect(groupIconSize.width() + textLeftOffset + 5 + nameWidth,
                                  GroupNameRect.y() + lastMessageTopOffset,width - textRigthOffset,baseTextHeigth);
    painter->setFont(f);
    painter->setPen(palette.text().color());
    painter->drawText(LastMessageRect, Qt::TextSingleLine,
                      font.elidedText(QString::fromStdString(item.lastMessage.text),Qt::ElideRight,width - textRigthOffset));

    if ((item.lastMessage.text != "") && (sizeHint(option,index).width() > timeMessageMaxOffset)) {
        QRect TimeMessageRect = QRect(width - groupIconSize.width() - timeRigthOffset ,GroupNameRect.y(),timeMessageWidth,baseTextHeigth);
        painter->setFont(f);
        painter->setPen(palette.text().color());
        painter->drawText(TimeMessageRect, Qt::TextSingleLine,
                      item.lastMessage.time);
    }
    painter->setPen(palette.mid().color());
    if (rect.y() != 0)
        painter->drawLine(GroupNameRect.x(),rect.y(),rect.width(),rect.y());

    painter->restore();
}

QSize GroupDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem opt(option);
    initStyleOption(&opt, index);
    return QSize(option.widget->width() - (option.widget->contentsMargins().left() + option.widget->contentsMargins().right()),baseItemHeight);
}
