// 打开文件夹对话框，获取文件夹路径

#include <iostream>
#include <Windows.h>
#include <ShlObj.h>
#include <tchar.h>

using std::cout;
using std::endl;


// ITEMID和ITEMIDLIST
// Windows Shell的一个功能在于管理并提供方法存取系统中的众多对像，
// 这些对像包括了文件，网路上的计算机，控制面板程序，回收站等等，
// 为了识别每一个对像，Windows Shell使用了Item ID来表示它們，
// 而Iten ID Lists用来表示一个对像的路径。所以，
// ITEMID和ITEMIDLIST的关系类似于文件名和路径的关系。
// 如果只对文件系统而言的话，ITEMIDLIST可以看成是路径的另一中表示法，
// Windows Shell也提供了函数來进行转化。

// BOOL SHGetPathFromIDList( LPCITEMIDLIST pidl, LPSTR pszPath )
// 这个函数將一个ITEMLIST转换成文件系统中的路径。

int main()
{
	char szPath[_MAX_PATH] = {0};
	BROWSEINFOA bi;
	LPITEMIDLIST plDL;
	bi.hwndOwner = NULL;			// 父窗口句柄
	bi.pidlRoot = NULL;				// 显示文件夹的根(root) NULL默认为Desktop
	//bi.pszDisplayName = szPath;
	bi.pszDisplayName = NULL;		// 保存被选取的文件夹路径的缓冲区
	bi.lpszTitle = "test";			// 显示在目录对话框左上部分的标题
	// 指定对话框外观和功能的标志,返回文件系统的目录
	bi.ulFlags = BIF_RETURNONLYFSDIRS;
	bi.lpfn = NULL;			// 处理事件的回调函数
	bi.lParam = 0;			// 回调函数的参数
	bi.iImage = 0;			// 保存被选取的文件夹的图片索引

	// 返回指向ITEMIDLIST的指针，这个ITEMIDLIST这是表示了用户所选择的文件夹
	plDL = SHBrowseForFolderA(&bi);
	// 将ITEMIDLIST转换为文件系统中的路径
	if(SHGetPathFromIDListA(plDL, szPath))
		cout << szPath << endl;

	system("pause");
	return 0;
}