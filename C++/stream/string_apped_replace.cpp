#include"iostream"
#include"string"
#include"cstring"
#include"iomanip"
using namespace std;
int main(int argc,char *argv[])
{
	string s1,s2,s3;
	s1="liang";
	s2="jisheng";
	s3="lijiahouzhihui";
	cout<<"s1+s2="<<s1+s2<<endl;
	cout<<s1.append("jisheng")<<endl;//将"jisheng"添加到s1的结尾
	//cout<<s1.append(s3,4)<<endl;将s3的前4个字符添加到s1的结尾
	//cout<<s1.append(2,"haha")<<endl;将haha的2份备份添加到s1的结尾
	cout<<s1.insert(4,s2)<<endl;//将s2插入到s1中的位置4处
	cout<<s1.insert(4,s2,3,2)<<endl;//将s2从第3位开始的2个字符插入到s1中的位置4处
	//cout<<s1.insert(4,s2,5)<<endl;将s2的前5个字符插入到s1中的位置4处
	//cout<<s1.insert(4,2,s2)<<endl;将s2的2份备份插入到s1中的位置4处
	cout<<s1.erase(4,12)<<endl;//删除s1从位置4开始的12个字符
	cout<<s1.replace(4,5,s2)<<endl;//将s1从位置4开始的5个字符用s2替换
	//cout<<s1.replace(4,5,s2,6)<<endl;将s1从位置4开始的5个字符用s2的前6个字符替换
	//cout<<s1.swap(s3)<<endl;交换s1和s3的内容；返回类型为void
	swap(s1,s2);//交换s1和s2的内容；返回类型为void
	return 0;
}