//求一个算术表达式，式中各数据可以是不同的类型
#include"iostream"
#include"sstream"//使用字符串流
using namespace std;//字符串流定义在std命名空间中
int main(int argc,char *argv[])
{
	string s1,s2;     //定义string对象
	ostringstream oss(ostringstream::out);//字符串输出流
	istringstream iss(istringstream::in);//字符串输入流
	char c1='+',c2;
	double val,sum=0.0;
	cout<<"请输入一个表达式:";
	cin>>s2;         //输入一个字符串
	iss.str(s2);     //复制s2的内容到字符串输入流
	while(c1!=' '){  //表达式结束
		iss>>val>>c2;//读取一个值和运算符+或-
		if(c1=='+')sum+=val;
		else if(c1=='-')sum-=val;
		c1=c2,c2=' ';
	}
	oss<<sum;        //将运算结果输出到字符串流中
	s1=oss.str();    //s1是其副本
	cout<<"结果等于:"<<s1<<endl;
	return 0;
}