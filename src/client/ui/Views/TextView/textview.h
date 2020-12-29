#ifndef APPLICATION_TEXTVIEW_H
#define APPLICATION_TEXTVIEW_H

#include <QTextEdit>
#include <QCompleter>

class TextView : public QTextEdit
{
    Q_OBJECT

public:
    TextView(QWidget *parent = nullptr);
    ~TextView();

    void setCompleter(QCompleter *c);
    QCompleter *completer() const;

protected:
    void keyPressEvent(QKeyEvent *e) override;
    void focusInEvent(QFocusEvent *e) override;

private slots:
            void insertCompletion(const QString &completion);

private:
    QString textUnderCursor() const;

public:
    std::map<std::string, std::string> commands;

private:
    QCompleter *c = nullptr;
};


#endif //APPLICATION_TEXTVIEW_H
