#ifndef DOCUMENTHANDLER_H

#define DOCUMENTHANDLER_H
#include <QQuickTextDocument>
#include "highlighter.h"
#include <QtGui/QTextCharFormat>
#include <QtCore/QTextCodec>
#include <qqmlfile.h>

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

class DocumentHandler : public QObject
{
    Q_OBJECT
    Q_ENUMS(HAlignment)
    Q_PROPERTY(QQuickItem *target READ target WRITE setTarget NOTIFY targetChanged)
    Q_PROPERTY(int cursorPosition READ cursorPosition WRITE setCursorPosition NOTIFY cursorPositionChanged)
    Q_PROPERTY(int selectionStart READ selectionStart WRITE setSelectionStart NOTIFY selectionStartChanged)
    Q_PROPERTY(int selectionEnd READ selectionEnd WRITE setSelectionEnd NOTIFY selectionEndChanged)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
public:
    DocumentHandler();
    QQuickItem *target() { return m_target; }
    void setTarget(QQuickItem *target);
    void setCursorPosition(int position);
    void setSelectionStart(int position);
    void setSelectionEnd(int position);
    int cursorPosition() const { return m_cursorPosition; }
    int selectionStart() const { return m_selectionStart; }
    int selectionEnd() const { return m_selectionEnd; }
    QString text() const;
public Q_SLOTS:
    void setText(const QString &arg);
    void setStyle(QString primaryColor, QString secondaryColor, QString highlightColor, QString secondaryHighlightColor, qreal m_baseFontPointSize);
Q_SIGNALS:
    void targetChanged();
    void cursorPositionChanged();
    void selectionStartChanged();
    void selectionEndChanged();
    void textChanged();
private:
    void reset();
    QTextCursor textCursor() const;
    void mergeFormatOnWordOrSelection(const QTextCharFormat &format);
    QQuickItem *m_target;
    QTextDocument *m_doc;
    int m_cursorPosition;
    int m_selectionStart;
    int m_selectionEnd;
    Highlighter *m_highlighter;
    QString m_text;
};
#endif
