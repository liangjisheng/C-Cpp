#include <iostream>
#include <vector>
#include <functional>

using namespace std;

// std::function 是一个多态的函数对象包装，类似于函数指针。
// 可以绑定至任何能调用的对象(仿函数，成员函数指针，函数指针
// 和lambda表达式)，只要参数和返回类型符合包装的类型即可。

function<int(void)> multiplyBy2lambda(int x)
{
    // multiplyBy2lambda的返回类型为function<int(void)>
    // 即：不接受参数并返回一个整数的函数，在lambda表达式从
    // 函数返回前，x值的副本绑定至lambda表达式中的x
    return [x] { return 2 * x; };
}


// 可以编写接受lambda表达式作为参数的函数，可通过这种方式
// 实现回调函数
void testCallBack(const vector<int>& vec,
                  const function<bool(int)>& callback)
{
    for(const auto& i : vec) {
        // Call callback. If it returns false,stop iteration.
        if(!callback(i))
            break;
        // Callback did not stop iteration.so print value
        cout << i << " ";
    }
    cout << endl;
}


int main()
{
    function<int(void)> fn = multiplyBy2lambda(5);
    cout << fn() << endl;


    // test callback
    vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    testCallBack(vec,[](int i) { return i < 6;} );

    return 0;
}
