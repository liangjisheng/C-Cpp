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

// C++11中使用了用嵌套异常
// 当处理第一个异常，且需要抛出嵌套了第一个异常的第二个异常时，需要
// 使用std::throw_with_nested()函数。下面的doSomething()函数抛出了
// 一个异常，这个异常立即被处理程序捕获，然后捕获程序使用throw_with_nested()
// 函数抛出了第二个异常，第一个异常嵌套在其中，嵌套异常是自动实现的

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
