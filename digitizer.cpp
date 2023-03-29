#include "digitizer.h"

// Main Widget
Digitizer::Digitizer(QWidget *parent)
    : QWidget{parent}
{
    digitizerInputGroupBox();
    digitizerResultsGroupBox();

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(digitizerInputGroup);
    layout->addWidget(digitizerResultsGroup);
    layout->addStretch();
    setLayout(layout);
}

// Input widget
void Digitizer::digitizerInputGroupBox() {
    digitizerTxtInput = new QLineEdit();
//    digitizerTxtInput->setClearButtonEnabled(true);

    // main layout
    QHBoxLayout *inputLayout = new QHBoxLayout();

    // Input Layout
    QPushButton *btnClear = new QPushButton("Clear");
    btnClear->setIcon(QIcon(":/icons/clear.png"));

    QPushButton *btnPaste = new QPushButton("Paste");
    btnPaste->setIcon(QIcon(":/icons/paste.png"));

    inputLayout->addWidget(digitizerTxtInput);
    inputLayout->addWidget(btnClear);
    inputLayout->addWidget(btnPaste);

    // add main layout to groupbox
    digitizerInputGroup = new QGroupBox();
    digitizerInputGroup->setLayout(inputLayout);
    digitizerInputGroup->setTitle("Paste teks di sini");

    connect(btnPaste, SIGNAL(clicked(bool)), digitizerTxtInput, SLOT(paste()));
    connect(btnClear, SIGNAL(clicked(bool)), digitizerTxtInput, SLOT(clear()));
    connect(digitizerTxtInput, SIGNAL(textChanged(QString)), this, SLOT(getDigitizer()));
}

// Results widget
void Digitizer::digitizerResultsGroupBox() {    
    // Init line edit and set all results read only
    // [1-1]
    QHBoxLayout *digitOnlyLayout = new QHBoxLayout();

    digitizerTxtResultDigitOnly = new QLineEdit();
    digitizerTxtResultDigitOnly->setReadOnly(true);

    QPushButton *btnCopyDigitOnly = new QPushButton();
    btnCopyDigitOnly->setIcon(QIcon(":/icons/copy.png"));
    btnCopyDigitOnly->setToolTip("Copy");
    connect(btnCopyDigitOnly, SIGNAL(clicked(bool)), digitizerTxtResultDigitOnly, SLOT(selectAll()));
    connect(btnCopyDigitOnly, SIGNAL(clicked(bool)), digitizerTxtResultDigitOnly, SLOT(copy()));

    digitOnlyLayout->addWidget(digitizerTxtResultDigitOnly);
    digitOnlyLayout->addWidget(btnCopyDigitOnly);

    // [1-2]
    QHBoxLayout *digitOnly9Layout = new QHBoxLayout();

    digitizerTxtResultDigitOnly9 = new QLineEdit();
    digitizerTxtResultDigitOnly9->setReadOnly(true);

    QPushButton *btnCopyDigitOnly9 = new QPushButton();
    btnCopyDigitOnly9->setIcon(QIcon(":/icons/copy.png"));
    btnCopyDigitOnly9->setToolTip("Copy");
    connect(btnCopyDigitOnly9, SIGNAL(clicked(bool)), digitizerTxtResultDigitOnly9, SLOT(selectAll()));
    connect(btnCopyDigitOnly9, SIGNAL(clicked(bool)), digitizerTxtResultDigitOnly9, SLOT(copy()));

    digitOnly9Layout->addWidget(digitizerTxtResultDigitOnly9);
    digitOnly9Layout->addWidget(btnCopyDigitOnly9);

    // [2-1]
    QHBoxLayout *decimalDotLayout = new QHBoxLayout();

    digitizerTxtResultDecimalDot = new QLineEdit();
    digitizerTxtResultDecimalDot->setReadOnly(true);

    QPushButton *btnCopyDecimalDot = new QPushButton();
    btnCopyDecimalDot->setIcon(QIcon(":/icons/copy.png"));
    btnCopyDecimalDot->setToolTip("Copy");
    connect(btnCopyDecimalDot, SIGNAL(clicked(bool)), digitizerTxtResultDecimalDot, SLOT(selectAll()));
    connect(btnCopyDecimalDot, SIGNAL(clicked(bool)), digitizerTxtResultDecimalDot, SLOT(copy()));

    decimalDotLayout->addWidget(digitizerTxtResultDecimalDot);
    decimalDotLayout->addWidget(btnCopyDecimalDot);

    // [2-2]
    QHBoxLayout *dotToCommaLayout = new QHBoxLayout();

    digitizerTxtResultDotToComma = new QLineEdit();
    digitizerTxtResultDotToComma->setReadOnly(true);

    QPushButton *btnCopyDotToComma = new QPushButton();
    btnCopyDotToComma->setIcon(QIcon(":/icons/copy.png"));
    btnCopyDotToComma->setToolTip("Copy");
    connect(btnCopyDotToComma, SIGNAL(clicked(bool)), digitizerTxtResultDotToComma, SLOT(selectAll()));
    connect(btnCopyDotToComma, SIGNAL(clicked(bool)), digitizerTxtResultDotToComma, SLOT(copy()));

    dotToCommaLayout->addWidget(digitizerTxtResultDotToComma);
    dotToCommaLayout->addWidget(btnCopyDotToComma);

    // [3-1]
    QHBoxLayout *decimalCommaLayout = new QHBoxLayout();

    digitizerTxtResultDecimalComma = new QLineEdit();
    digitizerTxtResultDecimalComma->setReadOnly(true);

    QPushButton *btnCopyDecimalComma = new QPushButton();
    btnCopyDecimalComma->setIcon(QIcon(":/icons/copy.png"));
    btnCopyDecimalComma->setToolTip("Copy");
    connect(btnCopyDecimalComma, SIGNAL(clicked(bool)), digitizerTxtResultDecimalComma, SLOT(selectAll()));
    connect(btnCopyDecimalComma, SIGNAL(clicked(bool)), digitizerTxtResultDecimalComma, SLOT(copy()));

    decimalCommaLayout->addWidget(digitizerTxtResultDecimalComma);
    decimalCommaLayout->addWidget(btnCopyDecimalComma);

    // [3-2]
    QHBoxLayout *commaToDotLayout = new QHBoxLayout();

    digitizerTxtResultCommaToDot = new QLineEdit();
    digitizerTxtResultCommaToDot->setReadOnly(true);

    QPushButton *btnCopyCommaToDot = new QPushButton();
    btnCopyCommaToDot->setIcon(QIcon(":/icons/copy.png"));
    btnCopyCommaToDot->setToolTip("Copy");
    connect(btnCopyCommaToDot, SIGNAL(clicked(bool)), digitizerTxtResultCommaToDot, SLOT(selectAll()));
    connect(btnCopyCommaToDot, SIGNAL(clicked(bool)), digitizerTxtResultCommaToDot, SLOT(copy()));

    commaToDotLayout->addWidget(digitizerTxtResultCommaToDot);
    commaToDotLayout->addWidget(btnCopyCommaToDot);


    // Main layout
    QGridLayout *resultGridLayout = new QGridLayout();

    // [1] Digit only - full
    resultGridLayout->addWidget(new QLabel("Digit only (full)"), 0, 0);
    resultGridLayout->addLayout(digitOnlyLayout, 1 , 0);
    resultGridLayout->addWidget(new QLabel("to 9 digit:"), 1, 1, Qt::AlignmentFlag::AlignRight);
    resultGridLayout->addLayout(digitOnly9Layout, 1, 2);

    // [2] Digit decimal dot, and convert to comma
    resultGridLayout->addWidget(new QLabel("Digit decimal dot"), 2, 0);
    resultGridLayout->addLayout(decimalDotLayout, 3, 0);
    resultGridLayout->addWidget(new QLabel("to comma:"), 3, 1, Qt::AlignmentFlag::AlignRight);
    resultGridLayout->addLayout(dotToCommaLayout, 3, 2);

    // [3] Digit decimal comma, and convert to dot
    resultGridLayout->addWidget(new QLabel("Digit decimal comma"), 4, 0);
    resultGridLayout->addLayout(decimalCommaLayout, 5, 0);
    resultGridLayout->addWidget(new QLabel("to dot:"), 5, 1, Qt::AlignmentFlag::AlignRight);
    resultGridLayout->addLayout(commaToDotLayout, 5, 2);

    // add main layout to groupbox
    digitizerResultsGroup = new QGroupBox();
    digitizerResultsGroup->setLayout(resultGridLayout);
    digitizerResultsGroup->setTitle("Results");
}

