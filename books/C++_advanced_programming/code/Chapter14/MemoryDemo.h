#ifndef MEMORYDEMO_H_INCLUDED
#define MEMORYDEMO_H_INCLUDED

// �����ض���� operator new �� operator delete,����������ͷ�
// �ض���Ķ����ǣ��Ż������Щ���ص������
// ����������4���� placement ��ʽ�� operator new ,operator delete

#include <new>

class MemoryDemo
{
public:
    MemoryDemo() { }
    virtual ~MemoryDemo() {}

    void* operator new(std::size_t Size);
    void operator delete(void* ptr) noexcept;

    // �������ر�׼��ʽ��operator new ֮�⣬�����Ա�д�����������
    // �İ汾
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
