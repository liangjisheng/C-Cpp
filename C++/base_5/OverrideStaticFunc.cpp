#include <iostream>

using namespace std;

// 在C++中，不能重写静态方法，方法不可能及时静态的又是虚的。
// 试图重写一个静态方法得到的结果并非预期，如果派生类中存在
// 的静态方法与基类中的静态方法同名，实际上这是两个独立的方法

class SuperStatic{
public:
    static void beStatic(){
        cout << "SuperStatic being static." << endl;
    }
};

class SubStatic : public SuperStatic {
public:
    static void beStatic() {
        cout << "SubStatic keepin it static." << endl;
    }
};

int main()
{
    SubStatic mySubStatic;
    SuperStatic& ref1 = mySubStatic;
    mySubStatic.beStatic();
    ref1.beStatic();

    SuperStatic::beStatic();
    SubStatic::beStatic();

    return 0;
}
