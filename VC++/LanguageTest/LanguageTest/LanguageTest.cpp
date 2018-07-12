
// LanguageTest.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "LanguageTest.h"
#include "LanguageTestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLanguageTestApp

BEGIN_MESSAGE_MAP(CLanguageTestApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CLanguageTestApp ����

CLanguageTestApp::CLanguageTestApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CLanguageTestApp ����

CLanguageTestApp theApp;


// CLanguageTestApp ��ʼ��

BOOL CLanguageTestApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// ���� shell ���������Է��Ի������
	// �κ� shell ����ͼ�ؼ��� shell �б���ͼ�ؼ���
	CShellManager *pShellManager = new CShellManager;

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	// ʹ��SetThreadLocale�����л������������
	// ��������д��벢û����������
	// SetThreadLocale(MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), SORT_DEFAULT));
	// SetThreadUILanguage(MAKELANGID(LANG_ENGLISH,SUBLANG_ENGLISH_US));	// ok change to English

	// ����ʹ��GetUserDefaultUILanguage()�жϵ�ǰ�û��������ԣ��統ǰ�û�����
	// ����Ϊ"��������"ʱ������Ϊ"Ӣ��(����)"
	if(GetUserDefaultUILanguage() == MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED))
		SetThreadUILanguage(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US));

	// ������ϵͳ���Ի����£����ó�������ΪӢ��
	if ((GetSystemDefaultLangID() != MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED)) &&  
		(GetSystemDefaultLangID() != MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US)))  
	{  
		OSVERSIONINFO ovs;  
		ovs.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);  
		if (::GetVersionEx(&ovs))  
		{  
			if (ovs.dwPlatformId == VER_PLATFORM_WIN32_NT && ovs.dwMajorVersion >= 6 &&  
				ovs.dwMinorVersion >= 0)  
			{  
				SetThreadUILanguage(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US));  
			}  
			else  
				SetThreadLocale(MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), SORT_DEFAULT));  
		}  
	}  

	CLanguageTestDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ɾ�����洴���� shell ��������
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}

