// ���ļ��жԻ��򣬻�ȡ�ļ���·��

#include <iostream>
#include <Windows.h>
#include <ShlObj.h>
#include <tchar.h>

using std::cout;
using std::endl;


// ITEMID��ITEMIDLIST
// Windows Shell��һ���������ڹ����ṩ������ȡϵͳ�е��ڶ����
// ��Щ����������ļ�����·�ϵļ���������������򣬻���վ�ȵȣ�
// Ϊ��ʶ��ÿһ������Windows Shellʹ����Item ID����ʾ������
// ��Iten ID Lists������ʾһ�������·�������ԣ�
// ITEMID��ITEMIDLIST�Ĺ�ϵ�������ļ�����·���Ĺ�ϵ��
// ���ֻ���ļ�ϵͳ���ԵĻ���ITEMIDLIST���Կ�����·������һ�б�ʾ����
// Windows ShellҲ�ṩ�˺��������ת����

// BOOL SHGetPathFromIDList( LPCITEMIDLIST pidl, LPSTR pszPath )
// ���������һ��ITEMLISTת�����ļ�ϵͳ�е�·����

int main()
{
	char szPath[_MAX_PATH] = {0};
	BROWSEINFOA bi;
	LPITEMIDLIST plDL;
	bi.hwndOwner = NULL;			// �����ھ��
	bi.pidlRoot = NULL;				// ��ʾ�ļ��еĸ�(root) NULLĬ��ΪDesktop
	//bi.pszDisplayName = szPath;
	bi.pszDisplayName = NULL;		// ���汻ѡȡ���ļ���·���Ļ�����
	bi.lpszTitle = "test";			// ��ʾ��Ŀ¼�Ի������ϲ��ֵı���
	// ָ���Ի�����ۺ͹��ܵı�־,�����ļ�ϵͳ��Ŀ¼
	bi.ulFlags = BIF_RETURNONLYFSDIRS;
	bi.lpfn = NULL;			// �����¼��Ļص�����
	bi.lParam = 0;			// �ص������Ĳ���
	bi.iImage = 0;			// ���汻ѡȡ���ļ��е�ͼƬ����

	// ����ָ��ITEMIDLIST��ָ�룬���ITEMIDLIST���Ǳ�ʾ���û���ѡ����ļ���
	plDL = SHBrowseForFolderA(&bi);
	// ��ITEMIDLISTת��Ϊ�ļ�ϵͳ�е�·��
	if(SHGetPathFromIDListA(plDL, szPath))
		cout << szPath << endl;

	system("pause");
	return 0;
}