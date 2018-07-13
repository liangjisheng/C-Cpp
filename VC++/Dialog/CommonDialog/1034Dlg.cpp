// 1034Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1034.h"
#include "1034Dlg.h"

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
// CMy1034Dlg dialog

CMy1034Dlg::CMy1034Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy1034Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy1034Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	pfindreplacedlg=new CFindReplaceDialog;
}

void CMy1034Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy1034Dlg)
	DDX_Control(pDX, IDC_TEXT, m_edit);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy1034Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy1034Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_COLOR_DIALOG, OnColorDialog)
	ON_BN_CLICKED(IDC_FONT_DIALOG, OnFontDialog)
	ON_BN_CLICKED(IDC_PAGESETUP_DIALOG, OnPagesetupDialog)
	ON_BN_CLICKED(IDC_FINDREPLACE_DIALOG, OnFindreplaceDialog)
	ON_MESSAGE(WM_FINDREPLACEMESSAGE,OnFindReplace)
	ON_EN_CHANGE(IDC_TEXT, OnChangeText)
	ON_BN_CLICKED(IDC_FILE_DIALOG, OnFileDialog)
	ON_BN_CLICKED(IDC_FILE_DIALOG_SAVE, OnFileDialogSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1034Dlg message handlers

BOOL CMy1034Dlg::OnInitDialog()
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

void CMy1034Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1034Dlg::OnPaint() 
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
HCURSOR CMy1034Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy1034Dlg::OnColorDialog() 
{
	// TODO: Add your control notification handler code here
	CColorDialog colordlg;
	COLORREF m_color;
	if(colordlg.DoModal()==IDOK)
		m_color=colordlg.GetColor();
}

void CMy1034Dlg::OnFontDialog() 
{
	// TODO: Add your control notification handler code here
	CFontDialog fontdlg;
	fontdlg.DoModal();
}

void CMy1034Dlg::OnPagesetupDialog() 
{
	// TODO: Add your control notification handler code here
	CPageSetupDialog pagesetupdlg;
	pagesetupdlg.DoModal();
}

void CMy1034Dlg::OnFindreplaceDialog() 
{
	// TODO: Add your control notification handler code here
	CString findstring="lishuyu";
	CString replacestring="li";
	// ��һ������Ϊtrue��ʾֻ�ǲ��ң���Ϊfalse��ʾ�����滻
	// ���ĸ�����Ϊ���ҷ��� FR_DOWN ��ʾ���²���
	// ���һ������Ϊ�����ڣ�Ĭ��ΪNULL
	pfindreplacedlg->Create(false,findstring,replacestring,FR_DOWN,NULL);
	pfindreplacedlg->ShowWindow(SW_SHOW);
}

long CMy1034Dlg::OnFindReplace(WPARAM wParam,LPARAM lParam) 
{
	/*BOOL if_whole_word=pfindreplacedlg->MatchWholeWord();	// ƥ��ȫ�ַ�
	BOOL if_case=pfindreplacedlg->MatchCase();	// ƥ���Сд
	BOOL if_down=pfindreplacedlg->SearchDown();	// ���ҷ���
	bool last_one=false;

	do{
		CString strfind,strtext;
		int index=0,nindex=-1;
		m_edit.GetWindowText(strtext);	// ���Ի����ȡ�ı�
		// �����滻�Ի����ϻ�ȡҪ�ҵ��ַ���strfind
		strfind=pfindreplacedlg->GetFindString();
		int len=strfind.GetLength();
		if(if_down) {	// ������
			if(nindex!=strtext.GetLength()-1)
				nindex++;
			else
				MessageBox("�Ѿ������ҵ��ļ�β","�����滻",MB_OK | MB_ICONINFORMATION);
			index=strtext.Find(strfind,nindex); // ��nindex��������ʼ����
		}
		else{
			if(nindex!=0) nindex--;
			else 
				MessageBox("�Ѿ������ҵ��ļ�ͷ","�����滻",MB_OK | MB_ICONINFORMATION);
			string str=strtext.GetBuffer(0);
			index=str.find_last_of(strfind,nindex);
			strtext.ReleaseBuffer();
		}
		if(index!=-1)
			m_edit.SetSel(index,index+len);
		else {
			last_one=true;
			MessageBox("�Ѿ����ҵ����һ����", "�����滻", MB_OK | MB_ICONINFORMATION);
		}
		if(pfindreplacedlg->ReplaceCurrent() || pfindreplacedlg->ReplaceAll()) {
			CString strreplace;
			m_edit.ReplaceSel(pfindreplacedlg->GetReplaceString(),true);
		}
		nindex=index;
	}while(pfindreplacedlg->ReplaceAll() && !last_one);
	m_edit.SetFocus();*/

	return 0;
}

void CMy1034Dlg::OnChangeText() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CMy1034Dlg::OnFileDialog() 
{	
	// ԭ��
	//CFileDialog::CFileDialog( BOOL bOpenFileDialog, LPCTSTR lpszDefExt = NULL,
    //    LPCTSTR lpszFileName = NULL,
    //   DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
    //   LPCTSTR lpszFilter = NULL, CWnd* pParentWnd = NULL );
	// TODO: Add your control notification handler code here
	char szFilter[]={"�ı��ļ�(*.txt)|*.txt|�������ļ�(*.dat)|*.dat|All Files(*.*)|*.*||"};
	CString m_strFilePath,m_strFileName,m_strFileTitle;
	CString m_strFolderPath,strtext;
	GetDlgItemText(IDC_TEXT,strtext);
	// ��һ������trueΪ���ļ��Ի���falseΪ�����ļ��Ի���
	CFileDialog filedlg(true,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,szFilter,NULL);
	if(filedlg.DoModal()==IDOK) {
		m_strFilePath=filedlg.GetPathName();		// �ļ�·��
		m_strFileName=filedlg.GetFileName();		// �ļ���������չ��
		m_strFileTitle=filedlg.GetFileTitle();		// �ļ�����������չ��
		//m_strFolderPath=filedlg.GetFolderPath();	// ѡ���ļ�Ŀ¼
		strtext+=m_strFilePath+"\r\n"+m_strFileName+"\r\n"+m_strFileTitle+"\r\n";
		SetDlgItemText(IDC_TEXT,strtext);
	}
}

void CMy1034Dlg::OnFileDialogSave() 
{
	// TODO: Add your control notification handler code here
	TCHAR szFilter[]=_T("�ı��ļ�(*.*)|*.txt|Դ�ļ�(*.cpp)|*.cpp|All Files(*.*)|*.*||");
	// ���챣���ļ��Ի���
	CFileDialog filedlg(false,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		szFilter,this);
	CString m_strFilePath,m_strFileName,m_strFileTitle;
	CString strtext,m_strFolderPath;
	GetDlgItemText(IDC_TEXT,strtext);
	if(filedlg.DoModal()==IDOK) {
		m_strFilePath=filedlg.GetPathName();
		m_strFileName=filedlg.GetFileName();
		m_strFileTitle=filedlg.GetFileTitle();
		// m_strFolderPath=filedlg.GetFolderPath();
		strtext=strtext+m_strFilePath+"\r\n"+m_strFileName+"\r\n"+
			m_strFileTitle+"\r\n";
		SetDlgItemText(IDC_TEXT,strtext);
	}
}
