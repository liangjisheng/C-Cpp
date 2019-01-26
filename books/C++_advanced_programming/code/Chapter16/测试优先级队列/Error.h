#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED

#include <string>
#include <ostream>

// Sample Error class with just a priority and a string error description
class Error{
public:
    Error(int priority = 0,const std::string& errMsg = "")
        : mPriority(priority),mError(errMsg) {}
    virtual ~Error() {}
    int getPriority() const { return mPriority; }
    const std::string& getErrorString() const { return mError; }
    friend bool operator<(const Error& lhs,const Error& rhs);
    friend std::ostream& operator<<(std::ostream& os,const Error& err);
private:
    int mPriority;
    std::string mError;
};

bool operator< (const Error& lhs,const Error& rhs)
{
    return lhs.getPriority() < rhs.getPriority();
}

std::ostream& operator<< (std::ostream& os,const Error& err)
{
    os << "priority :" << err.getPriority()
        << " description :" << err.getErrorString() << std::endl;
    return os;
}

#endif // ERROR_H_INCLUDED
