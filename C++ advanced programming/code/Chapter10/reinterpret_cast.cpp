#include <iostream>

using namespace std;

class X{};
class Y{};

int main()
{
    X x;
    Y y;
    X* xp = &x;
    Y* yp = &y;
    // Need reinterpret_cast for pointer conversion from unrelated classes
    // static_cast does not work.
    xp = reinterpret_cast<X*>(yp);
    // No cast required for conversion from pointer to void*
    void* p = xp;
    // Need reinterpret_cast for pointer conversion from void*
    xp = reinterpret_cast<X*>(p);
    // Need reinterpret_cast for reference conversion from unrelated classes
    // static_cast does not work
    X& xr = x;
    Y& yr = reinterpret_cast<Y&>(x);

    // ʹ��reinterpret_castʱҪ�ر�С�ģ���Ϊ��ִ��ת���ǲ���ִ���κ����ͼ��

    return 0;
}
