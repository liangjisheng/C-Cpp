// 1139Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1139.h"
#include "1139Dlg.h"
#include "afxinet.h"

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
// CMy1139Dlg dialog

CMy1139Dlg::CMy1139Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy1139Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy1139Dlg)
	m_host = _T("");
	m_out = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1139Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy1139Dlg)
	DDX_Text(pDX, IDC_EDIT_HOST, m_host);
	DDX_Text(pDX, IDC_EDIT_OUT, m_out);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy1139Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy1139Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_QUERY, OnQuery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1139Dlg message handlers

BOOL CMy1139Dlg::OnInitDialog()
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

void CMy1139Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1139Dlg::OnPaint() 
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
HCURSOR CMy1139Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy1139Dlg::OnQuery() 
{
	const CString http="http://";
	UpdateData(true);
	m_out="";
	UpdateData(false);
	// TryFTPSite(m_host);
	// TryFTPSite("ftp."+m_host);

	// TryURL(http+m_host);
	// TryURL(http+"www."+m_host);

	// TryGopherSite(m_host);
	// TryGopherSite("gopher."+m_host);

	// TryFinger(m_host);

	TryWhois(m_host);
}

void CMy1139Dlg::TryURL(CString URL) 
{
	CInternetSession session;
	m_out=m_out+"Trying "+URL+"\r\n";
	UpdateData(false);
	CInternetFile * file=NULL;
	try {
		// we know for sure this is an Internet file.so the cast is safe
		file=(CInternetFile*)session.OpenURL(URL);
	}
	catch(CInternetException* pEx) {
		// if anything went wrong.just set file to NULL
		file=NULL;
		pEx->Delete();
	}
	if(file) {
		m_out+="Connection established.\r\n";
		CString line;
		for(int i=0;i<20 && file->ReadString(line);i++)
			m_out=m_out+line+"\r\n";
		file->Close();
		delete file;
	}
	else m_out=m_out+"No server found there.\r\n";
	m_out+="-----------------------------\r\n";
	UpdateData(false);
}

void CMy1139Dlg::TryFTPSite(CString host)
{
	CInternetSession session;
	m_out=m_out+"Trying FTP site"+host+"\r\n";
	UpdateData(false);
	CFtpConnection * connection=NULL;
	try {
		connection=session.GetFtpConnection(host);
	}
	catch(CInternetException *pEx) {
		// if anything went wrong,just set connection to NULL
		connection=NULL;
		pEx->Delete();
	}
	if(connection) {
		m_out+="Connection established.\r\n";
		CString line;
		connection->GetCurrentDirectory(line);
		m_out=m_out+"default directory is"+line+"\r\n";
		connection->Close();
		delete connection;
	}
	else m_out+="No server found there.\r\n";
	m_out+="----------------------\r\n";
	UpdateData(false);
}

void CMy1139Dlg::TryGopherSite(CString host)
{
	CInternetSession session;
	m_out=m_out+"Trying Gopher site "+host+"\r\n";
	UpdateData(false);
	CGopherConnection * connection=NULL;
	try { connection=session.GetGopherConnection(host); }
	catch(CInternetException * pEx) {
		connection=NULL;
		pEx->Delete();
	}
	if(connection) {
		m_out+="Connection established.\r\n";
		CString line;
		CGopherLocator locator=connection->CreateLocator(NULL,
			NULL,GOPHER_TYPE_DIRECTORY);
		line=locator;
		m_out=m_out+"first locator is "+line + "\r\n";
		connection->Close();
		delete connection;
	}
	else m_out+="No server found there.\r\n";
	m_out+="---------------------\r\n";
	UpdateData(false);
}

void CMy1139Dlg::TryFinger(CString host) 
{
	CInternetSession session;
	m_out=m_out+" Trying to Finger " + host + "\r\n";
	UpdateData(false);
	CGopherConnection * connection=NULL;
	// 79为端口号
	try { connection=session.GetGopherConnection(host,NULL,NULL,79); }
	catch(CInternetException * pEx) {
		connection=NULL;
		pEx->Delete();
	}
	if(connection) {
		m_out+="Connection established.\r\n";
		CGopherLocator locator=connection->CreateLocator(NULL,NULL,
			GOPHER_TYPE_TEXT_FILE);
		CGopherFile * file=connection->OpenFile(locator);
		if(file) {
			CString line;
			for(int i=0;i<20 && file->ReadString(line);i++)
				m_out=m_out+line+"\r\n";
			file->Close();
			delete file;
		}
		connection->Close();
		delete connection;
	}
	else m_out+="No server found there.\r\n";
	m_out+="-------------------------\r\n";
	UpdateData(false);
}

void CMy1139Dlg::TryWhois(CString host)
{
	CInternetSession session;
	m_out=m_out+" Trying to Finger " + host + "\r\n";
	UpdateData(false);
	CGopherConnection * connection=NULL;
	// 43为端口号
	try { connection=session.GetGopherConnection(host,NULL,NULL,43); }
	catch(CInternetException * pEx) {
		connection=NULL;
		pEx->Delete();
	}
	if(connection) {
		m_out+="Connection established.\r\n";
		CGopherLocator locator=connection->CreateLocator(NULL,NULL,
			GOPHER_TYPE_TEXT_FILE);
		CGopherFile * file=connection->OpenFile(locator);
		if(file) {
			CString line;
			for(int i=0;i<20 && file->ReadString(line);i++)
				m_out=m_out+line+"\r\n";
			file->Close();
			delete file;
		}
		connection->Close();
		delete connection;
	}
	else m_out+="No server found there.\r\n";
	m_out+="-------------------------\r\n";
	UpdateData(false);
}