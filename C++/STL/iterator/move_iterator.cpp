#include <iostream>
#include <vector>

using namespace std;

class MoveableClass
{
public:
    MoveableClass(){
        cout << "Default constructor" << endl;
    }
    MoveableClass(const MoveableClass& src){
        cout << "Copy constructor" << endl;
    }
    MoveableClass(MoveableClass&& src) noexcept {
        cout << "Move constructor" << endl;
    }
    MoveableClass& operator=(const MoveableClass& rhs){
        cout << "Copy assignment operator" << endl;
        return *this;
    }
    MoveableClass& operator=(MoveableClass&& rhs) noexcept {
        cout << "Move assignment operator" << endl;
        return *this;
    }
    virtual ~MoveableClass(){
        cout << "deconstructor" << endl;
    }
};


int main()
{
    vector<MoveableClass> vec;
    MoveableClass mc;

    // 当vec中空间不够是，会分配更多的内存，将原来的使用
    // 移动复制构造函数移动到新的空间里
    vec.push_back(mc);
    vec.push_back(mc);
    //vec.push_back(mc);
    //vec.push_back(mc);
    cout << endl;

    // 使用移动复制操作符之后，不可以在访问vec中的元素
    // vec中的元素会自动调用析构函数
    vector<MoveableClass> vec1(make_move_iterator(vec.begin()),
                               make_move_iterator(vec.end()));

    cout << endl;

    return 0;
}
