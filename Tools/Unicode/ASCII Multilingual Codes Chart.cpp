
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	for(size_t i = 0; i < 256; i++)
	{
		if(i != 0 && 0 == i % 10)
			cout << endl;
		cout << (unsigned char)i << " ";
	}

	cout << "\n\n";
	for(size_t i = 0; i < 256; i++)
	{
		if(i != 0 && 0 == i % 10)
			cout << endl;
		cout << (char)i << " ";
	}

	system("pause");
	return 0;
}