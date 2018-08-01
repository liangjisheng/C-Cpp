#include <iostream>
#include <ratio>
// 有理数，都是编译时常量

using namespace std;

int main()
{
    // Define a compile-time rational number
    typedef ratio<1, 60> r1;
    cout << "1) " << r1::num << "/" << r1::den << endl;
    // Get numerator and denominator    获取分子和分母
    intmax_t num = r1::num;
    intmax_t den = r1::den;
    cout << "2) " << num << "/" << den << endl;

    // another rational number
    typedef ratio<1, 30> r2;
    cout << "3) " << r2::num << "/" << r2::den << endl;
    typedef ratio_add<r1, r2>::type result;
    cout << "4) " << result::num << "/" << result::den << endl;
    // compare two rational numbers
    typedef ratio_less<r2, r1>  res;
    cout << "5) " << boolalpha << res::value << endl;

    return 0;
}
