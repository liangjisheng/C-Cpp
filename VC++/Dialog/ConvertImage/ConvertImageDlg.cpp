// ConvertImageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ConvertImage.h"
#include "ConvertImageDlg.h"

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
// CConvertImageDlg dialog

CConvertImageDlg::CConvertImageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConvertImageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CConvertImageDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CConvertImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CConvertImageDlg)
	DDX_Control(pDX, IDC_EDIT_IMAGENAME, m_ImageName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CConvertImageDlg, CDialog)
	//{{AFX_MSG_MAP(CConvertImageDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OK, OnOk)
	ON_BN_CLICKED(IDC_CONVERT, OnConvert)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CConvertImageDlg message handlers

BOOL CConvertImageDlg::OnInitDialog()
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
	
	// ��ʼ��GDI+,�����ð�ť��״̬
	GdiplusStartup(&m_pGdiToken,&m_Gdiplus,NULL);	// ��ʼ��GDI+
	CButton* pButton = NULL;
	pButton = (CButton*)GetDlgItem(IDC_JPEG);	// ��ȡ��ť����
	if(pButton != NULL)
		pButton->SetCheck(BST_CHECKED);			// ѡ�а�ť
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CConvertImageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CConvertImageDlg::OnPaint() 
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
HCURSOR CConvertImageDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CConvertImageDlg::OnCancel() 
{
	// �Ի���ر�ʱж��GDI+
	GdiplusShutdown(m_pGdiToken);	// �ͷ�GDI+
	
	CDialog::OnCancel();
}


int CConvertImageDlg::GetCodesClsid(const WCHAR* format,CLSID* pClsid)
{
	UINT num = 0;				// ��¼ͼ����������
	UINT size = 0;				// ��¼���������С
	ImageCodecInfo* pImageCodecInfo = NULL;	// ����ͼ�������Ϣ
	GetImageEncodersSize(&num,&size);	// ��ȡͼ�����������ͱ��������С
	if(0 == size)
		return -1;
	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if(NULL == pImageCodecInfo)
		return -1;
	GetImageEncoders(num,size,pImageCodecInfo);		// ��ȡͼ�����
	for(UINT j=0;j<num;j++)					// ƥ��ͼ���ʽ
	{
		// �Ƚ��ַ���
		if(wcscmp(pImageCodecInfo[j].MimeType,format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;	// ��ȡͼ���ʽ��CLSID
			return j;
		}
	}
	return -1;
}

void CConvertImageDlg::OnOk() 
{
	// ����һ���ļ��򿪶Ի���
	CFileDialog dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		"ͼ���ļ�|*.bmp;*.jpeg;*.jpg;*.gif|�����ļ�|*.*||",this);
	if(dlg.DoModal() == IDOK)
	{
		m_FileName = dlg.GetPathName();		// ��ȡ�ļ�����·��
		m_ImageName.SetWindowText(m_FileName);
	}
}


BOOL CConvertImageDlg::TestButtonState(UINT BTNID)
{
	CButton* pButton = NULL;
	pButton = (CButton*)GetDlgItem(BTNID);
	if(NULL != pButton && pButton->GetCheck() == BST_CHECKED)
		return TRUE;
	return FALSE;
}

void CConvertImageDlg::OnConvert() 
{
	if(TestButtonState(IDC_JPEG))	// �ж�JPEG��ѡ��ť�Ƿ�ѡ��
	{
		CFileDialog dlg(FALSE,"jepg","convert",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
			"�����ļ�|*.*||",this);		// ����Ի���
		if(dlg.DoModal() == IDOK)
		{
			CString SaveName = dlg.GetPathName();
			Bitmap bmp(m_FileName.AllocSysString());	// ����һ��λͼ����
			CLSID clsid;
			GetCodesClsid(L"image/jpeg",&clsid);		// ��ȡJPEGͼ���CLSID
			bmp.Save(SaveName.AllocSysString(),&clsid);	// ����ΪJPEGͼ���ʽ
		}
	}
	else if(TestButtonState(IDC_BMP))
	{
		CFileDialog dlg(FALSE,"bmp","convert",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
			"�����ļ�|*.*||",this);		// ����Ի���
		if(dlg.DoModal() == IDOK)
		{
			CString SaveName = dlg.GetPathName();
			Bitmap bmp(m_FileName.AllocSysString());	// ����һ��λͼ����
			CLSID clsid;
			GetCodesClsid(L"image/bmp",&clsid);		// ��ȡJPEGͼ���CLSID
			bmp.Save(SaveName.AllocSysString(),&clsid);	// ����ΪJPEGͼ���ʽ
		}
	}
	else
	{
		CFileDialog dlg(FALSE,"gif","convert",OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
			"�����ļ�|*.*||",this);		// ����Ի���
		if(dlg.DoModal() == IDOK)
		{
			CString SaveName = dlg.GetPathName();
			Bitmap bmp(m_FileName.AllocSysString());	// ����һ��λͼ����
			CLSID clsid;
			GetCodesClsid(L"image/gif",&clsid);		// ��ȡJPEGͼ���CLSID
			bmp.Save(SaveName.AllocSysString(),&clsid);	// ����ΪJPEGͼ���ʽ
		}
	}
}
