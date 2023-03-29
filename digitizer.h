#ifndef DIGITIZER_H
#define DIGITIZER_H

#include <QWidget>
#include <QGroupBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QRegularExpression>
#include <QIcon>
#include <QPushButton>

class Digitizer : public QWidget
{
    Q_OBJECT
public:
    explicit Digitizer(QWidget *parent = nullptr);

private slots:
    void getDigitizer();

private:
    void digitizerInputGroupBox();
    void digitizerResultsGroupBox();

    QGroupBox *digitizerInputGroup;
    QGroupBox *digitizerResultsGroup;
    QLineEdit *digitizerTxtInput;
    QLineEdit *digitizerTxtResultDigitOnly;
    QLineEdit *digitizerTxtResultDigitOnly9;
    QLineEdit *digitizerTxtResultDecimalDot;
    QLineEdit *digitizerTxtResultDecimalComma;
    QLineEdit *digitizerTxtResultDotToComma;
    QLineEdit *digitizerTxtResultCommaToDot;

};

#endif // DIGITIZER_H
