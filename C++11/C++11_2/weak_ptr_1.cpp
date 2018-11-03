// weak_ptr解决shared_ptr相互引用问题
// weak_ptr与shared_ptr最大的区别是在赋值时，不会引起智能指针引用计数增加
#include <iostream>
#include <memory>

using namespace std;

class TestB;
class TestA
{
public:
    TestA() { cout << "TestA()" << endl; }
    void ReferTestB(std::shared_ptr<TestB> test_ptr) { m_TestB_ptr = test_ptr; }
    void TestWork() { cout << "~TestA::TestWork()" << endl; }
    ~TestA() { cout << "~TestA()" << endl; }
private:
    std::weak_ptr<TestB> m_TestB_ptr;     // TestB的智能指针
};

class TestB
{
public:
    TestB() { cout << "TestB()" << endl; }
    void ReferTestA(std::shared_ptr<TestA> test_ptr) { m_TestA_ptr = test_ptr; }
    void TestWork() { cout << "~TestB::TestWork()" << endl; }
    ~TestB()
    {
        // 将weak_ptr类型转换成shared_ptr类型，然后对TestA对象进行调用
        std::shared_ptr<TestA> tmp = m_TestA_ptr.lock();
        tmp->TestWork();
        cout << "2 ref a:" << tmp.use_count() << endl;
        cout << "~TestB()" << endl;
    }
private:
    std::weak_ptr<TestA> m_TestA_ptr;     // TestA的智能指针
};


int main()
{
    std::shared_ptr<TestA> ptr_a = std::make_shared<TestA>();
    std::shared_ptr<TestB> ptr_b = std::make_shared<TestB>();
    ptr_a->ReferTestB(ptr_b);
    ptr_b->ReferTestA(ptr_a);
    std::cout << "1 ref a:" << ptr_a.use_count() << std::endl;
    std::cout << "1 ref b:" << ptr_a.use_count() << std::endl;

    return 0;
}
