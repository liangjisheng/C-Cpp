
#include <iostream>

using std::cout;
using std::endl;
using std::wcout;

typedef wchar_t* LSPTR;

int main()
{
	short arr[] = {65, 66, 67, 0};
	wchar_t *s = NULL;
	// s = arr;							// error
	// s = wchar_t*(arr);				// error
	// s = (wchar_t *)arr;				// ok
	s = LSPTR(arr);						// ok
	wcout << s << endl;

	system("pause");
	return 0;
}