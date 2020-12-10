#ifndef GROUPLISTVIEW_H
#define GROUPLISTVIEW_H

#include <QListView>


class GroupListView : public QListView {
    Q_OBJECT
public:
    GroupListView(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent *e) override;
    int getRowWidth() const;
private:
    int rowWidth;
};


#endif // GROUPLISTVIEW_H
