#include"iostream"
using namespace std;
template<typename type>
type SUM(type var1,type var2)
{return var1+var2;}
int main()
{
	int a,b;
	cout<<"input two int numbers:";
	cin>>a>>b;
	cout<<"a+b="<<SUM(a,b)<<endl;
	double x,y;
	cout<<"input two double numbers:";
	cin>>x>>y;
	cout<<"x+y="<<SUM(x,y)<<endl;
	return 0;
}


#include"iostream"
using namespace std;
template<typename type,int len>
type MAX(type array[len])
{
	type result=array[0];
	for(int i=1;i<len;i++)
		result=array[i]>result?array[i]:result;
	return result;
}
int main()
{
	int a_int[5]={6,1,8,9,0};
	double b_double[5]={1.2,2.1,2.2,0.4,2.0};
	int max_int=MAX<int,5>(a_int);
	double max_double=MAX<double,5>(b_double);
	cout<<"max_int="<<max_int<<endl;
	cout<<"max_double="<<max_double<<endl;
	return 0;
}


#include"iostream"
using namespace std;
template<typename type>
type SUM(type x,type y)
{return x+y;}
template<typename type>
type SUM(type array[],int len)
{
	type sum=0;
	for(int i=0;i<len;i++)
		sum+=array[i];
	return sum;
}
int main(int argc,char *argv[])
{
	cout<<"整数和:"<<SUM(10,20)<<endl;
	int a[5]={1,2,4,5,3};
	cout<<"数组元素和:"<<SUM(a,5)<<endl;
	return 0;
}