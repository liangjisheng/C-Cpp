#include <iostream>
#include "MemoryDemo.h"
using namespace std;

int main()
{
    // ���ñ�׼��ʽ operator  new delete
    MemoryDemo* mem = new MemoryDemo();
    delete mem;

    // ���ñ�׼��ʽ operator  new[] delete[]
    mem = new MemoryDemo[10];
    delete [] mem;

    // ���ö�������� operator  new delete
    mem = new(5) MemoryDemo();
    delete mem;

    mem = new (nothrow) MemoryDemo();
    delete mem;

    mem = new (nothrow) MemoryDemo[10];
    delete [] mem;

    return 0;
}
