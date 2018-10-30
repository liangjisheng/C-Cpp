#include <cassert>
#include <cstring>

using namespace std;

template <typename T, typename U>
int bit_copy(T& a, U& b)
{
    assert(sizeof(a) == sizeof(b));
    memcpy(&a, &b, sizeof(b));
    return 0;
}

// 自定义静态断言
#define assert_static(e)\
    do {\
    enum { assert_static__ = 1 / (e) };\
    } while (0)

template <typename T, typename U>
int bit_copy_1(T& a, U& b)
{
    assert_static(sizeof(a) == sizeof(b));
    memcpy(&a, &b, sizeof(b));
    return 0;
}

// C++11标准中的static_assert断言
template <typename T, typename U>
int bit_copy_2(T& a, U& b)
{
    static_assert(sizeof(a) == sizeof(b),
                  "the parameter of bit_copy_2 must have same width.");
    memcpy(&a, &b, sizeof(b));
    return 0;
}


int main()
{
    int a = 0x2468;
    double b;
    bit_copy(a, b);
    // bit_copy_1(a, b);
    bit_copy_2(a, b);
}
