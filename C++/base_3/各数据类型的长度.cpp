#include"iostream"

int main()
{
	using std::endl;
	using std::cout;

	char var_ch='a';
	cout<<"var_ch="<<var_ch<<endl;
	cout<<"sizeof(char)="<<sizeof(var_ch)<<endl;
	
	unsigned char var_uch='b';
	cout<<"\nvar_uch="<<var_uch<<endl;
	cout<<"sizeof(unsigned char)="<<sizeof(var_uch)<<endl;

	signed char var_sch='c';
	cout<<"\nvar_sch="<<var_sch<<endl;
	cout<<"sizeof(signed char)="<<sizeof(var_sch)<<endl;

	wchar_t wch='a';
	cout<<"\nwch="<<wch<<endl;
	cout<<"sizeof(wchar_t)="<<sizeof(wch)<<endl;

	unsigned short var_usint=1;
	cout<<"\nvar_usint="<<var_usint<<endl;
	cout<<"sizeof(unsigned short)="<<sizeof(var_usint)<<endl;

	short int var_sint=1;
	cout<<"\nvar_sint="<<var_sint<<endl;
	cout<<"sizeof(short int)="<<sizeof(var_sint)<<endl;

	int var_int=2;
	cout<<"\nvar_int="<<var_int<<endl;
	cout<<"sizeof(int)="<<sizeof(var_int)<<endl;

	unsigned int var_uint=3;
	cout<<"\nvar_uint="<<var_uint<<endl;
	cout<<"sizeof(unsigned int)="<<sizeof(var_uint)<<endl;

	long int var_long=4;
	cout<<"\nvar_long="<<var_long<<endl;
	cout<<"sizeof(long)="<<sizeof(var_long)<<endl;

	unsigned long var_ulong=5;
	cout<<"\nvar_ulong="<<var_ulong<<endl;
	cout<<"sizeof(unsigned long)="<<sizeof(var_ulong)<<endl;

	float var_f=6.0;
	cout<<"\nvar_f="<<var_f<<endl;
	cout<<"sizeof(float)="<<sizeof(var_f)<<endl;

	double var_d=7.0;
	cout<<"\nvar_d="<<var_d<<endl;
	cout<<"sizeof(double)="<<sizeof(var_d)<<endl;

	long double var_ld=8.0;
	cout<<"\nvar_ld="<<var_ld<<endl;
	cout<<"sizeof(long double)="<<sizeof(var_ld)<<endl;

	enum mumble { m1,m2,m3 } mval;
	mval=m1;
	cout<<"\nmvar="<<mval<<endl;
	cout<<"sizeof(enum)="<<sizeof(mval)<<endl;

	system("pause");
	return 0;
}