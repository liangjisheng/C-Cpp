#include <iostream>

using namespace std;

template <typename T>
struct Type {
    void operator()() { cout << "未知类型" << endl; }
};

// int specialize特化
template <>
struct Type <int> {
    void operator()() { cout << "int" << endl; }
};

// short specialize
template<>
struct Type<short> {
    void operator()() { cout << "short" << endl; }
};

// long specialize
template<>
struct Type<long> {
    void operator()() { cout << "long" << endl; }
};

// float specialize
template<>
struct Type<float> {
    void operator()() { cout << "float" << endl; }
};

// double specialize
template<>
struct Type<double>{
    void operator()() { cout << "double" << endl; }
};


// ----------------------------------------------------
template <typename T>
class IsClassT{
    typedef char One;
    typedef struct { char ch[2]; } Two;

    template<typename C>
    static One test(int C::*);      // 不定义也可以

    template<typename C>
    static Two test(...);           // 不定义也可以

public:
    enum { Yes = sizeof(test<T>(0)) == 1 };
    enum { No = !Yes };
};


// ------------------------------------------------------
template <typename T>
void check()
{
    if(IsClassT<T>::Yes)
        cout << "class" << endl;
    else
        Type<T>()();
}

template <typename T>
void check(const T&) {
    check<T>();
}


// test template
class A{};
union B{};
enum C{};


int main()
{
    A a;
    B b;
    C c;
    int d;
    check(a);
    check(b);
    check(c);
    check(d);
    check(3.14f);
    check(6.24);

    return 0;
}
