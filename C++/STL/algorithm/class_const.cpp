#include"iostream"
using namespace std;

class sb{
private:
	const static int i;
	static int b;
	const int ci;
public:
	sb() : ci(5) {}
	void print();
};
int sb::b=5;
const int sb::i=5;

class A{};

void sb::print() {
	cout<<"const static int i="<<i<<endl
		<<"static int b="<<b<<endl
		<<"const int ci="<<ci<<endl;
}

int main()
{
	cout<<"sizeof class sb="<<sizeof(sb)<<endl;
	sb sb1;
	sb1.print();

	cout<<"sizeof(A)="<<sizeof(A)<<endl;

	system("pause");
	return 0;
}