
#include <iostream>
#include <Windows.h>
#include <ShlObj.h>			// for ITEMIDLIST
#include <string.h>

using std::cout;
using std::endl;

int main()
{
	ITEMIDLIST* ppidl;
	SHGetSpecialFolderLocation(NULL, CSIDL_DESKTOP, &ppidl);
	if(NULL == ppidl)
	{
		cout << "Æô¶¯ä¯ÀÀÂ·¾¶Ê§°Ü" << endl;
		return -1;
	}

	char szPath[_MAX_PATH] = {0};
	BROWSEINFOA* bi = new BROWSEINFOA;
	bi->hwndOwner = NULL;
	bi->iImage = 0;
	bi->lParam = NULL;
	bi->lpfn = NULL;
	bi->lpszTitle = "test browse info,select a directory.";
	bi->pidlRoot = ppidl;
	bi->pszDisplayName = NULL;
	bi->ulFlags = BIF_RETURNONLYFSDIRS | BIF_BROWSEINCLUDEFILES;

	ppidl = SHBrowseForFolderA(bi);
	if(!SHGetPathFromIDListA(ppidl, szPath))
	{
		delete bi;
		return -2;
	}

	delete bi;
	if(szPath[strlen(szPath) - 1] != '\\')
		szPath[strlen(szPath)] = '\\';
	cout << szPath << endl;

	system("pause");
	return 0;
}