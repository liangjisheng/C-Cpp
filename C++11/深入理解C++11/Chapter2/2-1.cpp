#include <iostream>

using namespace std;

const char* hello() { return __func__; }
const char* world() { return __func__; }

struct TestStruct
{
    TestStruct() : name(__func__) {}
    const char *name;
};

int main()
{
    // 预定义宏
    cout << "Standard Clib: " << __STDC_HOSTED__ << endl;   // 1
    cout << "Standard C: " << __STDC__ << endl;             // 1
    // cout << "C Standard version: " << __STDC_VERSION__ << endl;
    // cout << "ISO/IEC " << __STDC_ISO_10646__ << endl;

    cout << hello() << ", " << world() << endl;     // hello, world

    TestStruct ts;
    cout << ts.name << endl;        // TestStruct

    return 0;
}
