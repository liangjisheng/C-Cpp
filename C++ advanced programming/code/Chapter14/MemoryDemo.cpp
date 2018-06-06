
#include <iostream>
#include "MemoryDemo.h"
using std::cout;
using std::endl;
using std::nothrow_t;

// 重载版本的 new delete 调用了运算符的全局版本

void* MemoryDemo::operator new(size_t Size)
{
    cout << "operator new" << endl;
    return ::operator new(Size);
}

void MemoryDemo::operator delete(void* ptr) noexcept
{
    cout << "operator delete" << endl;
    ::operator delete(ptr);
}

// 带额外参数版本的 new delete
void* MemoryDemo::operator new(size_t Size,int extra)
{
    cout << "operator new with extra int arg: " << extra << endl;
    return ::operator new(Size);
}

void MemoryDemo::operator delete(void* ptr,int extra) noexcept
{
    cout << "operator delete with extra int arg: " << extra << endl;
    ::operator delete(ptr);
}

void* MemoryDemo::operator new[](size_t Size)
{
    cout << "operator new[]" << endl;
    return ::operator new[](Size);
}

void MemoryDemo::operator delete[](void* ptr) noexcept
{
    cout << "operator delete[]" << endl;
    ::operator delete[](ptr);
}

void* MemoryDemo::operator new(size_t Size,const nothrow_t& noThrow) noexcept
{
    cout << "operator new nothrow" << endl;
    return ::operator new(Size,noThrow);
}

void MemoryDemo::operator delete(void* ptr,const nothrow_t& noThrow) noexcept
{
    cout << "operator delete nothrow" << endl;
    ::operator delete(ptr,noThrow);
}

void* MemoryDemo::operator new[](size_t Size,const nothrow_t& noThrow) noexcept
{
    cout << "operator new[] nothrow" << endl;
    return ::operator new[](Size,noThrow);
}

void MemoryDemo::operator delete[](void* ptr,const nothrow_t& noThrow) noexcept
{
    cout << "operator delete[] nothrow" << endl;
    ::operator delete[](ptr,noThrow);
}
