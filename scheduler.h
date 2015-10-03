#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <QString>
#include <QList>

enum State{Ready, Running, Blocked};
enum ContextSwitch{Interupt, Blocking, Delete};

class Process
{
public:
    quint8         id;
    quint8         priority;
    State          state;
    State          prev_state;
    ContextSwitch  c_switch;
    QString        name;
    QList<Process> processes;

private:

};

class Dispatcher
{
public:
    void setActiveProc(Process *proc);
};

#endif // SCHEDULER_H

