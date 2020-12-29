#ifndef LOGDELEGATE_H
#define LOGDELEGATE_H

#include <QStyledItemDelegate>
#include <QTextEdit>
#include <QPainter>

class LogDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit LogDelegate(QWidget *parent = 0);
    QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const override;
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
                  const QModelIndex &index) const override;

private:
    QWidget showPicture;
    QPoint offset{5,5};
    int textOffset{15};
    int mainMessageTopOffset{14};
    int baseItemHeight{50};
    int rightMessageOffset{80};
    float baseTextHeight{15};
};


#endif // LOGDELEGATE_H
