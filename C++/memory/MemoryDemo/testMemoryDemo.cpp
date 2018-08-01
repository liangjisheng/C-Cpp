#include <iostream>
#include "MemoryDemo.h"
using namespace std;

int main()
{
    // 调用标准形式 operator  new delete
    MemoryDemo* mem = new MemoryDemo();
    delete mem;

    // 调用标准形式 operator  new[] delete[]
    mem = new MemoryDemo[10];
    delete [] mem;

    // 调用额外参数的 operator  new delete
    mem = new(5) MemoryDemo();
    delete mem;

    mem = new (nothrow) MemoryDemo();
    delete mem;

    mem = new (nothrow) MemoryDemo[10];
    delete [] mem;

    return 0;
}
