#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class SumAndProd
{
public:
    SumAndProd() : mSum(0), mProd(1) {}
    void operator()(int elem);
    int getSum() const { return mSum; }
    int getProduct() const { return mProd; }
private:
    int mSum;
    int mProd;
};

void SumAndProd::operator()(int elem)
{
    mSum += elem;
    mProd *= elem;
}

int main()
{
    map<int, int> myMap = { {4,40}, {5,50}, {6,60} };
    for_each(myMap.cbegin(), myMap.cend(),
             [](const pair<int, int>& p) { cout << p.first << "->" << p.second << endl;});


    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    int sum = 0;
    int prod = 1;
    for_each(vec.cbegin(), vec.cend(),
             [&sum, &prod](int i){
                sum += i;
                prod *= i;
             });

    cout << "The sum is :" << sum << endl;
    cout << "The product is :" << prod << endl;


    // 求连乘与求和除了可以用lambda表达式,也可以用仿函数
    SumAndProd func;
    // 仿函数移入for_each(),最终会移出for_each(),
    // 为了获得正确的行为，必须捕捉返回值
    func = for_each(vec.cbegin(), vec.cend(), func);
    cout << "The sum is :" << func.getSum() << endl;
    cout << "The product is :" << func.getProduct() << endl;

    return 0;
}
