#include"iostream"
using namespace std;
#include"stdarg.h"

double avg(int emp_num,...) {
	double total=0.0,sal=0.0;
	int num=emp_num;
	va_list ap;
	va_start(ap,emp_num);
	while(num--) {
		sal=va_arg(ap,double);	// 获取当前工资
		total+=sal;
	}
	va_end(ap);
	return (total?(total/emp_num):0);
}

int main(int argc,char* argv[],char* envp[]) {
	cout<<"平均工资："<<avg(5,1234.56,1111.11,5500.00,2345.67,2222.22)<<"$"<<endl;
	return 0;
}