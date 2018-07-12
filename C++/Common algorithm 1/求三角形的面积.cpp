#include"iostream"
#include"cmath"
using namespace std;
int main()
{
	double a,b,c;
	cout<<"input the a、b、c:";
	cin>>a>>b>>c;
	if(a+b>c&&b+c>a&&a+c>b)
	{
		double s,t;
		t=(a+b+c)/2.0;
		s=sqrt(t*(t-a)*(t-b)*(t-c));
		cout<<"area="<<s<<endl;
	}
	else
		cout<<"error!"<<endl;
	return 0;
}