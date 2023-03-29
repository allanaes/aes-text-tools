#ifndef CHANGECASE_H
#define CHANGECASE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QIcon>

class ChangeCase : public QWidget
{
    Q_OBJECT
public:
    explicit ChangeCase(QWidget *parent = nullptr);

private slots:
    void toSimplified();
    void toUpperCase();
    void toLowerCase();
    void toProperCase();
    void toSentenceCase();
    QString capitalizeAfterChar(const QString& txt, const QString& c);
    QString subtituteCommon(const QString& txt);

private:
    QPlainTextEdit *changeCaseTxtInput;

};

#endif // CHANGECASE_H
