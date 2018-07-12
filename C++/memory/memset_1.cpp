#include <iostream>
#include <vld.h>

using namespace std;

int main()
{
	for(int i = 0; i < 5; i++)
	{
		unsigned char *buff = new unsigned char[42000];
		memset(buff, 0, 42000);
		memcpy(buff, "adsf", 4);
		cout << buff << endl;
		delete []buff;
		buff = nullptr;
	}

	system("pause");
	return 0;
}