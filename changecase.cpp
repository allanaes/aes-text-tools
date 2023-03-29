#include "changecase.h"

// Main Widget
ChangeCase::ChangeCase(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *btnLayout = new QHBoxLayout();
    QHBoxLayout *actionLayout = new QHBoxLayout();

    // action button layout
    QPushButton *btnCopy = new QPushButton("Copy All");
    btnCopy->setIcon(QIcon(":/icons/copy.png"));
    QPushButton *btnPaste = new QPushButton("Paste");
    btnPaste->setIcon(QIcon(":/icons/paste.png"));
    QPushButton *btnTrim = new QPushButton("Trim");
    btnTrim->setIcon(QIcon(":/icons/trim.png"));
    QPushButton *btnClear = new QPushButton("Clear");
    btnClear->setIcon(QIcon(":/icons/clear.png"));
    actionLayout->addWidget(btnCopy);
    actionLayout->addWidget(btnPaste);
    actionLayout->addWidget(btnTrim);
    actionLayout->addWidget(btnClear);

    // input text area
    changeCaseTxtInput = new QPlainTextEdit();

    // change case button layout
    QPushButton *btnUpper = new QPushButton("UPPER CASE");
    QPushButton *btnLower = new QPushButton("lower case");
    QPushButton *btnProper = new QPushButton("Proper Case");
    QPushButton *btnSentence = new QPushButton("Sentence case");
    btnLayout->addWidget(btnUpper);
    btnLayout->addWidget(btnLower);
    btnLayout->addWidget(btnProper);
    btnLayout->addWidget(btnSentence);

    // add to main layout
    mainLayout->addLayout(actionLayout);
    mainLayout->addWidget(changeCaseTxtInput);
    mainLayout->addLayout(btnLayout);

    setLayout(mainLayout);

    // select all and copy
    connect(btnCopy, SIGNAL(clicked(bool)), changeCaseTxtInput, SLOT(selectAll()));
    connect(btnCopy, SIGNAL(clicked(bool)), changeCaseTxtInput, SLOT(copy()));
    connect(btnPaste, SIGNAL(clicked(bool)), changeCaseTxtInput, SLOT(paste()));
    connect(btnTrim, SIGNAL(clicked(bool)), this, SLOT(toSimplified()));
    connect(btnClear, SIGNAL(clicked(bool)), changeCaseTxtInput, SLOT(clear()));

    connect(btnUpper, SIGNAL(clicked(bool)), this, SLOT(toUpperCase()));
    connect(btnLower, SIGNAL(clicked(bool)), this, SLOT(toLowerCase()));
    connect(btnProper, SIGNAL(clicked(bool)), this, SLOT(toProperCase()));
    connect(btnSentence, SIGNAL(clicked(bool)), this, SLOT(toSentenceCase()));
}

// To Simplified
void ChangeCase::toSimplified()
{
    QString txtInput = changeCaseTxtInput->toPlainText();
    QString txtSimple = txtInput.simplified();

    changeCaseTxtInput->setPlainText(txtSimple);
}

// To Upper Case
void ChangeCase::toUpperCase()
{
    QString txtInput = changeCaseTxtInput->toPlainText();
    QString txtUpper = txtInput.toUpper();

    changeCaseTxtInput->setPlainText(txtUpper);
}

// To Lower Case
void ChangeCase::toLowerCase()
{
    QString txtInput = changeCaseTxtInput->toPlainText();
    QString txtLower = txtInput.toLower();

    changeCaseTxtInput->setPlainText(txtLower);
}

// Capitalize After Char
QString ChangeCase::capitalizeAfterChar(const QString &text, const QString &c)
{
    // https://wiki.qt.io/Converting_Strings_from_and_to_Camel_Case
    // tanpa SkipEmptyParts agar whitespace tetap terjaga
    QStringList parts = text.split(c);
    for (int i = 0; i < parts.size(); ++i)
        parts[i].replace(0, 1, parts[i][0].toUpper());

    return parts.join(c);
}

// Capitalize Each Word
void ChangeCase::toProperCase()
{
    QString txtInput = changeCaseTxtInput->toPlainText();
    QString txtProper = txtInput.toLower();
    txtProper = capitalizeAfterChar(txtProper, " ");
    txtProper = capitalizeAfterChar(txtProper, "-");
    txtProper = capitalizeAfterChar(txtProper, ".");
    txtProper = capitalizeAfterChar(txtProper, ",");
    txtProper = capitalizeAfterChar(txtProper, "/");
    txtProper = capitalizeAfterChar(txtProper, "(");
    txtProper = capitalizeAfterChar(txtProper, "\n");
    txtProper = capitalizeAfterChar(txtProper, "\t");
    txtProper = capitalizeAfterChar(txtProper, "\\");
    txtProper = capitalizeAfterChar(txtProper, "\"");

    // subtitute common words
    txtProper = subtituteCommon(txtProper);

    changeCaseTxtInput->setPlainText(txtProper);
}


