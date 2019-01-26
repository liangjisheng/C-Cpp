
// MultiLanguagesDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MultiLanguages.h"
#include "MultiLanguagesDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


CMultiLanguagesDlg::CMultiLanguagesDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMultiLanguagesDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_bRestartFlag = false;
}

void CMultiLanguagesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMultiLanguagesDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMultiLanguagesDlg::OnBnClickedButton1)
	ON_COMMAND(ID_LANGUAGE_TRANS, &CMultiLanguagesDlg::OnLanguageTrans)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CMultiLanguagesDlg ��Ϣ�������

BOOL CMultiLanguagesDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMultiLanguagesDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMultiLanguagesDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMultiLanguagesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMultiLanguagesDlg::OnBnClickedButton1()
{
	static int s_iClickTime = 0;
	s_iClickTime++;
	CString str = _T("");
	CString strnum = _T("");
	str.LoadString(IDC_STATIC_STRING_SAMPLE);
	strnum.Format(_T("%d"), s_iClickTime);
	str = str + strnum;
	AfxMessageBox(str);
}


// �����ڳ�ʼ��ʱ��͵�������Դ�ļ�����ͨ��SetThreadUILanguage������
// �߳����Ժ󣬴��ڵ���Դ��������ģ�����Ҫͨ������������װ����Դ
// ��Ϊ�����д��ڶ������̱߳���������ص���Դ�����
// �������������һ�ֽϿ�ݵĸ������Ի����ķ�����
void CMultiLanguagesDlg::OnLanguageTrans()
{
	// ��ȡ��ǰ�߳����ԣ������ݵ�ǰ�߳����Խ��������л�
	// GetThreadLocale()���������win7���ǲ����õ�
	// LCID lcidNew = GetThreadLocale();
	LCID lcidNew = GetThreadUILanguage();
	if(LANG_ENGLISH == PRIMARYLANGID(LANGIDFROMLCID(lcidNew)))
		lcidNew = MAKELCID(MAKELANGID(LANG_CHINESE, SUBLANG_CHINESE_SIMPLIFIED), SORT_DEFAULT);
	else
		lcidNew = MAKELCID(MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), SORT_DEFAULT);

	CFile file;
	file.Open(_T("Language.ini"), CFile::modeWrite | CFile::modeCreate | CFile::typeBinary);
	file.Write(&lcidNew, sizeof(lcidNew));
	file.Close();

	m_bRestartFlag = true;
	PostMessage(WM_CLOSE);
}


void CMultiLanguagesDlg::OnClose()
{
	if(m_bRestartFlag)
	{
		CString strFileName = _T("");
		GetModuleFileName(NULL, strFileName.GetBuffer(MAX_PATH), MAX_PATH);
		ShellExecute(NULL, _T(""), strFileName, NULL, NULL, SW_SHOWNORMAL);
		strFileName.ReleaseBuffer();
	}

	CDialogEx::OnClose();
}


// �뱾�ػ���صĺ������������£�
// GetSystemDefaultLCID
// GetSystemDefaultLocaleName
// GetUserDefaultLCID
// GetUserDefaultLocaleName
// SetThreadLocale
// GetThreadLocale
// GetThreadUILanguage
// SetThreadUILanguage

// MAKELCID
// MAKELANGID
// LCIDToLocalName
// LocalNameToLCID
// LANGIDFROMLCID
// PRIMARYLANGID

// LCID
// LANGID
// LANG_CHINESE 0x04
// LANG_ENGLISH 0x09
