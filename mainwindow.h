#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

namespace Ui {
class MainWindow;
}

QT_BEGIN_NAMESPACE
class Process;
class Dispatcher;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Process *pro;

private slots:
    void on_pushButtonCreateTask_clicked();
    void on_pushButtonSwitchProc_clicked();
    void on_pushButtonDelProc_clicked();

    void on_pushButtonBlkProc_clicked();

    void on_pushButtonUnBlk_clicked();

private:
    Ui::MainWindow *ui;
    Dispatcher *dis;
    void addProcess(Process *pro);
    void addToProcTable(Process *proc);
    void addToReadyList(Process *proc);
    void addToBlockList(Process *proc);
    void updateTables();
};

#endif // MAINWINDOW_H
