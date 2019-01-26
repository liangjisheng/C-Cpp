#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template<typename IteratorType>
void iteratorTraitsTest(IteratorType it)
{
    // 一些算法的实现需要迭代器的额外信息，例如，为了保存临时值
    // 算法可能需要知道迭代器引用的元素的类型，还有可能要知道
    // 迭代器是双向访问的还是随机访问的。
    // C++提供了一个iterator_traits的类模板，通过要使用的迭代器
    // 类型实例化iterator_traits类模板，然后可以访问以下5个
    // typedef: value_type、 difference_type、 iterator_category
    // pointer 和 reference
    // typename 说明后面紧跟的是一个类型
    typename std::iterator_traits<IteratorType>::value_type temp;
    temp = *it;
    cout << temp << endl;
}

int main()
{
    vector<int> v{ 5 };
    iteratorTraitsTest(v.cbegin());

    return 0;
}
