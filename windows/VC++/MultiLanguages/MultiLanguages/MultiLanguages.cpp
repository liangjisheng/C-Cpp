
// MultiLanguages.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "MultiLanguages.h"
#include "MultiLanguagesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMultiLanguagesApp

BEGIN_MESSAGE_MAP(CMultiLanguagesApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMultiLanguagesApp ����

CMultiLanguagesApp::CMultiLanguagesApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CMultiLanguagesApp ����

CMultiLanguagesApp theApp;


// CMultiLanguagesApp ��ʼ��

BOOL CMultiLanguagesApp::InitInstance()
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

	// Ŀǰ�ܶ��������Ҫ���ڵ�������ң���ˣ�Ϊ����ṩ�������֧�־ͳ�Ϊ��
	// һ������������Ϊ����ṩ������Ե�֧�ֵľ���ʵ�ַ����кܶ࣬������ԭ��
	// ����࣬����ʵ�ִ�������԰��Ķ�������������趨������ѡ�����԰���
	// ���У�MFC����Դ�ļ����ṩ�˶Զ����ͬ���Ե�֧�ֹ��ܣ����ʹ��MFC������
	// ֱ������Դ�ļ��Դ��Ķ������֧�֣�����ʡȥ���ٵ��鷳��

	// ���������ѡ�������ϵͳ����(System Locale)���û���������(User Locale)
	// ���߳�����(Thread Locale)�йء���������ʱ���Ǹ����߳�������ѡ����Դ�ġ�
	// ���������δ���߳����Խ������ã��߳�����Ĭ�ϲ����û��������ԡ�
	// �����߳����Եĺ�����SetThreadLocale��������win7�²���ʹ����Ҫ��
	// SetThreadUILanguage�������̱߳�������

	// �����߳�����Ҫ�ڶԻ��򴴽�֮ǰ�������޷����ĶԻ������Դ,������Ӧ�ó����
	// InitInstance()����������߳���������

	// �����߳�����Ϊ����
	// SetThreadLocale(MAKELCID(MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), SORT_DEFAULT));

	// �����߳�����ΪӢ��
	// SetThreadLocale(MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), SORT_DEFAULT));

	// ���µ�ϵͳ������������ܲ������ã�WIN7+VC2010ϵͳ�У���������Ӧ��ʹ�����´���
	// SetThreadUILanguage(MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), SORT_DEFAULT));

	// �������֮ǰ�����ݵ�ǰ����������ļ��е������������߳����ԣ�
	CString strFileName = _T("Language.ini");
	if(PathFileExists(strFileName))
	{
		LCID lcidThread = 0;
		CFile file;
		file.Open(strFileName, CFile::modeRead | CFile::typeBinary);
		file.Read(&lcidThread, sizeof(LCID));
		file.Close();
		// SetThreadLocale(lcidThread);			// �����̱߳������ԣ����������win7�²�����
		SetThreadUILanguage(lcidThread);
	}

	CMultiLanguagesDlg dlg;
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

