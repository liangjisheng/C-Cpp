                                   用法
static_cast 静态类型转换           static_cast<type>(expr)
reinterpret_cast 重新解释转换      reinterpret_cast<type>(expr)
const_cast 限定类型转换            const_cast<type>(expr)去掉expr的const或volatile限定
dynaic_cast 动态类型转换           dynamic_cast<type>(expr)
typeid     类型识别                typeid(expr)

#include"iostream"
using namespace std;
int main(int argc,char *argv[])
{
	double d=97.4;cout<<"d="<<d<<endl;
	char ch=static_cast<char>(d);//转换d为char型
	cout<<"ch="<<ch<<endl;
	void *p=&d;//正确，空指正可以指向任意类型
	double *dp=static_cast<double *>(p);//转换p为double*指针
	cout<<"p="<<p<<endl
		<<"dp="<<dp<<endl
		//<<"*p="<<*p<<endl
		<<"*dp="<<*dp<<endl;
	return 0;
}

#include"iostream"
using namespace std;
int main(int argc,char *argv[])
{
	const char *c="Objective-C";
	char *p2=const_cast<char *>(c);
	cout<<c<<endl
		<<p2<<endl;
	int i=3;
	const int &cref_i=i;
	cout<<"i="<<cref_i<<endl;
	const_cast<int &>(cref_i)=4;
	cout<<"i="<<cref_i<<endl;
	return 0;
}

#include"iostream"
#include"typeinfo"
using namespace std;
class Base{virtual void f(){}};
class Derived:public Base{};
int main(int argc,char *argv[])
{
	Derived *pd=new Derived;
    Base *pb=pd;
	cout<<typeid(pb).name()<<endl
//		<<typeid(*pb).name()<<endl
		<<typeid(pd).name()<<endl;
//		<<typeid(*pd).name()<<endl;
	return 0;
}