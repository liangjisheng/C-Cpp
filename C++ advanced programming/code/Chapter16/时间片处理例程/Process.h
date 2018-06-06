#ifndef PROCESS_H_INCLUDED
#define PROCESS_H_INCLUDED

#include <string>

// Simple Process class
class Process
{
public:
    Process(const std::string& name = "") : mName(name) {}
    // Implementation of doWorkDuringTimeSlice would let the process
    // perform its work for the duration of a time slice
    // Actual implementation omitted.
    void doWorkDuringTimesSlice(){
        std::cout << "Process " << mName
                << " performing work during time slice." << std::endl;
    }
    // Needed for the RoundRobin::Remove method to work
    bool operator==(const Process& rhs){
        return mName == rhs.mName;
    }
private:
    std::string mName;
};

#endif // PROCESS_H_INCLUDED
