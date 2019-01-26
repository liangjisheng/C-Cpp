#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

// forward_list和无序关联容器不能用reverse_iterator
// 反向遍历，rbegin()返回指向容器中最后一个元素的
// reverse_iterator, rend()返回指向容器中第一个元素之前的元素
// reverse_iterator.base()总是引用被调用reverse_iterator
// 引用的元素的最后一个元素

int main()
{
     vector<int> vec;
     vec.push_back(11);
     vec.push_back(22);
     vec.push_back(33);
     vec.push_back(22);
     vec.push_back(11);

     int num = 11;
     cout << "Enter a number to find: ";
     cin >> num;
     auto it1 = find(vec.begin(), vec.end(), num);
     auto it2 = find(vec.rbegin(), vec.rend(), num);
     if(it1 != vec.end())
     {
        cout << "Found " << num << " at position " << it1 - vec.begin()
            << " going forward." << endl;
        cout << "Found " << num << " at position "
            << it2.base() - 1 - vec.begin() << " going backward." << endl;
     }
     cout << "Failed to find " << num << endl;

    return 0;
}
