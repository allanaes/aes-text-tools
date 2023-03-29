#include "mainwindow.h"
#include "digitizer.h"
#include "changecase.h"

#define ABOUT \
    QDialog::tr("<h1>AES Text Tools</h1>" \
               "<p>Versi 0.1.20230207 (") \
    + QDialog::tr( getBuildExecArch().toLocal8Bit().data() ) \
    + QDialog::tr(")</p>" \
               "<p>Copyleft (ɔ) 2023 by allanaes</p>" \
               "<p>Aplikasi sederhana untuk memudahkan<br />" \
               "dalam memformat angka dan teks tanpa harus <br />" \
               "hapus karakter secara manual.</p>" \
               "<p>App Icon: Flaticon.com<br />"\
               "Button Icons: Fugue Icon&lt;p.yusukekamiyamane.com&gt;</p>" \
               )

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createMenu();

    QTabWidget* mainTab = new QTabWidget();
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QWidget* mainContainer = new QWidget();

    mainTab->addTab(new Digitizer(), tr("Digitizer"));
    mainTab->addTab(new ChangeCase(), tr("Change Case"));

    mainLayout->addWidget(mainTab);
    mainLayout->setMenuBar(menuBar);

    mainContainer->setLayout(mainLayout);
    setCentralWidget(mainContainer);
    setWindowTitle(tr("AES Text Tools"));
    setWindowIcon(QIcon(":/icons/app.png"));
    setMinimumWidth(480);
}

MainWindow::~MainWindow()
{

}

//  Main menu bar
void MainWindow::createMenu()
{
    menuBar = new QMenuBar;

    fileMenu = new QMenu(tr("&File"), this);
    exitAction = fileMenu->addAction(tr("E&xit"));
    exitAction->setIcon(QIcon(":/icons/cross.png"));

    aboutMenu = new QMenu(tr("&About"));
    aboutAction = aboutMenu->addAction(tr("&About"));

    menuBar->addMenu(fileMenu);
    menuBar->addAction(aboutAction);

    connect(exitAction, &QAction::triggered, this, &exit);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(aboutDialog()));
}

QString MainWindow::getBuildExecArch()
{
    #if Q_PROCESSOR_WORDSIZE == 4
        return QString("32-bit");
    #elif Q_PROCESSOR_WORDSIZE == 8
        return QString("64-bit");
    #else
        return QString("unknown");
    #endif
}

// About Dialog
void MainWindow::aboutDialog()
{
    about = new QMessageBox(this);
    about->setText(ABOUT);
    about->setWindowTitle(tr("Tentang Aplikasi"));
    about->setFixedWidth(240);
    about->exec();
}



