#include <iostream>
#include <functional>

using namespace std;

int main()
{
    plus<int> myPlus;
    int res = myPlus(4,5);
    cout << res << endl;

    minus<int> myMinus;
    res = myMinus(5,4);
    cout << res << endl;

    multiplies<int> myMultiply;
    res = myMultiply(4,5);
    cout << res << endl;

    divides<int> myDivides;
    res = myDivides(8,2);
    cout << res << endl;

    modulus<int> myModulus;
    res = myModulus(2,3);
    cout << res << endl;

    return 0;
}
