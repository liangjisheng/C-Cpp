#include <iostream>
#include <iterator>
#include <vector>
#include <deque>

using namespace std;

template <class InputIt, class OutputIt>
OutputIt my_copy(InputIt first, InputIt last, OutputIt d_first)
{
    while (first != last)
        *d_first++ = *first++;
    return d_first;
}


int main()
{
    vector<int> v1 = { 0, 1, 2, 3, 4 };
    vector<int>::const_iterator i1;
    deque<int> q2;
    front_insert_iterator<deque<int> > i2(q2);
    ostream_iterator<int> i3(cout, "  **  ");

    my_copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, "  $$  "));

    for (i1 = v1.begin(); i1 != v1.end(); ++i1)
        *i2++ = *i1;
    cout << endl;

    for (i1 = v1.begin(); i1 != v1.end(); ++i1)
        *i3 = *i1;
    cout << endl;

    for (i1 = v1.begin(); i1 != v1.end(); ++i1)
        *i3++ = *i1;
    cout << endl;

    my_copy(q2.begin(), q2.end(), i3);
    cout << endl;

    return 0;
}
