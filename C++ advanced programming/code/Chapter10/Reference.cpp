#include <iostream>

using namespace std;

// ����Ĭ��Ϊconst,�޷��ı�������ָ����

// ��������ʱ������Ĵ�С������һ���������ʽ��
// const int getArraySize() { return 32; }

// ����ʹ��constexpr�ؼ����¶���getArraySize()������
// ������ɳ������ʽ���������ʽ�ڱ����Ǽ��㡣
constexpr int getArraySize() { return 32; }

// ͨ������constexpr���캯�������Դ����û��Զ������͵ĳ���
// ���ʽ������constexpr���캯��Ӧ������һ��Ҫ��:
// ���캯�������в�����Ӧ��������������
// ���캯���岻Ӧ����function-try-block
// ���캯��Ӧ��������constexpr������ͬ��Ҫ��
// �������ݳ�Ա��Ӧ���ó������ʽ��ʼ��
class Rect{
public:
    constexpr Rect(int width,int height)
    : mWidth(width),mHeight(height) {}
    constexpr int getArea() const { return mWidth * mHeight; }
private:
    int mWidth,mHeight;
};

int main()
{
    //int& unnamedRef1 = 5;               // Does not compile
    const int& unnamedRef2 = 7;         // Work

    // ���Դ����κ����͵����ã�����ָ������
    int* intP;
    int*& ptrRef = intP;
    ptrRef = new int;
    *ptrRef = 5;

    // ������ȡ��ַ�Ľ����Ա����ñ���ȥ��ַ�Ľ����ͬ
    // �޷��������õ����ã�����ָ�����õ�ָ��

    // int myArray[getArraySize()];         // Invalid in C++
    int myArray[getArraySize()];            // OK

    constexpr Rect r(8,2);
    int myArray1[r.getArea()];              // OK

    return 0;
}
