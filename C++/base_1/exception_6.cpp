#include"iostream"
using namespace std;
void fun(int test)
{
	if(test==0)throw test;//当test是0时抛出int型异常
	if(test==1)throw 1.5;//当test是2时抛出double型异常
	if(test==2)throw "abc";//当test是2时抛出char*型异常
	cout<<"fun 调用正常结束"<<endl;
}
void caller1(int test)
{
	try{fun(test);}
	catch(int){cout<<"caller1 捕获 int->";}
	cout<<"caller1调用正常结束"<<endl;
}
void caller2(int test)
{
	try{caller1(test);}
	catch(double){cout<<"caller2 捕获 double->";}
	catch(...){cout<<"caller2 捕获所有未知异常->";}
	cout<<"caller2调用正常结束"<<endl;
}
int main(int argc,char *argv[])
{
	for(int i=3;i>=0;i--)caller2(i);
	return 0;
}