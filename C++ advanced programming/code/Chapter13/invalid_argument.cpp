#include <iostream>
#include <stdexcept>
using namespace std;

int SafeDevide(int num,int den)
{
    if(0 == den)
        throw invalid_argument("Divide by zero");
    return num / den;
}

int main()
{
    try{
        cout << SafeDevide(5,2) << endl;
        cout << SafeDevide(10,0) << endl;
        cout << SafeDevide(3,3) << endl;
    }catch(const invalid_argument& e){
        cout << "Caught exception: " << e.what() << endl;
    }

    return 0;
}
