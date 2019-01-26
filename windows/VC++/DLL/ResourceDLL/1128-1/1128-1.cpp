
// 1128-1.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "1128-1.h"
#include "MainFrm.h"

#include "1128-1Doc.h"
#include "1128-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy11281App

BEGIN_MESSAGE_MAP(CMy11281App, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CMy11281App::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
	ON_COMMAND(ID_CHINESE, &CMy11281App::OnChinese)
	ON_COMMAND(ID_ENGLISH, &CMy11281App::OnEnglish)
END_MESSAGE_MAP()


// CMy11281App construction

CMy11281App::CMy11281App()
{
	m_bHiColorIcons = TRUE;

	// support Restart Manager
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// If the application is built using Common Language Runtime support (/clr):
	//     1) This additional setting is needed for Restart Manager support to work properly.
	//     2) In your project, you must add a reference to System.Windows.Forms in order to build.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("1128-1.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	m_strCurrentPath = _T("");
	TCHAR szCurPath[MAX_PATH] = {0};
	GetCurrentDirectory(MAX_PATH, szCurPath);
	m_strCurrentPath = szCurPath;
	if (m_strCurrentPath.GetAt(m_strCurrentPath.GetLength() - 1) != _T('\\'))
		m_strCurrentPath += _T('\\');

	m_bEnglish = FALSE;
	m_bRestart = FALSE;
	m_hLangDLL = NULL;
}

// The one and only CMy11281App object

CMy11281App theApp;


// CMy11281App initialization

BOOL CMy11281App::InitInstance()
{
	// 在InitInstance中根据标志位载入资源
	m_bEnglish = GetLang();
	if (m_bEnglish)
	{
		m_hLangDLL = ::LoadLibrary(_T("ResDll.dll"));
		if (!m_hLangDLL)
		{
			AfxMessageBox(_T("Unable to load resource DLL!"));
			return FALSE;
		}
		AfxSetResourceHandle(m_hLangDLL);
	}

	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// Initialize OLE libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// AfxInitRichEdit2() is required to use RichEdit control	
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CMy11281Doc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CMy11281View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The one and only window has been initialized, so show and update it
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// call DragAcceptFiles only if there's a suffix
	//  In an SDI app, this should occur after ProcessShellCommand
	return TRUE;
}

int CMy11281App::ExitInstance()
{
	AfxOleTerm(FALSE);

	// 在退出实例函数中，增加释放DLL句柄及重启程序的代码
	if (m_hLangDLL)
		FreeLibrary(m_hLangDLL);

	if (m_bRestart)
	{
		STARTUPINFO StartupInfo = {0};
		PROCESS_INFORMATION ProcessInfo;

		StartupInfo.cb = sizeof(STARTUPINFO);
		TCHAR szPath[MAX_PATH] = {0};
		GetModuleFileName(NULL, szPath, MAX_PATH);
		CreateProcess(NULL, szPath, NULL, NULL, FALSE, 0, NULL, 
			m_strCurrentPath, &StartupInfo,&ProcessInfo);

		m_bRestart = FALSE;
	}

	return CWinAppEx::ExitInstance();
}

// CMy11281App message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// App command to run the dialog
void CMy11281App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CMy11281App customization load/save methods

void CMy11281App::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void CMy11281App::LoadCustomState()
{
}

void CMy11281App::SaveCustomState()
{
}

// CMy11281App message handlers
void CMy11281App::SetLang(BOOL bEnglish)  
{  
	CString strTemp;  
	strTemp.Format(_T("%d"), bEnglish);  
	WritePrivateProfileString(_T("English"), _T("bEnglish"), strTemp, m_strCurrentPath + _T("set.lang"));  
}

BOOL CMy11281App::GetLang(void)
{
	return GetPrivateProfileInt(_T("English"), _T("bEnglish"), 0, m_strCurrentPath + _T("set.lang"));
}


void CMy11281App::OnChinese()
{
	int nRet = 0;
	if (m_bEnglish)
		nRet = MessageBox(AfxGetApp()->GetMainWnd()->GetSafeHwnd(),
			_T("Really change to Chinese version?"), _T("Information"),
			MB_OKCANCEL | MB_ICONINFORMATION);
	else
		return;

	if (IDCANCEL == nRet)
		return ;

	SetLang(FALSE);
	m_bRestart = TRUE;
	PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WM_CLOSE, 0, 0);
}


void CMy11281App::OnEnglish()
{
	int nRet = 0;
	if (!m_bEnglish)
		nRet = MessageBox(AfxGetApp()->GetMainWnd()->GetSafeHwnd(),
			_T("确定切换到英文版本？"), _T("提示"), MB_OKCANCEL | MB_ICONINFORMATION);
	else
		return;

	if (IDCANCEL == nRet)
		return ;

	SetLang(TRUE);
	m_bRestart = TRUE;
	PostMessage(AfxGetMainWnd()->GetSafeHwnd(), WM_CLOSE, 0, 0);
}
