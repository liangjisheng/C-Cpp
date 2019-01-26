
#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::vector;

// Nά����ı�д
// ������дһ����ά���߸���ά���������
// ����Ϊÿ��ά��дһ��ģ����ģ���࣬Ȼ������ظ��ܶ����
// ��һ�ַ�����ֻ��дһ��һά����Ȼ��������һ��Grid��Ϊ
// Ԫ������ʵ����Grid,���Դ�������ά��Grid.

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
    // һά����
    OneDGrid<int> singleDGrid;
    // ��ά����
    OneDGrid<OneDGrid<int> > twoDGrid;
    // ��ά����
    OneDGrid<OneDGrid<OneDGrid<int> > > threeDGrid;

    singleDGrid[3] = 5;
    twoDGrid[3][3] = 5;
    threeDGrid[3][3][3] = 5;

    // ǰ�涨������ֻ������һά����
    singleDGrid.display();

    cout << twoDGrid[3][3] << endl;
    cout << threeDGrid[3][3][3] << endl;

    return 0;
}


