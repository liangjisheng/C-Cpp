
// 所谓Shell（壳），一般是指由操作系统提供的，用于计算机用户向操作系统
// 输入相关指令并得到结果的程序。Shell可以字符形式的，也可以是图形界面形式的。

// Windows Shell最重要的组成部件是explorer.exe。在使用Windows操作系统时，
// 开始菜单、任务栏、资源管理器等都是explorer.exe提供的。因此Shell程序设计
// 也是图形用户界面设计的重要组成部分。掌握Shell程序设计，需首先了解下面4个方面的内容。

//(1) Windows Shell编程接口。
//Windows Shell提供一系列编程接口，例如可以获取特殊文件夹，使用文件浏览对话框等。
//Shell编程接口的函数名通常是以“SH”开始。
//
//(2) Windows Shell扩展。
//Windows平台的Shell是可扩展的。可以为Windows Shell开发扩展程序(Extention)，例如：
//◇定制不同类型的文件的右键菜单、拖拽菜单（比如WinRAR、Adobe Acrobat等应用程序具有这样的功能）；
//◇开发系统通知区域图标、并为图标定制菜单和气泡弹出功能(QQ、MSN、Visual Studio等应用程序具有这样的功能)；
//◇定制任务栏、定制工具栏等；
//◇增加自动播放对话框中的选项；
//◇添加控制面板项；
//◇为不同文件类型文件属性页、文件夹的属性页（右键属性）增加选项页。
//
//上面是几种典型的Shell扩展应用。
//(3)注册表在Shell应用中具有重要作用。
//Shell应用在很大程度上依赖于注册表，举例如下。
//◇文件类型辅助：特定扩展名的文件的图标、默认打开程序等是通过注册表来配置的。
//◇Shell扩展的安装：比如特定类型文件的右键菜单、拖拽菜单(Context Meun)的菜单项及输入处理函数所在的动态链接库。
//
//(4)相关头文件和库文件。
//进行Shell程序的设计，需要使用一些头文件和库文件。
//一般Shell API都在shlobj.h头文件中声明，由She1132.dll导出，链接时需要使用到She1132.lib库。

//一、目录管理
//1、基本介绍
//
//计算机用户使用Shell最常进行的操作就是文件操作。Shell最重要的功能之一是进行文件浏览、查找、管理以及将文件和应用程序关联。
//Windows Shell中有很多特殊目录和文件，比如所有Windows用户都经常接触到的
//“我的文档”、“桌面”、“回收站”、“程序文件”(Program files)等。这些目录都是Shell特殊目录。
//可以通过Shell程序设计接口开发程序，获取和操作这些特殊目录。
//
//Shell有一种特殊的文件和目录管理方式，每个目录都有一个PIDL 
//(Pointer of Item identifier list，项标识符表指针)值，这个值惟一标识一个文件夹。
//由系统定义的特殊文件夹的CSIDL (constant special item ID list)是常数，比如：
//CSIDL_ DESKTOP代表“桌面”文件夹，是根目录；
//CSIDL_FAVORITES代表“收藏夹”；
//CSIDL_FONTS代表字体文件夹；
//CSIDL_MYDOCUMENTS，代表“我的文档”；
//CSIDL_MYMUSIC代表“我的音乐”；
//CSIDL PROFILE代表“用户”文件夹，一般情况下是C:\Documents and Settings\username;
//CSIDL_PROGRAMS代表“程序”文件夹，一般情况下是C:\Program Files;
//CSIDL_RECENT，代表“最近的文档”；
//CSIDL_STARTMENU，代表“开始菜单”目录；
//CSIDL_SYSTEM、CSIDL_WINDOWS分别代表“系统”和“Windows”目录。
//SHGetNameFromIDList、SHGetPathFromIDList等Shell API函数通过CSIDL获得有关于目录的详细信息。
//
//2、操作“我的文档”等特殊目录
//操作“我的文档”等特殊目录相关操作涉及的API：
//SHGetSpecialFolderPath通过文件夹的CSIDL，获得文件夹的路径;
//SHGetFolderLocation获取文件夹的路径，并保存在ITEMIDLIST结构中;
//SHGetPathFromIDList从PIDL转换为路径。
//
//两种方法来获取特殊文件夹的路径，一种是直接使用SHGetSpecialFolderPath,
//另外一种更为通用，使用SHGetFolderLocation从PIDL或CSIDL获得文件夹位置后，
//再使用SHGetPathFromIDList获取文件路径字符串。


