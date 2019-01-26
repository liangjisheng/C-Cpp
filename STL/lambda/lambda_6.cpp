// Lambda表达式语法规则
// [变量使用说明符号] (参数列表) ->返回值数据类型
// { 函数体 } 
// []表示Lambda表达式的开始，用来告诉编译器接下来就是Lambda表达式
// 在[]中，可以使用Lambda表达式定义当前作用域中的变量方式，如果是传值
// 则使用=，将是Lambda表达式以只读的方式访问当前作用域内的变量，
// 若为[]空，则默认表示已传值方式使用当前作用域内的变量
#include <iostream>
#include"vector"
#include"algorithm"
using namespace std;

void print(int n) { cout<<n<<' '; }

int main(int argc, char** argv) 
{
	vector<int> v;
	for(int i=0;i<50;i+=3)
		v.push_back(i);
		
	cout<<"Before Data:"<<endl;
	for_each(v.begin(),v.end(),print);
	cout<<endl;
	
	cout<<"After Data:"<<endl;
	int nAdd=3;
	for_each(v.begin(),v.end(),
		[=](int x)
	{
		x+=nAdd;
		cout<<x<<" ";
	});
	cout<<endl;
	
	system("pause");
	return 0;
}
