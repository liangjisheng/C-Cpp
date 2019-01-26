
namespace std
{
    template<class T>
    inline void swap(T& a,T& b){
        T tmp(a);
        a = b;
        b = tmp;
    }
}

class MyContainer {
private:
    int* elems;     // dynamic array of elements
    int numElmes;   // number of elements
public:
    // ...
    // implementation of swap()
    void swap(MyContainer& X) {
        std::swap(elems,X.elems);
        std::swap(numElmes,X.numElmes);
    }
    // ...
};

// overloaded global swap() for this type
inline void swap(MyContainer& c1,MyContainer& c2)
{
    c1.swap(c2);    // call implementation of swap()
}

// ����swap()����������������ֵ�������Ч���ϵ�����

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
