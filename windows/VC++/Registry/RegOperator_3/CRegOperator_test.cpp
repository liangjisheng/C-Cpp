
/***********************************************************************
 * 文件名: CRegOperator_test.cpp
 * 文件描述: 对封装的注册表操作类进行测试
 * 创建人: 梁基圣 20171104
 * 版本号: 1.0
 * 修改记录:
***********************************************************************/

#include "RegOperator.h"
#include <iostream>

void RegOperatorHelp(); 

using std::cout;
using std::endl;
using std::wcout;

int main(int argc, char* argv[])
{
	bool bReturn;
	// 命令行没有参数则输出帮助提示信息
	if(1 == argc)
	{
		RegOperatorHelp();
		//return 0;
	}

	//for (int i = 0; i < argc; ++i)
	//	assert(argv[i]);

	//TCHAR** wargv = new TCHAR*[argc - 1];
	//for (int i = 1; i < argc; ++i)
	//	wargv[i] = const_cast<TCHAR*>((CRegOperator::s2ws(argv[i])).c_str());

	TCHAR* wargv[4];
	wargv[0] = _T("-read");
	wargv[1] = _T("HKEY_CURRENT_USER");
	wargv[2] = _T("Software\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\{CF0F5650-A1B7-4ED0-88E1-91C37D1E9357}");
	wargv[3] = _T("Language");

	/*============================================================ 
    * 分支功能：读取键值 
    * 参　　数：-read  RootKey SubKey ValueName 
    * 参数说明：命令 根键 子键 值的名字 
    * 抛出异常：操作失败，提示信息 
    * 作　　者：梁基圣 20171104
    *============================================================*/
	//if(0 == strcmp(argv[1], "-read"))
	//{
		//if(5 == argc)
		//{
			CRegOperator reg;
			DWORD dwRes;
			// 设置当前根键
			bReturn = reg.SetHKEY(wargv[1]);

			if(false == bReturn)
			{
				// cout << "\nThe key [" << argv[2] << "] set fail!" << endl;
				cout << "failed" << endl;
				system("pause");
				return 0;
			}

			bReturn = reg.OpenKey(wargv[2]);
			if(false == bReturn)
			{
				//cout << "Open [" << argv[3] << "] fail!" << endl;
				cout << "failed" << endl;
				system("pause");
				return 0;
			}

			bReturn = reg.Read(wargv[3], &dwRes);
			if(false == bReturn)
			{
				// cout << "Read [" << argv[4] << "] fail!" << endl;
				cout << "failed" << endl;
				system("pause");
				return 0;
			}

			// cout << "The [" << argv[4] << "] value is [";
			wcout << "The [" << wargv[3] << "] value is [" << dwRes << "]" << endl;
			system("pause");
			return 0;
		//}
		//else
		//{
		//	cout << "Warning: Must have four param with /'-read/' option!" << endl;
		//	return 0;
		//}
	//}
}

void RegOperatorHelp()
{
	cout << " * 作　　者：梁基圣, 2017年11月04日" << endl;  
    cout << "/*============================================================" << endl;  
    cout << "* 分支功能：读取键值" << endl;  
    cout << "* 参　　数：-read  RootKey SubKey ValueName" << endl;  
    cout << "* 参数说明：命令 根键 子键 值的名字" << endl;  
    cout << "* 抛出异常：操作失败，提示信息。" << endl;  
    cout << "*============================================================*/" << endl;  
	cout << endl;  

	cout << "/*============================================================" << endl;  
    cout << "* 分支功能：创建子键" << endl;  
    cout << "* 参　　数：-create  RootKey SubKey" << endl;  
    cout << "* 参数说明：命令 根键 子键" << endl;  
    cout << "* 抛出异常：操作失败，提示信息。" << endl;  
    cout << "*============================================================*/" << endl;  
	cout << endl;  

    cout << "/*============================================================" << endl;  
    cout << "* 分支功能：创建键值" << endl;  
    cout << "* 参　　数：-write  RootKey SubKey ValueName Value" << endl;  
    cout << "* 参数说明：命令 根键 子键 值的名字 值" << endl;  
    cout << "* 抛出异常：操作失败，提示信息。" << endl;  
    cout << "*============================================================*/" << endl;  
	cout << endl;  

    cout << "/*============================================================" << endl;  
    cout << "* 分支功能：删除键值" << endl;  
    cout << "* 参　　数：-delval  RootKey SubKey ValueName" << endl;  
    cout << "* 参数说明：命令 根键 子键 值的名字" << endl;  
    cout << "* 抛出异常：操作失败，提示信息。" << endl;  
    cout << "*============================================================*/" << endl;  
	cout << endl;  

    cout << "/*============================================================" << endl;  
    cout << "* 分支功能：删除非空子键" << endl;  
    cout << "* 参　　数：-delkey  RootKey SubKey" << endl;  
    cout << "* 参数说明：命令 根键 子键" << endl;  
    cout << "* 抛出异常：操作失败，提示信息。" << endl;  
    cout << "*============================================================*/" << endl;  
	cout << endl;  

    cout << "/*============================================================" << endl;  
    cout << "* 分支功能：备份注册表" << endl;  
    cout << "* 参　　数：-save  RootKey SubKey Filename" << endl;  
    cout << "* 参数说明：命令 根键 子键 文件名" << endl;  
    cout << "* 抛出异常：操作失败，提示信息。" << endl;  
    cout << "*============================================================*/" << endl;  
	cout << endl;  

    cout << "/*============================================================" << endl;  
    cout << "* 分支功能：恢复注册表" << endl;  
    cout << "* 参　　数：-restore  RootKey Filename" << endl;  
    cout << "* 参数说明：命令 根键 文件名" << endl;  
    cout << "* 抛出异常：操作失败，提示信息。" << endl;  
    cout << "*============================================================*/" << endl;  
	cout << endl;  

    cout << "/*============================================================" << endl;  
    cout << "* 分支功能：版主信息" << endl;  
    cout << "* 参　　数：-h [-help]" << endl;  
    cout << "* 参数说明：命令" << endl;  
    cout << "* 抛出异常：操作失败，提示信息。" << endl;  
    cout << "*============================================================*/" << endl;  
	cout << endl;
}

