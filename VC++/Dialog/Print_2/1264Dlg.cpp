// 1264Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1264.h"
#include "1264Dlg.h"

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
// CMy1264Dlg dialog

CMy1264Dlg::CMy1264Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy1264Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy1264Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_LeftMargin = 0;
	m_TopMargin = 0;
}

void CMy1264Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy1264Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy1264Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy1264Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_PRINTSET,OnPrintSet)
	ON_BN_CLICKED(IDC_PRINT,OnPrint)
	ON_BN_CLICKED(IDC_EXIT,OnExit)
	ON_BN_CLICKED(IDC_PAGESETUP,OnPageSetup)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy1264Dlg message handlers

BOOL CMy1264Dlg::OnInitDialog()
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
	
	m_ImageList.Create(32,32,ILC_COLOR16 | ILC_MASK,1,1);
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON2));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON3));
	m_ImageList.Add(AfxGetApp()->LoadIcon(IDI_ICON4));
	UINT array[4] = {10000,10001,10002,10003};
	m_ToolBar.Create(this);
	m_ToolBar.SetButtons(array,4);		// ���ù�������ť����
	m_ToolBar.SetButtonText(0,"��ӡ����");	// ���ù�������ť�ı�
	m_ToolBar.SetButtonText(1,"��ӡ");
	m_ToolBar.SetButtonText(2,"�˳�");
	m_ToolBar.SetButtonText(3,"ҳ������");
	
	m_ToolBar.GetToolBarCtrl().SetImageList(&m_ImageList);	// ����ͼ���б�
	m_ToolBar.SetSizes(CSize(70,60),CSize(32,32));	// ���ð�ť��ͼ��Ĵ�С
	m_ToolBar.EnableToolTips(TRUE);		// ���������ʾ����
	// ��ʾ������
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);
	str[0] = "����һ���ƣ����������ס�\r\n";
	str[1] = "�ٱ������£���Ӱ�����ˡ�\r\n";
	str[2] = "�¼Ȳ�������Ӱͽ������\r\n";
	str[3] = "�ݰ��½�Ӱ�������뼰����\r\n";
	str[4] = "�Ҹ����ǻ�������Ӱ���ҡ�\r\n";
	str[5] = "��ʱͬ������������ɢ��\r\n";
	str[6] = "���������Σ��������ƺ���\r\n";
	m_IsWay = TRUE;		// ����Ĭ�ϴ�ӡ����
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy1264Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy1264Dlg::OnPaint() 
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
HCURSOR CMy1264Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

HBRUSH CMy1264Dlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// ���Ի��򱳾�����Ϊ��ɫ
	if(nCtlColor == CTLCOLOR_DLG)
	{
		// ����ʹ�þֲ�������ֻ���ڶ��ϴ���
		//CBrush brush;
		//brush.CreateSolidBrush(RGB(255,0,0));
		//return (HBRUSH)(brush.m_hObject);

		CBrush *brush;
		brush = new CBrush(RGB(255,255,255));
		return (HBRUSH)(brush->m_hObject);
	}
		
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CMy1264Dlg::DrawText(CDC* pDC,BOOL IsPrinted)
{
	if(!IsPrinted)	// Ԥ��ʱ���ñ���Ϊ1
	{
		rateX = 1;	
		rateY = 1;
	}
	else
		pDC->StartDoc("print start");

	int LeftMargin = int((m_LeftMargin / 25.4) * printX);
	int TopMargin = int((m_TopMargin / 25.4) * printY);

	m_Font.CreatePointFont(120,"����",pDC);
	pDC->SelectObject(&m_Font);
	for(int i=0;i<7;i++)
		pDC->TextOut(int(50*rateX),int((80+i*30)*rateY),str[i]);

	if(IsPrinted)
		pDC->EndDoc();	// ������ӡ
	m_Font.DeleteObject();
}

void CMy1264Dlg::OnPrintSet()
{
	DWORD dwflags = PD_ALLPAGES | PD_NOPAGENUMS | PD_USEDEVMODECOPIES
		| PD_SELECTION | PD_HIDEPRINTTOFILE;	// ����"��ӡ����"�Ի�������
	CPrintDialog dlg(TRUE,dwflags,NULL);		// ����"��ӡ����"�Ի���
	if(dlg.DoModal() == IDOK)
	{
		LPDEVMODE dev = dlg.GetDevMode();		// ��ô�ӡ����Ϣ
		if(dev->dmOrientation == DMORIENT_PORTRAIT)		// �ж��Ƿ�Ϊ�����ӡ
			m_IsWay = TRUE;		// �����ӡ
		else
			m_IsWay = FALSE;	// �����ӡ
	}
}

void CMy1264Dlg::OnPrint()
{
	DWORD dwflags = PD_ALLPAGES | PD_NOPAGENUMS | PD_USEDEVMODECOPIES
		| PD_SELECTION | PD_HIDEPRINTTOFILE;	// ����"��ӡ"�Ի�������
	CPrintDialog dlg(FALSE,dwflags,NULL);		// ����"��ӡ"�Ի���
	if(dlg.DoModal() == IDOK)
	{
		LPDEVMODE dev = dlg.GetDevMode();
		if(m_IsWay)
			dev->dmOrientation = DMORIENT_PORTRAIT;		// ���������ӡ
		else
			dev->dmOrientation = DMORIENT_LANDSCAPE;	// ���ú����ӡ

		CDC dc;		// �豸������
		dc.Attach(dlg.CreatePrinterDC());	// ������ӡ���豸������
		printX = dc.GetDeviceCaps(LOGPIXELSX);		// ��ô�ӡ������
		printY = dc.GetDeviceCaps(LOGPIXELSY);
		rateX = (double)(printX)/screenX;			// ��Ļ���ӡ��֮��ı���
		rateY = (double)(printY)/screenY;
		DrawText(&dc,TRUE);		// ��ӡ�ı�
	}
}

void CMy1264Dlg::OnExit()
{
	CDialog::OnCancel();
}

void CMy1264Dlg::OnPageSetup()
{
	CPageSetupDialog dlg;
	if(dlg.DoModal() == IDOK)
	{
		CRect rect,minRect;
		dlg.GetMargins(&rect,&minRect);
		m_LeftMargin = rect.left / 100;
		m_TopMargin = rect.top / 100;
	}
}