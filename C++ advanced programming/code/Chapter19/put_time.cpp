#include <iostream>
#include <ctime>
#include <iomanip>
#include <locale>

using namespace std;

int main()
{
	time_t t = time(NULL);
	//tm* ptm = localtime(&t);
	tm tm;
	localtime_s(&tm, &t);
	cout << put_time(&tm, "%y-%m-%d %H:%M:%S") << endl;

	system("pause");
	return 0;
}