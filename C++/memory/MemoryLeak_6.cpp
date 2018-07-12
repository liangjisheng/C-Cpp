
#include <iostream>

using std::cout;
using std::endl;

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

#endif

int main()
{
	int *x = new int(0);
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif

	system("pause");
	return 0;
}