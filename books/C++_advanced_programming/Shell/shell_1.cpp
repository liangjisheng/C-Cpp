
// ��νShell���ǣ���һ����ָ�ɲ���ϵͳ�ṩ�ģ����ڼ�����û������ϵͳ
// �������ָ��õ�����ĳ���Shell�����ַ���ʽ�ģ�Ҳ������ͼ�ν�����ʽ�ġ�

// Windows Shell����Ҫ����ɲ�����explorer.exe����ʹ��Windows����ϵͳʱ��
// ��ʼ�˵�������������Դ�������ȶ���explorer.exe�ṩ�ġ����Shell�������
// Ҳ��ͼ���û�������Ƶ���Ҫ��ɲ��֡�����Shell������ƣ��������˽�����4����������ݡ�

//(1) Windows Shell��̽ӿڡ�
//Windows Shell�ṩһϵ�б�̽ӿڣ�������Ի�ȡ�����ļ��У�ʹ���ļ�����Ի���ȡ�
//Shell��̽ӿڵĺ�����ͨ�����ԡ�SH����ʼ��
//
//(2) Windows Shell��չ��
//Windowsƽ̨��Shell�ǿ���չ�ġ�����ΪWindows Shell������չ����(Extention)�����磺
//���Ʋ�ͬ���͵��ļ����Ҽ��˵�����ק�˵�������WinRAR��Adobe Acrobat��Ӧ�ó�����������Ĺ��ܣ���
//�󿪷�ϵͳ֪ͨ����ͼ�ꡢ��Ϊͼ�궨�Ʋ˵������ݵ�������(QQ��MSN��Visual Studio��Ӧ�ó�����������Ĺ���)��
//���������������ƹ������ȣ�
//�������Զ����ŶԻ����е�ѡ�
//����ӿ�������
//��Ϊ��ͬ�ļ������ļ�����ҳ���ļ��е�����ҳ���Ҽ����ԣ�����ѡ��ҳ��
//
//�����Ǽ��ֵ��͵�Shell��չӦ�á�
//(3)ע�����ShellӦ���о�����Ҫ���á�
//ShellӦ���ںܴ�̶���������ע����������¡�
//���ļ����͸������ض���չ�����ļ���ͼ�ꡢĬ�ϴ򿪳������ͨ��ע��������õġ�
//��Shell��չ�İ�װ�������ض������ļ����Ҽ��˵�����ק�˵�(Context Meun)�Ĳ˵�����봦�������ڵĶ�̬���ӿ⡣
//
//(4)���ͷ�ļ��Ϳ��ļ���
//����Shell�������ƣ���Ҫʹ��һЩͷ�ļ��Ϳ��ļ���
//һ��Shell API����shlobj.hͷ�ļ�����������She1132.dll����������ʱ��Ҫʹ�õ�She1132.lib�⡣

//һ��Ŀ¼����
//1����������
//
//������û�ʹ��Shell����еĲ��������ļ�������Shell����Ҫ�Ĺ���֮һ�ǽ����ļ���������ҡ������Լ����ļ���Ӧ�ó��������
//Windows Shell���кܶ�����Ŀ¼���ļ�����������Windows�û��������Ӵ�����
//���ҵ��ĵ����������桱��������վ�����������ļ���(Program files)�ȡ���ЩĿ¼����Shell����Ŀ¼��
//����ͨ��Shell������ƽӿڿ������򣬻�ȡ�Ͳ�����Щ����Ŀ¼��
//
//Shell��һ��������ļ���Ŀ¼����ʽ��ÿ��Ŀ¼����һ��PIDL 
//(Pointer of Item identifier list�����ʶ����ָ��)ֵ�����ֵΩһ��ʶһ���ļ��С�
//��ϵͳ����������ļ��е�CSIDL (constant special item ID list)�ǳ��������磺
//CSIDL_ DESKTOP�������桱�ļ��У��Ǹ�Ŀ¼��
//CSIDL_FAVORITES�����ղؼС���
//CSIDL_FONTS���������ļ��У�
//CSIDL_MYDOCUMENTS�������ҵ��ĵ�����
//CSIDL_MYMUSIC�����ҵ����֡���
//CSIDL PROFILE�����û����ļ��У�һ���������C:\Documents and Settings\username;
//CSIDL_PROGRAMS���������ļ��У�һ���������C:\Program Files;
//CSIDL_RECENT������������ĵ�����
//CSIDL_STARTMENU��������ʼ�˵���Ŀ¼��
//CSIDL_SYSTEM��CSIDL_WINDOWS�ֱ����ϵͳ���͡�Windows��Ŀ¼��
//SHGetNameFromIDList��SHGetPathFromIDList��Shell API����ͨ��CSIDL����й���Ŀ¼����ϸ��Ϣ��
//
//2���������ҵ��ĵ���������Ŀ¼
//�������ҵ��ĵ���������Ŀ¼��ز����漰��API��
//SHGetSpecialFolderPathͨ���ļ��е�CSIDL������ļ��е�·��;
//SHGetFolderLocation��ȡ�ļ��е�·������������ITEMIDLIST�ṹ��;
//SHGetPathFromIDList��PIDLת��Ϊ·����
//
//���ַ�������ȡ�����ļ��е�·����һ����ֱ��ʹ��SHGetSpecialFolderPath,
//����һ�ָ�Ϊͨ�ã�ʹ��SHGetFolderLocation��PIDL��CSIDL����ļ���λ�ú�
//��ʹ��SHGetPathFromIDList��ȡ�ļ�·���ַ�����


