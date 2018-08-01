#include"iostream"
#include"limits"
using namespace std;

struct Range_error{
	int i;
	Range_error(int ii) { i=ii; }
};

char to_char(int i) 
{
	if(i < numeric_limits<char>::min() || numeric_limits<char>::max() < i)
		throw Range_error(i);
	return i;
}

void g(int i) {
	try {
		char c=to_char(i);
		cout<<c<<endl;
	}
	catch(Range_error& e) {
		cerr<<"error\n";
	}
}

int main()
{
	g(3);

	system("pause");
	return 0;
}
