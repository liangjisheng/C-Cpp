// share_ptr相互引用问题示例
#include <iostream>
#include <memory>

using namespace std;

class TestB;
class TestA
{
public:
    TestA() { cout << "TestA()" << endl; }
    void ReferTestB(std::shared_ptr<TestB> test_ptr) { m_TestB_ptr = test_ptr; }
    ~TestA() { cout << "~TestA()" << endl; }
private:
    std::shared_ptr<TestB> m_TestB_ptr;     // TestB的智能指针
};

class TestB
{
public:
    TestB() { cout << "TestB()" << endl; }
    void ReferTestA(std::shared_ptr<TestA> test_ptr) { m_TestA_ptr = test_ptr; }
    ~TestB() { cout << "~TestB()" << endl; }
private:
    std::shared_ptr<TestA> m_TestA_ptr;     // TestA的智能指针
};


int main()
{
    shared_ptr<TestA> ptr_a = make_shared<TestA>();
    shared_ptr<TestB> ptr_b = make_shared<TestB>();
    ptr_a->ReferTestB(ptr_b);
    ptr_b->ReferTestA(ptr_a);

    // 最后ptr_a和ptr_b的引用计数都是2，无法调用析构函数，导致内存泄漏

    return 0;
}
