// output1.cpp -- char and address
#include"iostream"
#include"cstdlib"
#include"cstring"
#include"iomanip.h"

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;

	const char * amount="lishuyu";
	cout<<"amount="<<amount<<endl;
	cout<<"address amount="<<(void*)amount<<endl;

	cout.put('a')<<endl;
	cout.put('b').put('c')<<endl;		// 可以拼接
	cout.put(65)<<endl;	// 整数转换成字母'A'
	cout.put(66.3)<<endl;	// 转换成'B'
	cout<<endl<<endl;

	const char * state1="Florida";
	const char * state2="Kansas";
	const char * state3="Euphoria";
	int len=strlen(state2);
	cout<<"state1="<<state1<<endl;
	cout<<"state2="<<state2<<endl;
	cout<<"state3="<<state3<<endl;
	cout<<"Increasing loop index:\n";
	int i;
	for(i=1;i<=len;i++) {
		cout.write(state2,i);
		cout<<endl;
	}

	cout<<"Decreasing loop index:\n";
	for(i=len;i>0;i--)
		cout.write(state2,i)<<endl;

	// exceed string length
	cout<<"Exceeding string legth:\n";
	cout.write(state2,len+5)<<endl;

	cout<<"hello,good-looking!"<<flush;
	cout<<"wait just a moment,please.!"<<endl;
	
	system("pause");
	return 0;
}