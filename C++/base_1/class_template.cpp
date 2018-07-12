#include"iostream"
using namespace std;

template<class T>
// 建立一个静态模板类
class Operate{
	public:
		static T Add(T a,T b) { return a+b; }
		static T Mul(T a,T b) { return a*b; }
		static T Judge(T a,T b=1) {
			if(a>=0) return a;
			else return a/b;
		}
};

int main()
{
	int A=1,B=2,C=3,D=4,E=5,x,y,z;
	x=Operate<int>::Add(A,B);
	y=Operate<int>::Mul(C,D);
	z=Operate<int>::Judge(E,B);
	cout<<x<<' '<<y<<' '<<z<<endl;

	system("pause");
	return 0;
}