#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function template to populate(填充) a container of ints.
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
    // transform()算法对一个范围中的每个元素应用回调，期望回调
    // 生成一个新元素，并保存在指定的目标范围中。源范围和目标范围
    // 可以是同一范围
    vector<int> myVec;
    populateContainer(myVec);

    cout << "The vector contents are: " << endl;
    for(const auto& i : myVec)
        cout << i << " ";
    cout << endl;

    transform(myVec.begin(), myVec.end(), myVec.begin(),
              [](int i){ return i + 100; });

    cout << "The vector contents are: " << endl;
    for(const auto& i : myVec)
        cout << i << " ";
    cout << endl;



    // transform()的另外一种形式对范围中的元素对调用二元函数，
    // 需要第一个范围的首尾迭代器、第二个范围的首迭代器和模板
    // 范围的首迭代器作为参数。
    // 创建两个vector，然后通过transform()计算元素对的和，
    // 并将结果保存会第一个vector中
    vector<int> vec1;
    cout << "Vector1: " << endl;
    populateContainer(vec1);

    vector<int> vec2;
    cout << "Vector2: " << endl;
    populateContainer(vec2);

    if(vec2.size() < vec1.size())
    {
        cout << "Vector2 should be at least the same size as vector1." << endl;
        return 1;
    }

    // Create a lambda to print a container
    auto printContainer = [](const vector<int>& container){
        for(auto& i : container)
            cout << i << ' ';
        cout << endl;
    };

    cout << "Vector1: ";
    printContainer(vec1);
    cout << "Vector2: ";
    printContainer(vec2);

    // 第一个和第二个参数指明了源范围，第三个参数指明了目标范围，
    // 最后一个参数指明需要将转换结果保存在哪里
    // transform()和其它修改算法通常返回一个应用目标范围最后一个值
    // 后一个位置(past-the-end)的迭代器
    transform(vec1.begin(), vec1.end(), vec2.begin(), vec1.begin(),
              [](int a,int b){ return a + b;});

    cout << "Vector1: ";
    printContainer(vec1);
    cout << "Vector2: ";
    printContainer(vec2);

    return 0;
}
