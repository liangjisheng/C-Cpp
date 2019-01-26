// 1043Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1043.h"
#include "1043Dlg.h"

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
// CMy1043Dlg dialog

CMy1043Dlg::CMy1043Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy1043Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy1043Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy1043Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy1043Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy1043Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy1043Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOOKHELP, OnLookhelp)
	ON_BN_CLICKED(IDC_CONFIG, OnConfig)
	ON_BN_CLICKED(IDC_SENDMAIL, OnSendmail)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1043Dlg message handlers

BOOL CMy1043Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// ����״̬��
	statu=::CreateStatusWindow(WS_CHILD | WS_VISIBLE,"��ӭʹ�ñ����!",
		this->m_hWnd,IDC_STATU);
	this->SetWindowText("�ʼ��շ��� v1.0");		// ���ô��ڱ���
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
	/*file.Open("״̬�����ļ�.lw",CFile::modeReadWrite);
	char d;
	file.Read(&d,1);
	file.Close();
	if(d=='Y') {
		GetDlgItem(IDC_LOOKHELP)->EnableWindow(false);	// ��ʼ���������
		GetDlgItem(IDC_CONFIG)->EnableWindow(false);
	}
	else
		GetDlgItem(IDC_CONFIG)->EnableWindow(true);
		*/

	GetDlgItem(IDC_CONFIG)->EnableWindow(false);
	GetDlgItem(IDC_SENDER)->EnableWindow(false);
	GetDlgItem(IDC_RECVER)->EnableWindow(false);
	GetDlgItem(IDC_SUBJECT)->EnableWindow(false);
	GetDlgItem(IDC_SENDMAIL)->EnableWindow(false);
	GetDlgItem(IDC_RECVMAIL)->EnableWindow(false);
	GetDlgItem(IDC_MAILTEXT)->EnableWindow(false);
	GetDlgItem(IDC_SENDER)->SetWindowText("���û����Ȳ鿴\"ʹ��ǰ��֪\".");
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy1043Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1043Dlg::OnPaint() 
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
HCURSOR CMy1043Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy1043Dlg::OnLookhelp() 
{
	// TODO: Add your control notification handler code here
	CString str="";
	str+="�������ʹ�÷���: \r\n";
	str+="��һ��: ����SMTP��������������������ַ���˿ں���\r\n";
	str+="�ڶ���: ���÷����˵�ַ���ռ��˵�ַ���ʼ����⣬�ʼ�����.\r\n";
	str+="���У������˵�ַ���ռ��˵�ַ����Ϊ�գ����������Ϊ�ա�\r\n";
	str+="ע�⣬�����Ҫ���ʼ����͵����ˣ������ռ��˵�ַ����ʹ�ö��Ž���ַ���ֿ�����\r\n";
	str+="����: liangjisheng";

	if(MessageBox(str,"title",MB_OK | MB_ICONINFORMATION)==IDOK) {
		GetDlgItem(IDC_LOOKHELP)->SetWindowText("���ܴ���");	// �ȸð�ť����
		GetDlgItem(IDC_LOOKHELP)->EnableWindow(false);
		GetDlgItem(IDC_CONFIG)->EnableWindow(true);
		/*CFile file1("״̬�����ļ�.lw",CFile::modeReadWrite);
		char d='Y';
		file1.Write(&d,sizeof(d));
		file1.Close();*/
	}
}

void CMy1043Dlg::OnConfig() 
{
	// TODO: Add your control notification handler code here
	set.DoModal();
	if(set.m_port>0 && set.m_port<100) {	// �ж϶˿ڷ�Χ
		if(set.m_serveraddr!="") {
			addr.sin_family=AF_INET;
			addr.sin_port=htons(set.m_port);
			// host=set.m_serveraddr.GetBuffer(1);
			addr.sin_addr.S_un.S_addr=inet_addr(set.m_serveraddr.GetBuffer(1));
			s=::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
			if(::connect(s,(sockaddr*)&addr,sizeof(addr))) {
				GetDlgItem(IDC_SENDER)->EnableWindow(true);
				GetDlgItem(IDC_RECVER)->EnableWindow(true);
				GetDlgItem(IDC_SUBJECT)->EnableWindow(true);
				GetDlgItem(IDC_SENDMAIL)->EnableWindow(true);
				GetDlgItem(IDC_RECVMAIL)->EnableWindow(true);
				GetDlgItem(IDC_MAILTEXT)->EnableWindow(true);
				GetDlgItem(IDC_SENDER)->SetWindowText("");
				::SendMessage(statu,SB_SETTEXT,0,(long)"SMTP��������Ϣ���óɹ����Ѿ����ӷ�����");
			}
			else 
				MessageBox("�����������ӻ��������÷�������Ϣ!");
			char buf[4];
			recv(s,buf,4,0);
			if(atoi(buf)==220) MessageBox("������׼������");
			else MessageBox("��������������ʧ��");
		}
		else
			MessageBox("��������ַ����Ϊ��");
	}
	else 
		MessageBox("�˿ڷ�Χ(0~100)");
}

void CMy1043Dlg::OnSendmail() 
{
	// TODO: Add your control notification handler code here
	char buf[4];
	CString data="Data: Tue,04,Feb 2009 21:18:03+0800\r\n";
	CString sender=" MAIL FROM";
	CString recver=" REPT TO:";
	CString subject=" Subject:";
	CString strsendtext,r,s1,mailtext;
	GetDlgItem(IDC_SENDER)->GetWindowText(strsendtext);
	GetDlgItem(IDC_RECVER)->GetWindowText(r);
	GetDlgItem(IDC_SUBJECT)->GetWindowText(s1);
	GetDlgItem(IDC_MAILTEXT)->GetWindowText(mailtext);
	sender+=strsendtext;
	recver+=r;
	subject+=s1;
	CString sendmail=CString("HELO")+sender.GetBuffer(1)+recver.GetBuffer(1);
	sendmail=sendmail+"DATA\r\n"+subject.GetBuffer(1)+mailtext.GetBuffer(1);
	sendmail=sendmail+"QUIT\r\n"+"\0";
	send(s,sendmail,sizeof(sendmail),0);
	recv(s,buf,4,0);
	if(buf!=NULL) {
		if(atoi(buf)==250)
			::SendMessage(statu,SB_SETTEXT,0,(long)"�ʼ����ͳɹ�");
		else
			::SendMessage(statu,SB_SETTEXT,0,(long)"�ʼ�����ʧ��");
	}
	else
		::SendMessage(statu,SB_SETTEXT,0,(long)"�ʼ����ڷ���");
}
