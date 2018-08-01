#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    auto basiclambda = []{ cout << "hello from lambda" << endl; };
    // 普通函数调用语法调用lambda 表达式
    basiclambda();

    // 接受参数的 lambda 表达式，如果不接受参数，可以使用空圆括号或忽略括号
    auto parameters =
        [](int value) { cout << "The value is :" << value << endl; };
    parameters(2);

    // 拖尾返回类型
    auto returninglambda = [](int a, int b) -> int { return a + b; };
    cout << returninglambda(11,22) << endl;

    // lambda 表达式可以在其作用域内捕捉变量
    double data = 1.23;
    // 只写变量名，表示按值捕捉
    auto capturinglambda = [data] { cout << "Data = " << data << endl; };
    capturinglambda();

    const double cData = 2.34;
    auto cCapturinglambda =
        [cData] { cout << "const Data = " << cData << endl; };
    cCapturinglambda();


    // 对于lambda表示式，这个函数调用运算符默认标记为const,
    // 这表示，即使在lambda表达式中按值捕捉了非const变量，
    // lambda也不能修改其副本。把lambda表达式指定为mutable,
    // 就可以把函数调用运算符标记为非const
    double d1 = 3.45;
    auto capturinglambda_1 =
        [d1] () mutable { d1 *= 2; cout << "Data = " << d1 << endl; };
    capturinglambda_1();
    // 如果指定了mutable,就必须给参数指定圆括号，即使圆括号为空，也是如此


    // 在变量名前加上&,就可以按引用捕捉变量
    double d2 = 4.56;
    auto capturinglambda_2 =
        [&d2] { d2 *= 2; cout << "Data2 = " << d2 << endl; };
    capturinglambda_2();


    // [=]: 通过值捕捉所有变量
    // [&]: 通过引用捕捉作用域中的所有变量
    // [&x]: 只通过应用捕捉x，不捕捉其它变量
    // [x]: 只通过值捕捉x，不捕捉其它变量
    // [=,&x,&y]: 默认通过值捕捉，变量x和变量y例外，通过引用捕捉
    // [&,x]: 默认通过引用捕捉，变量x例外，通过值捕捉
    // [&x,&x]: 非法，标识符不允许重复。
    // [this]: 捕捉周围对象。即使没有使用this->，也可以在lambda表达式
    // 中访问这个对象。
    // 即使可行，也不建议在内部作用域中使用[=],[&],或默认捕捉所有变量
    // 而应选择捕捉需要的变量。


    // 从C++14开始，lambda表达式的参数就有自动推断类型功能，无需显示指定
    vector<int> Ints{11,55,101,155};
    vector<double> Doubles{11.1,55.5,101.1,155.5};

    auto isGreaterThan100 = [](auto i) { return i > 100; };

    auto it1 = find_if(Ints.begin(),Ints.end(),isGreaterThan100);
    if(it1 != Ints.end()){
        cout << "Found a value > 100 : " << *it1 << endl;
    }

    auto it2 = find_if(Doubles.begin(),Doubles.end(),
                       isGreaterThan100);
    if(it2 != Doubles.end()) {
        cout << "Found a value > 100 : " << *it2 << endl;
    }

    return 0;
}
