#include "textview.h"
#include <QKeyEvent>
#include <QAbstractItemView>
#include <QScrollBar>
#include <QDebug>
#include <utility>
#include <QString>


TextView::TextView(QWidget *parent)
        : QTextEdit(parent) {
    commands.insert(std::pair<std::string, std::string>("create chat", "\n\ntitle: \nmembers id:"));
    commands.insert(std::pair<std::string, std::string>("create employee", "\n\nfist name: \nlast name: \nlogin: \npassword:"));
    commands.insert(std::pair<std::string, std::string>("create notice", "\n\ntitle: \ntext: \ntime (hh:mm) :"));
}

TextView::~TextView() {}


void TextView::setCompleter(QCompleter *completer) {
    if (c)
        c->disconnect(this);

    c = completer;

    if (!c)
        return;

    c->setWidget(this);
    c->setCompletionMode(QCompleter::PopupCompletion);
    c->setCaseSensitivity(Qt::CaseInsensitive);
    QObject::connect(c, QOverload<const QString &>::of(&QCompleter::activated),
                     this, &TextView::insertCompletion);
}

QCompleter *TextView::completer() const {
    return c;
}

void TextView::insertCompletion(const QString &completion) {
    if (c->widget() != this)
        return;
    QTextCursor tc = textCursor();
    int extra = completion.length() - c->completionPrefix().length();
    tc.movePosition(QTextCursor::Left);
    tc.movePosition(QTextCursor::EndOfWord);
    std::string key = (c->completionPrefix() + completion.right(extra)).toStdString();
    tc.insertText(completion.right(extra) + QString::fromStdString(commands[key]));
    setTextCursor(tc);
}

QString TextView::textUnderCursor() const {
    QTextCursor tc = textCursor();
    tc.select(QTextCursor::WordUnderCursor);
    return tc.selectedText();
}

void TextView::focusInEvent(QFocusEvent *e) {
    if (c)
        c->setWidget(this);
    QTextEdit::focusInEvent(e);
}

void TextView::keyPressEvent(QKeyEvent *e)
{
    if (c && c->popup()->isVisible()) {
        // The following keys are forwarded by the completer to the widget
        switch (e->key()) {
            case Qt::Key_Enter:
            case Qt::Key_Return:
            case Qt::Key_Escape:
            case Qt::Key_Tab:
            case Qt::Key_Backtab:
                e->ignore();
                return; // let the completer do default behavior
            default:
                break;
        }
    }

    const bool isShortcut = (e->modifiers().testFlag(Qt::ControlModifier) && e->key() == Qt::Key_E); // CTRL+E
    if (!c || !isShortcut) // do not process the shortcut when we have a completer
        QTextEdit::keyPressEvent(e);

    const bool ctrlOrShift = e->modifiers().testFlag(Qt::ControlModifier) ||
                             e->modifiers().testFlag(Qt::ShiftModifier);
    if (!c || (ctrlOrShift && e->text().isEmpty()))
        return;

    static QString eow("~!@#$%^&*()_+{}|:\"<>?,./;'[]\\-="); // end of word
    const bool hasModifier = (e->modifiers() != Qt::NoModifier) && !ctrlOrShift;
    QString completionPrefix = textUnderCursor();

    if (!isShortcut && (hasModifier || e->text().isEmpty()|| completionPrefix.length() < 3
                        || eow.contains(e->text().right(1)))) {
        c->popup()->hide();
        return;
    }

    if (completionPrefix != c->completionPrefix()) {
        c->setCompletionPrefix(completionPrefix);
        c->popup()->setCurrentIndex(c->completionModel()->index(0, 0));
    }
    QRect cr = cursorRect();
    cr.setWidth(c->popup()->sizeHintForColumn(0)
                + c->popup()->verticalScrollBar()->sizeHint().width());
    c->complete(cr); // popup it up!
}

