
#include <iostream>
#include "MemoryDemo.h"
using std::cout;
using std::endl;
using std::nothrow_t;

// ���ذ汾�� new delete �������������ȫ�ְ汾

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

// ����������汾�� new delete
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
