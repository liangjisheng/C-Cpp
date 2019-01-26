#ifndef MEMORYDEMO_H_INCLUDED
#define MEMORYDEMO_H_INCLUDED

// 重载特定类的 operator new 和 operator delete,仅当分配或释放
// 特定类的对象是，才会调用这些重载的运算符
// 下面重载了4个非 placement 形式的 operator new ,operator delete

#include <new>

class MemoryDemo
{
public:
    MemoryDemo() { }
    virtual ~MemoryDemo() {}

    void* operator new(std::size_t Size);
    void operator delete(void* ptr) noexcept;

    // 除了重载标准形式的operator new 之外，还可以编写带额外参数的
    // 的版本
    void* operator new (std::size_t Size,int extra);
    void operator delete(void* ptr,int extra) noexcept;

    void* operator new[](std::size_t Size);
    void operator delete[](void* ptr) noexcept;

    void* operator new(std::size_t Size,const std::nothrow_t&) noexcept;
    void operator delete(void* ptr,const std::nothrow_t&) noexcept;

    void* operator new[](std::size_t Size,const std::nothrow_t&) noexcept;
    void operator delete[](void* ptr,const std::nothrow_t&) noexcept;
};

#endif // MEMORYDEMO_H_INCLUDED
