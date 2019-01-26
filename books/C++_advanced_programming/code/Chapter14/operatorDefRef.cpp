#include <iostream>
#include "operatorDefRef.h"
using namespace std;

int main()
{
    Pointer<int> smartInt(new int);
    *smartInt = 5;
    cout << *smartInt << endl;

    Pointer<double> smartDouble(new double);
    *smartDouble = 1.2;
    cout << *smartDouble << endl;

    return 0;
}
