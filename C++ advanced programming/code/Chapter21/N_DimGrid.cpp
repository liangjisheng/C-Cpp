
#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::vector;

// N维网格的编写
// 如果想编写一个三维或者更高维的网格程序
// 可以为每个维度写一个模板或非模板类，然而这会重复很多代码
// 另一种方法是只编写一个一维网格。然后利用另一个Grid作为
// 元素类型实例化Grid,可以创建任意维度Grid.

template<typename T>
class OneDGrid
{
public:
    explicit OneDGrid(size_t inSize = kDefaultSize);
    virtual ~OneDGrid();

    T& operator[](size_t x);
    const T& operator[](size_t x) const;

    void reSize(size_t newSize);
    size_t getSize() const { return mElems.size(); }
    static const size_t kDefaultSize = 10;

    void display() const;

private:
    std::vector<T> mElems;
    void initialization();
};


template<typename T>
OneDGrid<T>::OneDGrid(size_t inSize)
{
    mElems.resize(inSize);
}


template<typename T>
void OneDGrid<T>::initialization()
{
    for(size_t i = 0; i < mElems.size(); ++i)
        mElems[i] = T();
}


template<typename T>
OneDGrid<T>::~OneDGrid()
{
    // Nothing to do, the vector will clean up itself.
}


template<typename T>
T& OneDGrid<T>::operator[](size_t x)
{
    return mElems[x];
}


template<typename T>
const T& OneDGrid<T>::operator[](size_t x) const
{
    return mElems[x];
}


template<typename T>
void OneDGrid<T>::display() const
{
    for(size_t i = 0; i < mElems.size(); ++i)
        std::cout << mElems[i] << ' ';
    std::cout << std::endl;
}



int main()
{
    // 一维网格
    OneDGrid<int> singleDGrid;
    // 二维网格
    OneDGrid<OneDGrid<int> > twoDGrid;
    // 三维网格
    OneDGrid<OneDGrid<OneDGrid<int> > > threeDGrid;

    singleDGrid[3] = 5;
    twoDGrid[3][3] = 5;
    threeDGrid[3][3][3] = 5;

    // 前面定义的输出只能用于一维网格，
    singleDGrid.display();

    cout << twoDGrid[3][3] << endl;
    cout << threeDGrid[3][3][3] << endl;

    return 0;
}


