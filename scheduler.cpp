#include "scheduler.h"

void Dispatcher::setActiveProc(Process *proc)
{
    // Search through all processes
    for (quint8 i = 0; i < proc->processes.size(); ++i)
    {
        if (proc->processes.at(i).state == Ready)
        {
            proc->processes[i].state = Running;
            proc->processes[i].name  = "Running";

            ++i;

            while (i < proc->processes.size())
            {
                if (proc->processes[i].state == Running)
                {
                    proc->processes[i].state = Ready;
                    proc->processes[i].name  = "Ready";
                }
                ++i;
            }
            return;
        }
        else if (proc->processes.at(i).state == Running)
            if (proc->c_switch != Interupt)
                return;
    }
}
