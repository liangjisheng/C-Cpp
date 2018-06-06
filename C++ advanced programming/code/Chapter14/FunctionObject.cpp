#include <iostream>

using namespace std;

class FunctionObject{
public:
    int operator()(int inParam);        // function call operator
    int doSquare(int inParam);          // Normal method
    void operator()(std::string& str);
    int operator()(int inAdd1,int inAdd2);
};

int FunctionObject::operator()(int inParam){
    return doSquare(inParam);
}

int FunctionObject::doSquare(int inParam){
    return inParam * inParam;
}

int main()
{
    int x = 3,xSquared,xSquaredAgain;
    FunctionObject square;
    xSquared = square(x);       // call function object
    xSquaredAgain = square.doSquare(x);

    cout << x << endl
        << xSquared << endl
        << xSquaredAgain << endl;

    return 0;
}
