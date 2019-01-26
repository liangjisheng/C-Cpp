#include <iostream>
#include <stdexcept>
using namespace std;

class myException : public exception
{
public:
    myException(const char* msg) : mMsg(msg) {}
    virtual ~myException() noexcept {}
    virtual const char* what() const noexcept override
    { return mMsg.c_str(); }
private:
    string mMsg;
};

// C++11��ʹ������Ƕ���쳣
// �������һ���쳣������Ҫ�׳�Ƕ���˵�һ���쳣�ĵڶ����쳣ʱ����Ҫ
// ʹ��std::throw_with_nested()�����������doSomething()�����׳���
// һ���쳣������쳣������������򲶻�Ȼ�󲶻����ʹ��throw_with_nested()
// �����׳��˵ڶ����쳣����һ���쳣Ƕ�������У�Ƕ���쳣���Զ�ʵ�ֵ�

void doSomething()
{
    try{
        throw runtime_error("Throwing a runtime_error exception");
    }catch(const runtime_error& e){
        cout << __func__ << " caught a runtime_error" << endl;
        cout << __func__ << " throwing myException" << endl;
        std::throw_with_nested(
            myException("myException with nested runtime_error"));
    }
}


int main()
{
    try{
        doSomething();
    }catch(const myException& e){
        cout << __func__ << " caught myException: " << e.what() << endl;
        const nested_exception* pNested =
            dynamic_cast<const nested_exception*>(&e);
        if(pNested){
            try{
                pNested->rethrow_nested();
            }catch(const runtime_error& e){
                // Handle nested exception
                cout << " Nested exception: " << e.what() << endl;
            }
        }
    }

    return 0;
}
