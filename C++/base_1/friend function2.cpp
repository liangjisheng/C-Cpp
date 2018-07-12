#include"iostream"
using namespace std;
#ifndef DATA
#define DATA
class Data{
public:
	Data(int i,int j):a(i),b(j){}
	friend int MAX(Data &);
private:
	int a,b;
};
#endif
int MAX(Data& d)
{return d.a>d.b?d.a:d.b;}
//main
int main()
{
	Data data(4,6);
	cout<<"max is:"<<MAX(data)<<endl;
	return 0;
}
