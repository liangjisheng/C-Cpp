#include <iostream>
#include "Scheduler.h"
using namespace std;

int main()
{
    vector<Process> processes = { Process("1"), Process("2"),Process("3")};
    Scheduler sched(processes);
    for(int i = 0; i < 4; ++i)
        sched.scheduleTimeSlice();

    sched.removeProcess(processes[1]);
    cout << "Removed second process" << endl;
    for(int i = 0; i < 6; ++i)
        sched.scheduleTimeSlice();

    return 0;
}
