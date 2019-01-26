// 1058Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1058.h"
#include "1058Dlg.h"

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
// CMy1058Dlg dialog

CMy1058Dlg::CMy1058Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy1058Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy1058Dlg)
	// -1 ����������ѡ��ťȫ��ѡ��,
	// 0 ��ʾĳ����ĵ�һ����ѡ��ťѡ��
	// 1 ��ʾĳ����ĵڶ�����ѡ��ťѡ��
	// 2 ��ʾĳ����ĵ�������ѡ��ťѡ��
	// ��������
	// m_Radio1 = -1;	
	// m_Radio3 = -1;
	// m_Radio1=0;
	m_Radio3=0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1058Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy1058Dlg)
	DDX_Radio(pDX, IDC_RADIO1, m_Radio1);
	DDX_Radio(pDX, IDC_RADIO3, m_Radio3);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy1058Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy1058Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_HIDE, OnHide)
	ON_BN_CLICKED(IDC_SHOW, OnShow)
	ON_BN_CLICKED(IDC_OPENFORBID, OnOpenforbid)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1058Dlg message handlers

BOOL CMy1058Dlg::OnInitDialog()
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
	// ((CButton*)GetDlgItem(IDC_RADIO1))->SetCheck(true);
	// ((CButton*)GetDlgItem(IDC_RADIO2))->SetCheck(false);
	CheckRadioButton(IDC_RADIO1, //��һ������Ϊ����ĵ�һ����ѡ��ť��ID  
	IDC_RADIO2,  //�ڶ�������Ϊ��������һ����ѡ��ť��ID  
	IDC_RADIO1);        //����������Ϊ�����б�ѡ�еĵ�ѡ��ť��ID  
	GetDlgItem(IDC_BUTTON1)->EnableWindow(false);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy1058Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1058Dlg::OnPaint() 
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
HCURSOR CMy1058Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy1058Dlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	m_Radio1=0;	// ��һ����ť��ѡ��
	MessageBox("��һ��ĵ�һ����ť��ѡ��");
	GetDlgItem(IDC_BUTTON1)->EnableWindow(true);
}

void CMy1058Dlg::OnRadio3() 
{
	// TODO: Add your control notification handler code here
	m_Radio3=0;	// ��������ť��ѡ��
	MessageBox("�ڶ����һ����ť��ѡ��");
	GetDlgItem(IDC_BUTTON1)->EnableWindow(true);
}

void CMy1058Dlg::OnRadio2() 
{
	// TODO: Add your control notification handler code here
	m_Radio1=1;	// �ڶ�����ť��ѡ��
	MessageBox("��һ��ĵڶ�����ť��ѡ��");
	GetDlgItem(IDC_BUTTON1)->EnableWindow(true);
}

void CMy1058Dlg::OnRadio4() 
{
	// TODO: Add your control notification handler code here
	m_Radio1=1;	// ���ĸ���ť��ѡ��
	MessageBox("�ڶ���ڶ�����ť��ѡ��");
	GetDlgItem(IDC_BUTTON1)->EnableWindow(true);
}

void CMy1058Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	int iRadioButton3=GetCheckedRadioButton(IDC_RADIO3,IDC_RADIO4);
	int iRadioButton1=GetCheckedRadioButton(IDC_RADIO1,IDC_RADIO2);
	if(iRadioButton1==IDC_RADIO1)
		MessageBox("��һ��ĵ�һ����ť��ѡ��");
	if(iRadioButton1==IDC_RADIO2)
		MessageBox("��һ��ĵڶ�����ť��ѡ��");
	if(iRadioButton3==IDC_RADIO3)
		MessageBox("�ڶ���ĵ�һ����ť��ѡ��");
	if(iRadioButton3==IDC_RADIO4)
		MessageBox("�ڶ���ĵڶ�����ť��ѡ��");
}

void CMy1058Dlg::OnHide() 
{
	// TODO: Add your control notification handler code here
	CWnd * pWnd;
	pWnd=GetDlgItem(IDC_BUTTON1);
	pWnd->ShowWindow(SW_HIDE);
}

void CMy1058Dlg::OnShow() 
{
	// TODO: Add your control notification handler code here
	CWnd * pWnd;
	pWnd=GetDlgItem(IDC_BUTTON1);
	pWnd->ShowWindow(SW_SHOW);
}

static int i=0;

void CMy1058Dlg::OnOpenforbid() 
{
	// TODO: Add your control notification handler code here
	if(i++%2==0)
		GetDlgItem(IDC_BUTTON1)->EnableWindow(true);
	else 
		GetDlgItem(IDC_BUTTON1)->EnableWindow(false);
}
