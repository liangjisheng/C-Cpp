// test_mc.cpp
#include"iostream"
#include"stonewt.h"

int main() {
	using namespace std;
	mc mc1,mc2(3),mc3;
	cout<<mc1<<endl;
	cout<<mc1.get()<<endl;
	mc1.set(3);
	cout<<mc1<<endl;
	mc1=(mc)9;
	cout<<mc1<<endl;
	mc1=23;
	cout<<mc1<<endl;

	double xx=mc1;
	cout<<xx<<endl;

	int n=mc1;
	cout<<n<<endl;
	
	long n1=(double)mc1;
	cout<<n1<<endl;

	long n2=(int)mc1;
	cout<<n2<<endl;
	
	mc3=mc1+mc2;
	cout<<mc3<<endl;

	mc3=mc1+(mc)4;
	cout<<mc3<<endl;

	cout<<mc1*mc3<<endl;

	cout<<mc1*(mc)2<<endl;

	cout<<2*(double)mc1<<endl;

	return 0;
}