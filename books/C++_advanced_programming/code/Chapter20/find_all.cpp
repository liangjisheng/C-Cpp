#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

// ��дfind_all()��������ָ����Χ���ҵ�����ĳ��ν�ʵ�����Ԫ��
template<typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator find_all(InputIterator first, InputIterator last,
                        OutputIterator dest, Predicate pred)
{
    while(first != last){
        if(pred(*first)){
            *dest = first;
            ++dest;
        }
        ++first;
    }
    return dest;
}

int main()
{
    vector<int> vec{3, 4, 5, 4, 5, 6, 5, 8 };
    vector<vector<int>::iterator> matches;
    find_all(vec.begin(), vec.end(), back_inserter(matches),
             [](int i){ return i == 5; });
    cout << "Found " << matches.size() << " matching elements: " << endl;

    for(auto it : matches)
        cout << *it << " at position " << (it - vec.cbegin()) << endl;

    return 0;
}