// Get digits from input
void Digitizer::getDigitizer()
{
    // get input teks dan remove white space
    QString txtInput = digitizerTxtInput->text();
    txtInput = txtInput.replace(" ", "");
    txtInput = txtInput.replace("\t", "");
    txtInput = txtInput.replace("\n", "");

    // input line edit ke versi tanpa white space
    digitizerTxtInput->setText(txtInput);

    // start digitizer
    QString txtDigitOnly = txtInput;
    QString txtDecimalDot = txtInput;
    QString txtDecimalComma = txtInput;

    static QRegularExpression reDigitOnly("[^\\d\\s]");
    static QRegularExpression reDecimalDot("[^\\d\\.\\s]");
    static QRegularExpression reDecimalComma("[^\\d\\,\\s]");

    // mutate string to get digit only
    txtDigitOnly.remove(reDigitOnly);
    txtDecimalDot.remove(reDecimalDot);
    txtDecimalComma.remove(reDecimalComma);

    // convert dot to comma
    QString txtDecimalDotToComma = txtDecimalDot;
    txtDecimalDotToComma.replace(".", ",");

    // convert comma to dot
    QString txtDecimalCommaToDot = txtDecimalComma;
    txtDecimalCommaToDot.replace(",", ".");

    // display results
    digitizerTxtResultDigitOnly->setText(txtDigitOnly);
    digitizerTxtResultDigitOnly9->setText(txtDigitOnly.left(9));
    digitizerTxtResultDecimalDot->setText(txtDecimalDot);
    digitizerTxtResultDecimalComma->setText(txtDecimalComma);
    // converted results
    digitizerTxtResultDotToComma->setText(txtDecimalDotToComma);
    digitizerTxtResultCommaToDot->setText(txtDecimalCommaToDot);
}
