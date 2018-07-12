#include"iostream"
#include"limits"
using namespace std;

int main()
{
	cout<<"max float="<<numeric_limits<float>::max()
		<<"\nmin float="<<numeric_limits<float>::min()
		<<"\nmax double="<<numeric_limits<double>::max()
		<<"\nmin double="<<numeric_limits<double>::min()
		<<"\nmax long double="<<numeric_limits<long double>::max()
		<<"\nmin long double="<<numeric_limits<long double>::min()
		<<"\nmax int="<<numeric_limits<int>::max()
		<<"\nmin int="<<numeric_limits<int>::min()
		<<"\nmax unsigned int="<<numeric_limits<unsigned>::max()
		<<"\nmin unsigned int="<<numeric_limits<unsigned>::min()
		<<"\nmax short int="<<numeric_limits<short int>::max()
		<<"\nmin short int="<<numeric_limits<short int>::min()
		<<"\nmax char="<<numeric_limits<char>::max()
		<<"\nmin char="<<numeric_limits<char>::min()
		<<"\nmax unsigned char="<<numeric_limits<unsigned char>::max()
		<<"\nmin unsigned char="<<numeric_limits<unsigned char>::min()
		<<"\nchar is signed="<<numeric_limits<char>::is_signed<<endl;

	system("pause");
	return 0;
}