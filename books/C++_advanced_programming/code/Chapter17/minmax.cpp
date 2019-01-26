#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int x = 4, y = 5;
    cout << "x is " << x << " and y is " << y << endl;
    cout << "Max is " << max(x, y) << endl;
    cout << "Min is " << min(x, y) << endl;

    // Using max() and min() on more than two values
    int x1 = 2, x2 = 9, x3 = 3, x4 = 12;
    auto p2 = minmax( {x1, x2, x3, x4 } );
    cout << "Minmax of 4 elements is <"
        << p2.first << "," << p2.second << ">" << endl;

    // Using minmax_element()
    vector<int> vec{11, 33, 22};
    auto result = minmax_element(vec.cbegin(), vec.cend());
    cout << "minmax_element() result: <"
        << *result.first << "," <<*result.second << ">" << endl;

    return 0;
}
