#ifndef CHATDELEGATE_H
#define CHATDELEGATE_H

#include <QStyledItemDelegate>
#include <QTextEdit>
#include <QPainter>

class ChatDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ChatDelegate(QWidget *parent = 0);
    QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const override;
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
                  const QModelIndex &index) const override;

private:
    QWidget showPicture;
    QPixmap *unload;
    QPixmap *check;
    QPixmap *uncheck;
    QPoint offset{5,5};
    int textOffset{15};
    int mainMessageTopOffset{14};
    int baseItemHeight{50};
    int rightMessageOffset{80};
    float baseTextHeight{15};
};


#endif // CHATDELEGATE_H