// Sentence Case
void ChangeCase::toSentenceCase()
{
    QString txtInput = changeCaseTxtInput->toPlainText();
    QString txtProper = txtInput.toLower();
    txtProper = capitalizeAfterChar(txtProper, ". ");
    txtProper = capitalizeAfterChar(txtProper, "? ");
    txtProper = capitalizeAfterChar(txtProper, "! ");
    txtProper = capitalizeAfterChar(txtProper, "\n");
    txtProper = capitalizeAfterChar(txtProper, "\"");

    // subtitute common words
    txtProper = subtituteCommon(txtProper);

    changeCaseTxtInput->setPlainText(txtProper);
}

// Subtitute Common Words
QString ChangeCase::subtituteCommon(const QString &text)
{
    QString txtNew = text;
    txtNew = txtNew.replace(" , ", ", ");
    txtNew.replace(" . ", ". ");
        txtNew.replace(" No ", " No. ");
        txtNew.replace("Jl ", "Jl. ");
        txtNew.replace("Kav ", "Kav. ");
        txtNew.replace(" Kab ", ", Kab. ");
        txtNew.replace(" Kec ", ", Kec. ");
        txtNew.replace(" Rt ", " RT.");
        txtNew.replace(" Rt. ", " RT.");
        txtNew.replace(" Rt. ", " RT.");
        txtNew.replace(" Rw ", " RW.");
        txtNew.replace(" Rw.", " RW.");
        txtNew.replace(" Rw. ", " RW.");
        txtNew.replace("Djp", "DJP", Qt::CaseInsensitive);
        txtNew.replace("Kpdjp", "KPDJP", Qt::CaseInsensitive);
        txtNew.replace("Kpp", "KPP", Qt::CaseInsensitive);
        txtNew.replace("Npwp", "NPWP", Qt::CaseInsensitive);
        txtNew.replace(" Ppn", " PPN", Qt::CaseInsensitive);
        txtNew.replace(" Ppnbm", " PPnBM", Qt::CaseInsensitive);
        txtNew.replace(" Pph", " PPh", Qt::CaseInsensitive);
        txtNew.replace(" Spt", " SPT", Qt::CaseInsensitive);
        txtNew.replace("Ppn ", "PPN ", Qt::CaseInsensitive);
        txtNew.replace("Ppnbm ", "PPNnBM ", Qt::CaseInsensitive);
        txtNew.replace("Pph ", "PPh ", Qt::CaseInsensitive);
        txtNew.replace("Spt ", "SPT ", Qt::CaseInsensitive);
        txtNew.replace("Spt Masa", "SPT Masa", Qt::CaseInsensitive);
        txtNew.replace("Spt Tahunan", "SPT Tahunan", Qt::CaseInsensitive);
        txtNew.replace("Pt ", "PT ", Qt::CaseInsensitive);
        txtNew.replace("Pt. ", "PT ");
        txtNew.replace("Cv ", "CV ", Qt::CaseInsensitive);
        txtNew.replace("Cv. ", "CV ");
        txtNew.replace("Cv.", "CV ");
        txtNew.replace(" Dari ", " dari ");
        txtNew.replace(" Di ", " di ");
        txtNew.replace(" Ke ", " ke ");
        txtNew.replace(" Pada ", " pada ");
        txtNew.replace(" Yang ", " yang ");
        txtNew.replace(" Untuk ", " untuk ");
        txtNew.replace(" Dengan ", " dengan ");
        txtNew.replace(" Dan ", " dan ");
        txtNew.replace(" Dan/Atau ", " dan/atau ");
        txtNew.replace(" Atau ", " atau ");
        txtNew.replace(" Atas ", " atas ");
        txtNew.replace(" Oleh ", " oleh ");
        txtNew.replace(" Tentang ", " tentang ");
        txtNew.replace(" Re Martadinata ", " RE Martadinata ");
        txtNew.replace(" Re. Martadinata ", " RE Martadinata ");
        txtNew.replace(" Mt Haryono ", " MT Haryono ");
        txtNew.replace(" Mt. Haryono ", " MT Haryono ");

    return txtNew;
}

