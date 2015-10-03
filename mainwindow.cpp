#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scheduler.h"

#define MAX_PROCESSES 8

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Process *p;
    p = new Process;
    pro = p;

    Dispatcher *d;
    d = new Dispatcher;
    dis = d;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonCreateTask_clicked()
{
    if(pro->processes.size() < MAX_PROCESSES)
    {
        addProcess(pro);
    }
}

void MainWindow::on_pushButtonSwitchProc_clicked()
{
    for (qint8 i = 0; i < pro->processes.size(); ++i)
    {
        if (pro->processes.at(i).state == Running)
        {
            pro->c_switch = Interupt;
            dis->setActiveProc(pro);
            pro->processes[i].state = Ready;
            pro->processes[i].name = "Ready";
            updateTables();
            return;
        }
    }
}

void MainWindow::on_pushButtonBlkProc_clicked()
{
    for (qint8 i = 0; i < pro->processes.size(); ++i)
    {
        if (pro->processes.at(i).id == ui->lineEditBlk->text().toInt())
        {
            //if (pro->processes.at(i).state == Running)

            pro->processes[i].state = Blocked;
            pro->processes[i].name = "Blocked";
            dis->setActiveProc(pro);
            updateTables();
            return;
        }
    }
    ui->lineEditBlk->setText("Please enter a valid ID");
}

void MainWindow::on_pushButtonUnBlk_clicked()
{
    for (qint8 i = 0; i < pro->processes.size(); ++i)
    {
        if ((pro->processes.at(i).state == Blocked)
                && (pro->processes.at(i).id == ui->lineEditUnBlk->text().toInt()))
        {
            pro->processes[i].state      = Ready;
            pro->processes[i].name       = "Ready";
            pro->c_switch = Blocking;
            dis->setActiveProc(pro);
            updateTables();
            return;
        }
    }
    ui->lineEditUnBlk->setText("Please enter a valid ID");
}

void MainWindow::on_pushButtonDelProc_clicked()
{
    for (qint8 i = 0; i < pro->processes.size(); ++i)
    {
        if (pro->processes.at(i).id == ui->lineEditDelete->text().toInt())
        {
            pro->c_switch = Delete;
            pro->processes.removeAt(i);
            dis->setActiveProc(pro);
            updateTables();
            return;
        }
    }
    ui->lineEditDelete->setText("Please enter a valid ID");
}

void MainWindow::addProcess(Process *pro)
{
    Process* test;
    test = new Process;

    if (pro->processes.size())
        test->id = pro->processes.value(pro->processes.size() - 1).id + 1;
    else
        test->id = pro->processes.size() + 101;
    test->priority = pro->processes.value(pro->processes.size() - 1).priority + 1;

    if(pro->processes.size() == 0)
    {
        test->state = Running;
        test->name = "Running";
    }
    else
    {
        test->state = Ready;
        test->name = "Ready";
    }

    pro->processes.append(*test);

    addToProcTable(test);
    updateTables();
}

void MainWindow::updateTables()
{
    QTableWidgetItem *proc_id, *proc_pri, *proc_state;

    ui->tableProcesses->clearContents();
    ui->tableBlocked->clear();
    ui->tableReady->clear();

    for (qint8 i = 0; i < pro->processes.size(); ++i)
    {
        proc_id    = new QTableWidgetItem(QString::number(pro->processes[i].id));
        proc_pri   = new QTableWidgetItem(QString::number(pro->processes[i].priority));
        proc_state = new QTableWidgetItem(pro->processes[i].name);

        proc_id->setTextAlignment(Qt::AlignCenter);
        proc_pri->setTextAlignment(Qt::AlignCenter);
        proc_state->setTextAlignment(Qt::AlignCenter);

        ui->tableProcesses->setItem(i,0,proc_id);
        ui->tableProcesses->setItem(i,1,proc_pri);
        ui->tableProcesses->setItem(i,2,proc_state);

        if (pro->processes[i].state == Ready)
            addToReadyList(&pro->processes[i]);
        else if (pro->processes[i].state == Blocked)
            addToBlockList(&pro->processes[i]);
    }
}

void MainWindow::addToProcTable(Process *proc)
{
    QTableWidgetItem *proc_id, *proc_pri, *proc_state;

    proc_id    = new QTableWidgetItem(QString::number(proc->id));
    proc_pri   = new QTableWidgetItem(QString::number(proc->priority));
    proc_state = new QTableWidgetItem(proc->name);

    proc_id->setTextAlignment(Qt::AlignCenter);
    proc_pri->setTextAlignment(Qt::AlignCenter);
    proc_state->setTextAlignment(Qt::AlignCenter);

    ui->tableProcesses->setItem(proc->priority - 1,0,proc_id);
    ui->tableProcesses->setItem(proc->priority - 1,1,proc_pri);
    ui->tableProcesses->setItem(proc->priority - 1,2,proc_state);
}

void MainWindow::addToReadyList(Process *proc)
{
    QListWidgetItem *proc_id;
    proc_id = new QListWidgetItem;
    proc_id->setText(QString::number(proc->id));
    ui->tableReady->addItem(proc_id);
}

void MainWindow::addToBlockList(Process *proc)
{
    QListWidgetItem *proc_id;
    proc_id = new QListWidgetItem;
    proc_id->setText(QString::number(proc->id));
    ui->tableBlocked->addItem(proc_id);
}
