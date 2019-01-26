
// ����ʹ��ģ��ݹ��д������Nά������Ϊ�����ά�ȱ�������
// �ݹ�ģ����Ա�дһ��ģ�����Զ����еݹ顣�������´���Nά����
// NDGrid<int, 1> singleDGrid;
// NDGrid<int, 2> twoDGrid;
// NDGrid<int, 3> threeDGrid;
// ����ؼ��������ڣ�NDGrid��Ԫ�����Ͳ���ģ������б���ָ����
// Ԫ�����ͣ�������һ��ݹ��ά����ָ�������͡����仰˵��
// ��ά�����Ƕ�ά�����ʸ������ά������һά�����ʸ��
// ʹ�õݹ�ʱ����Ҫһ����������(base case).���Ա�дά��Ϊ1�Ĳ���
// �ػ���NDGrid������Ԫ�����Ͳ�����һ��NDGrid,����ģ�����ָ����
// Ԫ������

#include <iostream>
#include <vector>
#include <cstddef>

using std::cout;
using std::endl;
using std::vector;

// ������ģ�嶨���һ����ʽ
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


// ģ��ݹ�ʵ����ֵĲ��ֲ���ģ��ݹ鱾����������ÿ��ά��
// ����ȷ��С�����ʵ�ִ�����Nά����ÿ��ά�ȶ���һ����ġ�
// Ϊÿ��ά��ָ����ͬ�Ĵ�СҪ���ѵĶࡣȻ������ʹ�������ļ�
// ��Ȼ����һ�����⣺�û�Ӧ������������ָ����С�����飬����20��
// 50.��ˣ����캯������һ��������С������Ȼ������ָ̬��������
// ʸ���Ĵ�С�ǣ����ܽ������Сֵ���ݸ�������Ԫ�أ���Ϊʸ��ʹ��
// Ĭ�Ϲ��캯������������˱����ʸ����ÿ������Ԫ����ʽ����
// reSize(),�������β���Ҫ������Ŀ����Ϊ�������ε�Ԫ����T,����������

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




// �������ε�ģ�嶨����ά��Ϊ1�Ĳ�����������
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


// �����ǲ�����������ʵ�ֲ���(��������)����ע�⣬������д�ܶ�
// ���룬��Ϊ�������������м̳��κ�ʵ��

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


