
// MultiLanguages.cpp : 定义应用程序的类行为。
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


// CMultiLanguagesApp 构造

CMultiLanguagesApp::CMultiLanguagesApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CMultiLanguagesApp 对象

CMultiLanguagesApp theApp;


// CMultiLanguagesApp 初始化

BOOL CMultiLanguagesApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	// 目前很多软件都是要出口到多个国家，因此，为软件提供多国语言支持就成为了
	// 一个基本条件。为软件提供多国语言的支持的具体实现方法有很多，但基本原理
	// 都差不多，就是实现代码和语言包的独立，代码根据设定的语言选择语言包。
	// 其中，MFC的资源文件就提供了对多国不同语言的支持功能，如果使用MFC开发，
	// 直接用资源文件自带的多国语言支持，可以省去不少的麻烦。

	// 程序的语言选择跟操作系统语言(System Locale)、用户设置语言(User Locale)
	// 和线程语言(Thread Locale)有关。程序运行时，是根据线程语言来选择资源的。
	// 如果程序中未对线程语言进行设置，线程语言默认采用用户设置语言。
	// 设置线程语言的函数是SetThreadLocale，但是在win7下不好使，需要用
	// SetThreadUILanguage来设置线程本地语言

	// 设置线程语言要在对话框创建之前，否则无法更改对话框的资源,可以在应用程序的
	// InitInstance()函数中添加线程语言设置

	// 设置线程语言为中文
	// SetThreadLocale(MAKELCID(MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), SORT_DEFAULT));

	// 设置线程语言为英文
	// SetThreadLocale(MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), SORT_DEFAULT));

	// 在新的系统中上述代码可能不起作用，WIN7+VC2010系统中，设置语言应该使用如下代码
	// SetThreadUILanguage(MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), SORT_DEFAULT));

	// 启动软件之前，根据当前软件的配置文件中的语言来设置线程语言，
	CString strFileName = _T("Language.ini");
	if(PathFileExists(strFileName))
	{
		LCID lcidThread = 0;
		CFile file;
		file.Open(strFileName, CFile::modeRead | CFile::typeBinary);
		file.Read(&lcidThread, sizeof(LCID));
		file.Close();
		// SetThreadLocale(lcidThread);			// 设置线程本地语言，这个函数在win7下不管用
		SetThreadUILanguage(lcidThread);
	}

	CMultiLanguagesDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

