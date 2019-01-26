#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function template to populate(Моід) a container of ints.
// The container must support push_back().
template<typename Container>
void populateContainer(Container& cont)
{
    int num;
    while(true)
    {
        cout << "Enter a number (0 to quit): ";
        cin >> num;
        if(0 == num)
            break;
        cont.push_back(num);
    }
}

int main()
{
    vector<int> vec1, vec2;
    populateContainer(vec1);
    vec2.resize(vec1.size());

    // copy_if()返回目标范围中最后一个复制的元素后一个位置的迭代器，
    // 以便确定需要从目标容器中删除的元素个数
    auto endIt = copy_if(vec1.cbegin(), vec1.cend(),
                         vec2.begin(), [](int i) { return i % 2 == 0; });
    vec2.erase(endIt, vec2.end());

    cout << "Vector2: ";
    for(const auto& i : vec2)
        cout << i << ' ';
    cout << endl;

    return 0;
}