// 获取并显示特殊目录，遍历回收站实例
#include <Windows.h>
#include <ShlObj.h>
#include <iostream>

using std::cout;
using std::endl;

// 列出回收站名字
DWORD ListFileInRecycleBin();
void GetSpecialFolder();

int main()
{
	ListFileInRecycleBin();
	GetSpecialFolder();

	system("pause");
	return 0;
}

void GetSpecialFolder()
{
	// 获取我的文档的路径
	TCHAR szMyDocument[MAX_PATH] = {0};
	// 使用SHGetSpecialFolderPath()获取特殊目录路径
	SHGetSpecialFolderPath(NULL, szMyDocument, CSIDL_PERSONAL, FALSE);
	std::wcout << szMyDocument << std::endl;

	// 获取桌面路径
	TCHAR szDesktop[MAX_PATH] = {0};
	LPITEMIDLIST pidl = NULL;
	LPMALLOC pMalloc = NULL;
	
	SHGetMalloc(&pMalloc);
	// 使用SHGetFolderLocation、SHGetPathFromIDList可以获取任意目录的路径
	// 将CSIDL_DESKTOPDIRECTORY 路径结构保存在pidl
	SHGetFolderLocation(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, &pidl);
	SHGetPathFromIDList(pidl, szDesktop);
	std::wcout << szDesktop << std::endl;
}


// 遍历回收站
DWORD ListFileInRecycleBin()
{
	TCHAR pszPath[MAX_PATH] = {0};
	IShellFolder *pisf = NULL;
	IShellFolder *pisfRecBin = NULL;

	// 获取根目录，桌面
	SHGetDesktopFolder(&pisfRecBin);

	IEnumIDList *peidl = NULL;
	LPITEMIDLIST pidlBin = NULL;
	LPITEMIDLIST idlCurrent = NULL;
	LPMALLOC pMalloc = NULL;

	SHGetMalloc(&pMalloc);
	// 回收站位置
	SHGetFolderLocation(NULL, CSIDL_BITBUCKET, NULL, 0, &pidlBin);
	// 绑定回收站对象
	pisfRecBin->BindToObject(pidlBin, NULL, IID_IShellFolder, (void**)&pisf);
	// 列举回收站中的对象，得到IEnumIDLists接口，包括SHCONTF_FOLDERS
	// SHCONTF_NONFOLDERS, SHCONTF_INCLUDEHIDDEN类型的对象
	pisf->EnumObjects(NULL, 
		SHCONTF_FOLDERS | SHCONTF_NONFOLDERS | SHCONTF_INCLUDEHIDDEN,
		&peidl);

	STRRET strret;
	ULONG uFetched;

	HANDLE hOutPut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Files in Recycle Bin." << endl;

	while(1)
	{
		// 遍历IEnumIDList对象，idlCurrent为当前对象
		if(peidl->Next(1, &idlCurrent, &uFetched) == S_FALSE)
			break;

		// 获取回收站当前对象当前的路径，
		SHGetPathFromIDList(idlCurrent, pszPath);
		std::wcout << pszPath << endl;

		// DisplayName,删除前的路径
		pisf->GetDisplayNameOf(idlCurrent, SHGDN_NORMAL, &strret);

		WriteConsole(hOutPut, L"\t", 1, NULL, NULL);
		WriteConsole(hOutPut, strret.pOleStr, lstrlenW(strret.pOleStr), NULL, NULL);
		WriteConsole(hOutPut, L"\n", 1, NULL, NULL);
	}

	// 释放资源
	pMalloc->Free(pidlBin);
	pMalloc->Free(strret.pOleStr);
	pMalloc->Release();
	pisf->Release();
	return 0;
}

