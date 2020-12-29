#ifndef CHATVIEW_H
#define CHATVIEW_H

#include <QListView>
#include <QAbstractScrollArea>
#include <QScrollEvent>

class ChatView : public QListView
{
    Q_OBJECT
public:
    ChatView(QWidget *parent = nullptr);
    void resizeEvent(QResizeEvent *event) override;
    void rowsInserted(const QModelIndex &parent, int start, int end) override;
    void rowsAboutToBeRemoved(const QModelIndex &parent, int start, int end) override;
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles = QVector<int>()) override;
    void mousePressEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *e) override;

private:
    QImage *background;
    int currHeight{0};
public slots:
    void scrollWhileDataChanged();
signals:
    void insertRow(int);

};

#endif // CHATVIEW_H
