
#include <iostream>

using std::cout;
using std::endl;

#ifdef _DEBUG

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

#endif

int main()
{
	int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	tmpFlag |= _CRTDBG_LEAK_CHECK_DF;
	_CrtSetDbgFlag(tmpFlag);

	int *x = new int(0);

	system("pause");
	return 0;
}