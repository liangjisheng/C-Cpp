
//#include <iostream>
//#include "Scheduler.h"

//Scheduler::Scheduler(const std::vector<Process>& processes)
//{
//    for(auto& process : processes){
//        rr.Add(process);
//    }
//}
//
//void Scheduler::scheduleTimeSlice()
//{
//    try{
//        rr.getNext().doWorkDuringTimesSlice();
//    }catch(const std::out_of_range&){
//        std::cerr << "No more processes to schedule." << std:: endl;
//    }
//}
//
//void Scheduler::removeProcess(const Process& process)
//{
//    rr.Remove(process);
//}
