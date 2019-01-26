
#include <iostream>
using namespace std;

int main()
{
	char c;

	// while it is possible to read a character
	// Ctrl+Z ½áÊøÊäÈë
	// pass by reference
	while (cin.get(c))
		cout.put(c);

	system("pause");
	return 0;
}
