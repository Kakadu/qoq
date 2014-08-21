#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QHash>
#include <QTextCharFormat>

class QTextDocument;

class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    Highlighter(QTextDocument *parent = 0);

    void setStyle(QString primaryColor, QString secondaryColor, QString highlightColor, QString secondaryHighlightColor, qreal m_baseFontPointSize);
protected:
    void highlightBlock(const QString &text);

private:
    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };

    void updateRules();

    QVector<HighlightingRule> highlightingRules;

    QString m_keywordColor;
    QString m_normalColor;
    QString m_commentColor;
    QString m_evaluatedColor;

    qreal m_baseFontPointSize;

    QRegExp commentStartExpression;
    QRegExp commentEndExpression;

    QTextCharFormat italicFormat;
    QTextCharFormat boldFormat;
    QTextCharFormat boldItalicFormat;
    QTextCharFormat header6Format;
    QTextCharFormat header5Format;
    QTextCharFormat header4Format;
    QTextCharFormat header3Format;
    QTextCharFormat header2Format;
    QTextCharFormat header1Format;
    QTextCharFormat imageFormat;
    QTextCharFormat linkFormat;

    QTextCharFormat keywordFormat;

};

#endif
