#include <iostream>
#include <vector>
using namespace std;

int main()
{
    const size_t Count = 10;
    unsigned int arr[Count];    // standard C-style array
    for(unsigned int i = 0; i < Count; ++i)
        arr[i] = i;

    vector<int> vec;
    vec.insert(vec.end(), arr, arr + Count);

    // print
    for(const auto& i : vec)
        cout << i << ' ';
    cout << endl;

    return 0;
}
