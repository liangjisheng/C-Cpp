// Shaddlg2.cpp : implementation file
//

#include "stdafx.h"
#include "1018.h"
#include "Shaddlg2.h"
#include "1018Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShaddlg2 dialog


CShaddlg2::CShaddlg2(CWnd* pParent /*=NULL*/)
	: CDialog(CShaddlg2::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShaddlg2)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}


void CShaddlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShaddlg2)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CShaddlg2, CDialog)
	//{{AFX_MSG_MAP(CShaddlg2)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShaddlg2 message handlers
BOOL CShaddlg2::OnInitDialog()
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
	SetWindowLong(GetSafeHwnd(),GWL_EXSTYLE,
		GetWindowLong(GetSafeHwnd(),GWL_EXSTYLE) | 0x80000);
	typedef BOOL(WINAPI* FSetLayeredWindowAttributes)(HWND,COLORREF,BYTE,DWORD);
	FSetLayeredWindowAttributes SetLayeredWindowAttributes;
	HINSTANCE hInst=LoadLibrary("User32.DLL");
	SetLayeredWindowAttributes=(FSetLayeredWindowAttributes)
	GetProcAddress(hInst,"SetLayeredWindowAttributes");
	if(SetLayeredWindowAttributes)
		SetLayeredWindowAttributes(GetSafeHwnd(),RGB(0,0,0),128,2);
	FreeLibrary(hInst);
	m_font.CreateFont(18,16,0,0,600,0,0,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,FF_SCRIPT,"ËÎÌו");
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}
