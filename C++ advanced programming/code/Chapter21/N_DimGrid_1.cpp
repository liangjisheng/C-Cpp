
// 可以使用模板递归编写真正的N维网格，因为网格的维度本质上是
// 递归的，可以编写一个模板类自动进行递归。可以如下创建N维网格
// NDGrid<int, 1> singleDGrid;
// NDGrid<int, 2> twoDGrid;
// NDGrid<int, 3> threeDGrid;
// 这里关键问题在于，NDGrid的元素类型不是模板参数列表中指定的
// 元素类型，而是上一层递归的维度中指定的类型。换句话说，
// 三维网格是二维网格的矢量；二维网格是一维网格的矢量
// 使用递归时，需要一个基本情形(base case).可以编写维度为1的部分
// 特化的NDGrid，其中元素类型不是另一个NDGrid,而是模板参数指定的
// 元素类型

#include <iostream>
#include <vector>
#include <cstddef>

using std::cout;
using std::endl;
using std::vector;

// 下面是模板定义的一般形式
template<typename T, size_t N>
class NDGrid
{
public:
    explicit NDGrid(size_t inSize = kDefaultSize);
    virtual ~NDGrid();

    NDGrid<T, N - 1>& operator[](size_t x);
    const NDGrid<T, N - 1>& operator[](size_t x) const;

    void reSize(size_t newSize);
    size_t getSize() const { return mElems.size(); }
    static const size_t kDefaultSize = 10;

private:
    std::vector<NDGrid<T, N - 1> > mElems;
};


// 模板递归实现最棘手的部分不是模板递归本身，而是网格每个维度
// 的正确大小。这个实现创建了N维网格，每个维度都是一样大的。
// 为每个维度指定不同的大小要困难的多。然而，即使是这样的简化
// 仍然存在一个问题：用户应该有能力创建指定大小的数组，例如20或
// 50.因此，构造函数接受一个整数大小参数。然而当动态指定子网格
// 矢量的大小是，不能讲这个大小值传递给子网格元素，因为矢量使用
// 默认构造函数创建对象，因此必须对矢量的每个网格元素显式调用
// reSize(),基本情形不需要调整数目，因为基本情形的元素是T,而不是网格

template<typename T, size_t N>
NDGrid<T, N>::NDGrid(size_t inSize)
{
    reSize(inSize);
}


template<typename T, size_t N>
NDGrid<T, N>::~NDGrid()
{
    // Nothing to do.the vector will clean up itself.
}


template<typename T, size_t N>
void NDGrid<T, N>::reSize(size_t newSize)
{
    mElems.resize(newSize);
    for(auto& ele : mElems)
        ele.reSize(newSize);
}


template<typename T, size_t N>
NDGrid<T, N - 1>& NDGrid<T, N>::operator[](size_t x)
{
    return mElems[x];
}


template<typename T, size_t N>
const NDGrid<T, N - 1>& NDGrid<T, N>::operator[](size_t x) const
{
    return mElems[x];
}




// 基本情形的模板定义是维度为1的部分特例化：
template<typename T>
class NDGrid<T, 1>
{
public:
    explicit NDGrid(size_t inSize = kDefaultSize);
    virtual ~NDGrid();

    T& operator[](size_t x);
    const T& operator[](size_t x) const;

    void reSize(size_t newSize);
    size_t getSize() const { return mElems.size(); }
    static const size_t kDefaultSize = 10;

private:
    std::vector<T> mElems;
};


// 下面是部分特例化的实现部分(基本情形)，请注意，必须重写很多
// 代码，因为不能在特例化中继承任何实现

template<typename T>
NDGrid<T, 1>::NDGrid(size_t inSize)
{
    reSize(inSize);
}


template<typename T>
NDGrid<T, 1>::~NDGrid()
{
    // Nothing to do, the vector will clean up itself.
}


template<typename T>
void NDGrid<T, 1>::reSize(size_t newSize)
{
    mElems.resize(newSize);
}


template<typename T>
T& NDGrid<T, 1>::operator[](size_t x)
{
    return mElems[x];
}


template<typename T>
const T& NDGrid<T, 1>::operator[](size_t x) const
{
    return mElems[x];
}



int main()
{
    NDGrid<int, 3> my3DGrid;
    my3DGrid[2][1][2] = 5;
    my3DGrid[1][1][1] = 5;
    cout << my3DGrid[2][1][2] << endl;

    return 0;
}


