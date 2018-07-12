// 882Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "882.h"
#include "882Dlg.h"
#include"winreg.h"
#pragma comment (lib,"advapi32.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy882Dlg dialog

CMy882Dlg::CMy882Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy882Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy882Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy882Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy882Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy882Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy882Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy882Dlg message handlers

BOOL CMy882Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy882Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMy882Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMy882Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy882Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	HKEY hKey;	// 键句柄
	LPCTSTR lpSubKey=_T("Software\\Microsoft\\Windows NT\\CurrentVersion\\");	// 子键
	long ret=::RegOpenKeyEx(HKEY_LOCAL_MACHINE,lpSubKey,0,KEY_READ,&hKey);	// 打开指定子键
	if(ret!=ERROR_SUCCESS)
		return ;	// 打开失败，返回
	
	LPCTSTR lpOwnName=_T("RegisteredOwner");		// 值的名称
	LPCTSTR lpOrgName=_T("RegisteredOrganization");	// 值的名称
	LPBYTE lpData=new BYTE[80];
	DWORD dwType=REG_SZ;	// 值的类型
	DWORD cbData=80;
	ret=::RegQueryValueEx(hKey,lpOwnName,NULL,&dwType,lpData,&cbData);	// 查询指定键
	if(ret!=ERROR_SUCCESS)
		m_strOwn=_T("无效的用户名称");

	m_strOwn=CString(lpData);
	cbData=80;
	ret=::RegQueryValueEx(hKey,lpOrgName,NULL,&dwType,lpData,&cbData);
	if(ret!=ERROR_SUCCESS)
		m_strOwn=_T("无效的公司名称");

	m_strOwn=CString(lpData);
	delete []lpData;
	::RegCloseKey(hKey);
	UpdateData(false);
}

void CMy882Dlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	int i,j;
	HKEY hKey;
	LPCTSTR lpSubKey="Software\\Micorsoft\\Windows NT\\CurrentVersion";
	long ret=::RegOpenKeyEx(HKEY_LOCAL_MACHINE,lpSubKey,0,KEY_WRITE,&hKey);
	if(ret!=ERROR_SUCCESS)
		return ;
	LPCTSTR lpOwnName=_T("RegisteredOwner");
	LPCTSTR lpOrgName=_T("RegisteredOrganization");
	int cbData=m_strOwn.GetLength()+1;
	LPBYTE lpData=new BYTE[cbData];
	for(i=0;i<cbData-1;i++)
		lpData[i]=m_strOwn.GetAt(i);
	lpData[i]='\0';
	DWORD dwType = REG_SZ;	// 指定类型
	ret=::RegSetValueEx(hKey,lpOwnName,0,dwType,lpData,cbData);
	if(ret!=ERROR_SUCCESS)
		return ;

	cbData=m_strOrg.GetLength()+1;
	lpData=new BYTE[cbData];
	for(j=0;j<cbData-1;j++)
		lpData[j]=m_strOrg.GetAt(j);
	lpData[j]='\0';
	ret=::RegSetValueEx(hKey,lpOrgName,0,dwType,lpData,cbData);
	if(ret!=ERROR_SUCCESS)
		return ;
	
	delete [] lpData;
	::RegCloseKey(hKey);
}
