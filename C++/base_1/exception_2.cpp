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
		cout<<(int)c<<endl;
	}
	catch(Range_error& e) {
		cerr<<"error\n";
	}
}

int main()
{
	g(3);
	g(345);
	int minc=numeric_limits<char>::min();
	int maxc=numeric_limits<char>::max();
	cout<<"numeric_limits<char>::min()="<<minc<<endl;
	cout<<"numeric_limits<char>::max()="<<maxc<<endl;

	int mins=numeric_limits<short int>::min();
	int maxs=numeric_limits<short int>::max();
	cout<<"numeric_limits<short int>::min()="<<mins<<endl;
	cout<<"numeric_limits<short int>::max()="<<maxs<<endl;

	int mini=numeric_limits<int>::min();
	int maxi=numeric_limits<int>::max();
	cout<<"numeric_limits<int>::min()="<<mini<<endl;
	cout<<"numeric_limits<int>::max()="<<maxi<<endl;

	unsigned int minui=numeric_limits<unsigned int>::min();
	unsigned int maxui=numeric_limits<unsigned int>::max();
	cout<<"numeric_limits<unsigned>::min()="<<minui<<endl;
	cout<<"numeric_limits<unsigned>::max()="<<maxui<<endl;

	float minf=numeric_limits<float>::min();
	float maxf=numeric_limits<float>::max();
	cout<<"numeric_limits<float>::min()="<<minf<<endl;
	cout<<"numeric_limits<float>::max()="<<maxf<<endl;

	double mind=numeric_limits<double>::min();
	double maxd=numeric_limits<double>::max();
	cout<<"numeric_limits<double>::min()="<<mind<<endl;
	cout<<"numeric_limits<double>::max()="<<maxd<<endl;

	system("pause");
	return 0;
}