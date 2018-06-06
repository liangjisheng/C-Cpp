

namespace std{

    // �������ĸ����������������ò�����==��<��ɵ�
    // ���ĸ�����������<utility>
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

    // ��������������������һ���汾,����һ�������template����,��Ϊ���Ƚ�׼��
    // ��Ϊ�Ƚ�׼��Ӧ���Ǹ��������߷º���
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
    // l = std::max(i,l);      // ʹ��ʱ�������ͱ���һ�� ERROR��argument types don't match

    l = std::max<long>(i,l);    // OK,��ʽ����ת��

    return 0;
}
