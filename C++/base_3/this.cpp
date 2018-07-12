#include"iostream"
using namespace std;

class Point{
public:
	Point() {
		cout<<this<<endl;
		cout<<this+1<<endl;
		cout<<this-1<<endl;
	}
};

int main()
{
	Point a;
	cout<<&a<<endl;

	system("pause");
	return 0;
}