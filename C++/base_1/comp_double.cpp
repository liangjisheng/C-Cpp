#include"iostream"
#include"math.h"
using namespace std;

int main()
{
	float x=0.5;
	double y=0.5;

	if(x==y) cout<<"x==y"<<endl;
	else cout<<"x!=y"<<endl;

	if(cos(x)==cos(y)) cout<<"x==y"<<endl;
	else cout<<"x!=y"<<endl;

	const double eps=0.00001;
	if(fabs(cos(x)-cos(y)) < eps)
		cout<<"x==y"<<endl;
	else cout<<"x!=y"<<endl;

	system("pause");
	return 0;
}