#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QIcon>
#include <QMessageBox>

//class QPushButton;
//class QTextBrowser;
//class QGridLayout;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void aboutDialog();

private:
    void createMenu();
    QString getBuildExecArch();

    QMenuBar* menuBar;
    QMenu *fileMenu;
    QMenu *aboutMenu;
    QMessageBox *about;
    QAction *exitAction;
    QAction *aboutAction;
};

#endif // MAINWINDOW_H
