#include "documenthandler.h"
#include <QtGui/QTextDocument>
#include <QtGui/QTextCursor>
#include <QtGui/QFontDatabase>
#include <QtCore/QFileInfo>

DocumentHandler::DocumentHandler()
    : m_target(0)
    , m_doc(0)
    , m_cursorPosition(-1)
    , m_selectionStart(0)
    , m_selectionEnd(0)
    , m_highlighter(0)
{
}
void DocumentHandler::setTarget(QQuickItem *target)
{
    m_doc = 0;
    m_highlighter = 0;
    m_target = target;
    if (!m_target)
        return;
    QVariant doc = m_target->property("textDocument");
    if (doc.canConvert<QQuickTextDocument*>()) {
        QQuickTextDocument *qqdoc = doc.value<QQuickTextDocument*>();
        if (qqdoc)
            m_doc = qqdoc->textDocument();
        m_highlighter = new Highlighter(m_doc);
    }
    emit targetChanged();
}
void DocumentHandler::setStyle(QString primaryColor, QString secondaryColor, QString highlightColor, QString secondaryHighlightColor, qreal m_baseFontPointSize)
{
    if (m_highlighter) {
        m_highlighter->setStyle(primaryColor, secondaryColor, highlightColor, secondaryHighlightColor, m_baseFontPointSize);
    }
}
void DocumentHandler::setText(const QString &arg)
{
    if (m_text != arg) {
        m_text = arg;
        emit textChanged();
    }
}
QString DocumentHandler::text() const
{
    return m_text;
}
void DocumentHandler::setCursorPosition(int position)
{
    if (position == m_cursorPosition)
        return;
    m_cursorPosition = position;
    reset();
}
void DocumentHandler::reset()
{
}
QTextCursor DocumentHandler::textCursor() const
{
    QTextCursor cursor = QTextCursor(m_doc);
    if (m_selectionStart != m_selectionEnd) {
        cursor.setPosition(m_selectionStart);
        cursor.setPosition(m_selectionEnd, QTextCursor::KeepAnchor);
    } else {
        cursor.setPosition(m_cursorPosition);
    }
    return cursor;
}
void DocumentHandler::mergeFormatOnWordOrSelection(const QTextCharFormat &format)
{
    QTextCursor cursor = textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(format);
}
void DocumentHandler::setSelectionStart(int position)
{
    m_selectionStart = position;
}
void DocumentHandler::setSelectionEnd(int position)
{
    m_selectionEnd = position;
}