// ��ȡ����ʾ����Ŀ¼����������վʵ��
#include <Windows.h>
#include <ShlObj.h>
#include <iostream>

using std::cout;
using std::endl;

// �г�����վ����
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
	// ��ȡ�ҵ��ĵ���·��
	TCHAR szMyDocument[MAX_PATH] = {0};
	// ʹ��SHGetSpecialFolderPath()��ȡ����Ŀ¼·��
	SHGetSpecialFolderPath(NULL, szMyDocument, CSIDL_PERSONAL, FALSE);
	std::wcout << szMyDocument << std::endl;

	// ��ȡ����·��
	TCHAR szDesktop[MAX_PATH] = {0};
	LPITEMIDLIST pidl = NULL;
	LPMALLOC pMalloc = NULL;
	
	SHGetMalloc(&pMalloc);
	// ʹ��SHGetFolderLocation��SHGetPathFromIDList���Ի�ȡ����Ŀ¼��·��
	// ��CSIDL_DESKTOPDIRECTORY ·���ṹ������pidl
	SHGetFolderLocation(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, &pidl);
	SHGetPathFromIDList(pidl, szDesktop);
	std::wcout << szDesktop << std::endl;
}


// ��������վ
DWORD ListFileInRecycleBin()
{
	TCHAR pszPath[MAX_PATH] = {0};
	IShellFolder *pisf = NULL;
	IShellFolder *pisfRecBin = NULL;

	// ��ȡ��Ŀ¼������
	SHGetDesktopFolder(&pisfRecBin);

	IEnumIDList *peidl = NULL;
	LPITEMIDLIST pidlBin = NULL;
	LPITEMIDLIST idlCurrent = NULL;
	LPMALLOC pMalloc = NULL;

	SHGetMalloc(&pMalloc);
	// ����վλ��
	SHGetFolderLocation(NULL, CSIDL_BITBUCKET, NULL, 0, &pidlBin);
	// �󶨻���վ����
	pisfRecBin->BindToObject(pidlBin, NULL, IID_IShellFolder, (void**)&pisf);
	// �оٻ���վ�еĶ��󣬵õ�IEnumIDLists�ӿڣ�����SHCONTF_FOLDERS
	// SHCONTF_NONFOLDERS, SHCONTF_INCLUDEHIDDEN���͵Ķ���
	pisf->EnumObjects(NULL, 
		SHCONTF_FOLDERS | SHCONTF_NONFOLDERS | SHCONTF_INCLUDEHIDDEN,
		&peidl);

	STRRET strret;
	ULONG uFetched;

	HANDLE hOutPut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Files in Recycle Bin." << endl;

	while(1)
	{
		// ����IEnumIDList����idlCurrentΪ��ǰ����
		if(peidl->Next(1, &idlCurrent, &uFetched) == S_FALSE)
			break;

		// ��ȡ����վ��ǰ����ǰ��·����
		SHGetPathFromIDList(idlCurrent, pszPath);
		std::wcout << pszPath << endl;

		// DisplayName,ɾ��ǰ��·��
		pisf->GetDisplayNameOf(idlCurrent, SHGDN_NORMAL, &strret);

		WriteConsole(hOutPut, L"\t", 1, NULL, NULL);
		WriteConsole(hOutPut, strret.pOleStr, lstrlenW(strret.pOleStr), NULL, NULL);
		WriteConsole(hOutPut, L"\n", 1, NULL, NULL);
	}

	// �ͷ���Դ
	pMalloc->Free(pidlBin);
	pMalloc->Free(strret.pOleStr);
	pMalloc->Release();
	pisf->Release();
	return 0;
}

