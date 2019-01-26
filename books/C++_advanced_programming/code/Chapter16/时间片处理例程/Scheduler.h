#ifndef SCHEDULER_H_INCLUDED
#define SCHEDULER_H_INCLUDED

#include "RoundRobin.h"
#include "Process.h"
// Simple round-robin base process scheduler
class Scheduler
{
public:
    // Constructor takes a vector of processes
    Scheduler(const std::vector<Process>& processes);
    // Selects the next process using a round-robin scheduling
    // algorithm and allows it to preform some work during
    // this time slice
    void scheduleTimeSlice();
    void removeProcess(const Process& process);
private:
    RoundRobin<Process> rr;
};

Scheduler::Scheduler(const std::vector<Process>& processes)
{
    for(auto& process : processes){
        rr.Add(process);
    }
}

void Scheduler::scheduleTimeSlice()
{
    try{
        rr.getNext().doWorkDuringTimesSlice();
    }catch(const std::out_of_range&){
        std::cerr << "No more processes to schedule." << std:: endl;
    }
}

void Scheduler::removeProcess(const Process& process)
{
    rr.Remove(process);
}

#endif // SCHEDULER_H_INCLUDED
