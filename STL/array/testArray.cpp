#include <iostream>
#include <array>
using namespace std;

void print(const array<int,3>& arr)
{
    for(const auto& i : arr)
        cout << i << ' ';
    cout << endl;
}

int main()
{
    // array 类的大小是固定，不能增加或减小，目的是为了让array
    // 能分配在栈上，而不是像vector那样总是需要访问堆
    array<int,3> arr = {9,8,7};
    cout << "Array size = " << arr.size() << endl;
    print(arr);

    cout << "Performing arr.fill(3)..." << endl;
    // Use the fill method to change the contents of the array
    arr.fill(3);
    // Output the contents of the array using iterators.
    for(auto iter = arr.cbegin(); iter != arr.cend(); ++iter){
        cout << *iter << ' ';
    }
    cout << endl;

    return 0;
}
