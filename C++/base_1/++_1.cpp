// a=5;p=++a+(++a);是多少？p=（++a）+(++a)+(++a);
#include"iostream"
using namespace std;

int main()
{
	int a=5;
	int p=++a+(++a);
	cout<<p<<endl;
	p=++a+(++a)+(++a);
	cout<<p<<endl;

	system("pause");
	return 0;
}