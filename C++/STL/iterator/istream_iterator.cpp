#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vec1;
    for(int i = 0; i < 10; i++)
        vec1.push_back(i);

    copy(vec1.cbegin(), vec1.cend(),
         ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << endl;
    cout << "Enter number separated by write space." << endl;
    cout << "Press Ctrl+Z followed by Enter to stop." << endl;
    istream_iterator<int> numberIter(cin);
    istream_iterator<int> endIter;
    int sum = accumulate(numberIter, endIter, 0);
    cout << "sum = " << sum << endl;

    return 0;
}
