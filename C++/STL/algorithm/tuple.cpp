#include"iostream"
#include<tuple>
#include"vector"
#include"string"
#include"functional"
using namespace std;

// tuple将多个数据打包成一种新的数据类型，
// 类似于结构体
// tuple<string,unsigned int,double> Li;	// 定义一个变量li
// 使用make_tuple()函数对变量li赋值
// tupleLi=make_tuple("asdf",1,1.2);
// 利用typedef将新的数据类型定义为一个简短的类型名
typedef tuple<string,unsigned int,double> Human;
// 定义变量
Human h("qwer",2,2.0);
vector<Human> vecHumans;

int main()
{
	Human Li("asdf",1,1.0);
	// 获取Li中的第一个数据姓名
	cout<<"姓名:"<<get<0>(Li)<<endl;
	get<1>(Li) +=1;
	cout<<"年龄:"<<get<1>(Li)<<endl;
	cout<<"体重:"<<get<2>(Li)<<endl;

	string strName;
	unsigned int nAge;
	double fWeight;
	// 获取Li中的各个数据，并保存到各分数据的变量中
	tie(strName,nAge,fWeight)=Li;
	cout<<strName<<endl
		<<nAge<<endl
		<<fWeight<<endl;

	system("pause");
	return 0;
}