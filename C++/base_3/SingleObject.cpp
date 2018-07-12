// 私有构造函数，单例模式
#include"stdafx.h"
#include"iostream"
using namespace std;

class Emperor{
private:
	static Emperor * pEmperor;
	static int count;
	Emperor() { count++; }
public:
	static Emperor GetInstance() {
		if(pEmperor==NULL)
			pEmperor=new Emperor();
		return *pEmperor;
	}
	void GetName() { cout<<"我是第"<<count<<"次创建的实例"<<endl; }
};

Emperor * Emperor::pEmperor=NULL;
int Emperor::count=0;

int main(int argc,char * argv[])
{
	cout<<"创建1对象:"<<endl;
	Emperor emperor1=Emperor::GetInstance();
	emperor1.GetName();
	cout<<"创建2对象:"<<endl;
	Emperor emperor2=Emperor::GetInstance();
	emperor2.GetName();
	cout<<"创建3对象:"<<endl;
	Emperor emperor3=Emperor::GetInstance();
	emperor3.GetName();

	system("pause");
	return 0;
}