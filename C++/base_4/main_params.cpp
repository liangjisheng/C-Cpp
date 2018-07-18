
/***********************************************************
 * @name: main_params.cpp
 * @brief: 主函数参数
 * @author: Jisheng Liang
 * @date: 2018/6/7 16:33:40
 * @version: 1.0
 **********************************************************/

#include <iostream>
#include <tchar.h>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	wcout.imbue(locale("chs"));		//设置语言区域为中国
	wcout << argc << endl;
	for (int i = 0; i < argc; i++)
		wcout << "argv[" << i << "]=" << argv[i] << endl;

	return 0;
}
