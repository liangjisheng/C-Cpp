

namespace std{

    // 下面这四个操作符，都是利用操作符==和<完成的
    // 这四个函数定义与<utility>
    namespace rel_ops{
        template <class T>
        inline bool operator != (const T& x, const T& y) {
            return !(x == y);
        }

        template <class T>
        inline bool operator > (const T& x, const T& y) {
            return y < x;
        }

        template <class T>
        inline bool operator <= (const T& x, const T& y) {
            return !(y < x);
        }

        template <class T>
        inline bool operator >= (const T& x, const T& y) {
            return !(x < y);
        }
    }

    template <class T>
    inline const T& min(const T& a,const T& b){
        return b < a ? b : a;
    }

    template <class T>
    inline const T& max(const T& a,const T& b){
        return a < b ? b : a;
    }

    // 上述两个函数还有另外一个版本,接收一个额外的template参数,作为“比较准则”
    // 作为比较准则，应该是个函数或者仿函数
    template <class T,class Compare>
    inline const T& min(const T& a,const T& b,Compare comp) {
        return comp(b,a) ? b : a;
    }

    template <class T,class Compare>
    inline const T& max(const T& a,const T& b,Compare comp){
        return comp(a,b) ? b : a;
    }
}



#include <iostream>
#include <algorithm>
using namespace std;

bool int_ptr_less (int* a, int* b)
{
    return *a < *b;
}

bool int_less (int a, int b)
{
    return a < b;
}


int main()
{
    int x = 17;
    int y = 42;
    int* px = &x;
    int* py = &y;
    int* pmax;
    int int_max;

    pmax = max(px,py,int_ptr_less);
    int_max = max(x,y,int_less);

    cout<<*pmax<<endl;
    cout<<int_max<<endl;

    long l = 10;
    int i = 9;
    // l = std::max(i,l);      // 使用时参数类型必须一致 ERROR；argument types don't match

    l = std::max<long>(i,l);    // OK,隐式类型转换

    return 0;
}
