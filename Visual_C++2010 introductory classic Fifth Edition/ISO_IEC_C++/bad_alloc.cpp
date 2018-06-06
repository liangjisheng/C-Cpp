// Catchint an exception thrown by new
#include <new>
#include <iostream>
using std::bad_alloc;
using std::cout;
using std::endl;

int main()
{
	char* pdata(nullptr);
	size_t count(static_cast<size_t>(0) / 2);
	try
	{
		pdata = new char[count];
		cout << "Memory allocated." << endl;
	}
	catch (bad_alloc& ex)
	{
		cout << "Memory allocation failed." << endl
			 << "The information form the exception object is: "
			 << ex.what() << endl;
	}

	delete[]pdata;

	system("pause");
	return 0;
}