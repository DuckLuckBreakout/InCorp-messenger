#ifndef GROUPDELEGATE_H
#define GROUPDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include "ui/Views/Models/GroupModel/groupmodel.h"

class GroupDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit GroupDelegate(QObject *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index ) const override;

private:
    QPixmap *groupIcon;
    QPoint offset{5,5};
    int textLeftOffset{15};
    int textTopOffset{5};
    int baseTextHeigth{15};
    int lastMessageTopOffset{30};
    int textRigthOffset{150};
    int timeMessageWidth{40};
    int timeMessageMaxOffset{140};
    int baseItemHeight{60};
    int timeRigthOffset{20};
    QSize groupIconSize{50,50};
    int groupIconRadius{100};
};

#endif // GROUPDELEGATE_H
