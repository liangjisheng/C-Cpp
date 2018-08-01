#include <iostream>
#include <string>

using namespace std;

// Forward class declaration
class myString;

class myInt
{
public:
    myInt(int num = 0) : mValue(num) {}
    myInt operator+(const myString& rhs) const;
    int getInt() const { return mValue; }

private:
    int mValue;
};


class myString
{
public:
    myString(const std::string& str) : mString(str) {}
    myString operator+(const myInt& rhs) const;
    const std::string& getString() const { return mString; }

private:
    std::string mString;
};


myInt myInt::operator+(const myString& rhs) const
{
    return mValue + stoi(rhs.getString());
}


int main()
{

    return 0;
}
