#include <iostream>

using namespace  std;

// C++中类的虚表内容由虚函数地址组成，虚表分布在PE文件的.rdata节，
// 并且同一类的所有实例共享同一个虚表。

// __declspec(novtable) 禁止生成虚表，则运行到fun2()时，就会出错
// __declspec(novtable)，我们只能禁止编译器生成虚表，
// 但是不能阻止对象仍包含虚表指针(不能减小对象的大小)，
// 也不能阻止程序对虚表的访问（尽管实际虚表不存在），
// 所以禁止生成虚表只适用于永远不会实例化的类(基类)

// 单继承时父类和子类共用同一虚表指针，而子类的数据
// 被添加在父类数据之后，父类和子类的对象指针在相互转化时值不变。

class /*__declspec(novtable)*/A
{
public:
    void fun1(){ cout << "fun1"<<endl; }
    virtual void fun2() { cout << "fun2"<<endl; }
    virtual ~A() {}

    char m_cA;
    int m_nA;
    static int s_nCount;
};

int A::s_nCount = 0;

int main() 
{
    A* p = new A;
	p->fun1();
	cout<<sizeof(*p)<<endl;
    p->fun2();
	cout<<endl;

    system("pause");
    return 0;
}