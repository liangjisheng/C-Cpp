#ifndef ERRORCORRELATOR_H_INCLUDED
#define ERRORCORRELATOR_H_INCLUDED

#include <queue>
#include "Error.h"
// Simple ErrorCorrelator class that returns highest priority errors first.

class ErrorCorrelator
{
public:
    // Add an error to be correlated
    void addError(const Error& error);
    Error getError();
private:
    std::priority_queue<Error> mErrors;
};


void ErrorCorrelator::addError(const Error& error)
{
    mErrors.push(error);
}

Error ErrorCorrelator::getError()
{
    if(mErrors.empty()) {
        throw std::out_of_range("No more errors.");
    }

    Error top = mErrors.top();
    mErrors.pop();
    return top;
}

#endif // ERRORCORRELATOR_H_INCLUDED
