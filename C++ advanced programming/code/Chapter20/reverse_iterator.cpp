#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

// forward_list�������������������reverse_iterator
// ���������rbegin()����ָ�����������һ��Ԫ�ص�
// reverse_iterator, rend()����ָ�������е�һ��Ԫ��֮ǰ��Ԫ��
// reverse_iterator.base()�������ñ�����reverse_iterator
// ���õ�Ԫ�ص����һ��Ԫ��

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
