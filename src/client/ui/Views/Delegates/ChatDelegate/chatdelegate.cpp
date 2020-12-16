#include "chatdelegate.h"
#include <QApplication>
#include <QMouseEvent>
#include <QFontMetrics>
#include <QDebug>
#include <QTextLine>
#include <QLabel>
#include <QLineEdit>

#include "ui/Views/Models/ChatModel/chatmodel.h"

ChatDelegate::ChatDelegate(QWidget *parent)
    : QStyledItemDelegate(parent) {
    unload = new QPixmap("src/client/ui/inc/images/unload.png");
    check = new QPixmap("src/client/ui/inc/images/check.png");
    uncheck = new QPixmap("src/client/ui/inc/images/uncheck.png");
    showPicture.move(parent->pos().x() + parent->size().width()/(4),
                     parent->pos().y() + parent->size().height()/(4));
    showPicture.setWindowFlag(Qt::Popup);
    showPicture.resize(900,600);

}

QSize ChatDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    MessageView item = index.model()->data(index).value<MessageView>();
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

bool ChatDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                               const QStyleOptionViewItem &option, const QModelIndex &index) {
    MessageView item = index.model()->data(index).value<MessageView>();
    QRect NameRect = option.rect;
    NameRect.setHeight(baseTextHeight);
    NameRect.setX(textOffset);
    NameRect.setWidth(option.widget->width() - rightMessageOffset);

    QRect MessageRect =option.rect;
    MessageRect.setY(MessageRect.y() + mainMessageTopOffset);
    MessageRect.setX(textOffset);
    MessageRect.setWidth(option.widget->width() - rightMessageOffset);
    QFontMetrics fMetrics(option.font);
    QRect ButtonRect = option.rect;
    ButtonRect.setWidth(45);

    return  QAbstractItemDelegate::editorEvent(event,model,option,index);
}

void ChatDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    MessageView item = index.model()->data(index).value<MessageView>();
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
                      (item.firstName + " " + item.lastName + "   (" + item.role + ")" ));

    QRect TimeRect = myOpt.rect;
    TimeRect.setHeight(baseTextHeight);
    TimeRect.setX(myOpt.widget->width() - 80);
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


    if (item.type == MessageView::MessageType::MESSAGE_WAS_NOT_SEND) {
        QPixmap checkScaled = unload->scaled(15, 15,
                                           Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
        QBrush check(checkScaled);
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setBrush(check);
        painter->translate(QPointF(rect.width()-30,rect.y() + 10));
        painter->fillRect(checkScaled.rect(),Qt::transparent);
        painter->translate(QPointF(-10,0));
        painter->drawPixmap(checkScaled.rect(),checkScaled);
    }
    else if (item.type == MessageView::MessageType::MESSAGE_WAS_SEND) {
        QPixmap checkScaled = uncheck->scaled(15, 15,
                                            Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
        QBrush check(checkScaled);
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setBrush(check);
        painter->translate(QPointF(rect.width()-30,rect.y() + 10));
        painter->fillRect(checkScaled.rect(),Qt::transparent);
        painter->translate(QPointF(-10,0));
        painter->drawPixmap(checkScaled.rect(),checkScaled);
    }
    else if (item.type == MessageView::MessageType::MESSAGE_WAS_READ) {

        QPixmap checkScaled = check->scaled(15, 15,
                                         Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);
        QBrush check(checkScaled);
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setBrush(check);
        painter->translate(QPointF(rect.width()-30,rect.y() + 10));
        painter->fillRect(checkScaled.rect(),Qt::transparent);
        painter->drawPixmap(checkScaled.rect(),checkScaled);

        painter->translate(QPointF(-10,0));
        painter->drawPixmap(checkScaled.rect(),checkScaled);
    }
    painter->restore();
}


void ChatDelegate::setEditorData(QWidget* editor, const QModelIndex &index) const{
    QStyledItemDelegate::setEditorData(editor,index);
     QLabel* le= qobject_cast<QLabel*>(editor);
    if(le){
         QString text = "test";
                le->setText(text);
        }

}

QWidget *ChatDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyledItemDelegate::createEditor(parent,option,index);
    QString text = QString::fromStdString(index.model()->data(index).value<MessageView>().text);
    QLabel* editor = new QLabel(text,parent);
    return editor;
}

void ChatDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyledItemDelegate::updateEditorGeometry(editor,option,index);
    editor->setGeometry(option.rect);
}
