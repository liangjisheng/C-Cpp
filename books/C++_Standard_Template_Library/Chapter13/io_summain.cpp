
#include <iostream>
#include <cstdlib>

namespace MyLib
{
	double readAndProcessSum(std::istream& strm);
	double readAndProcessSum1(std::istream& strm);
}

int main()
{
	using namespace std;
	double sum = 0;

	try{
		sum = MyLib::readAndProcessSum1(cin);
	}
	catch(const ios::failure& error)
	{
		cerr << "standard exception: " << error.what() << endl;
		system("pause");
		return EXIT_FAILURE;
	}
	catch(...)
	{
		cerr << "unknown exception" << endl;
		system("pause");
		return EXIT_FAILURE;
	}

	cout << "sum: " << sum << endl;

	system("pause");
	return 0;
}
