
// 1120-1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "1120-1.h"
#include "1120-1Dlg.h"
#include "afxdialogex.h"

//#ifdef _DEBUG
//	#include "vld.h"
//#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int CALLBACK BrowseCallBackFun(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData);

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


CMy11201Dlg::CMy11201Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy11201Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy11201Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy11201Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy11201Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMy11201Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMy11201Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMy11201Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CMy11201Dlg ��Ϣ�������

BOOL CMy11201Dlg::OnInitDialog()
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

void CMy11201Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy11201Dlg::OnPaint()
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
HCURSOR CMy11201Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy11201Dlg::OnBnClickedButton1()
{
	CString ReturnPath;
	TCHAR szPath[_MAX_PATH] = {0};			// ����·������
	BROWSEINFO bi;
	ZeroMemory(&bi, sizeof(BROWSEINFO));
	bi.hwndOwner = GetSafeHwnd();			// HWND���	or bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;						// ���ÿ�ʼ����λ�ã�ΪNULLĬ�ϴ�the desktop folder��ʼ
	bi.lpszTitle =_T("Choose a directory");	// ��ʾλ�ڶԻ������ϲ��ı���
	bi.pszDisplayName = szPath;				// ��ѡ�е��ļ��л�������ַ
	bi.ulFlags = BIF_BROWSEINCLUDEFILES;	// ָ���Ի������ۺ͹��ܵı�־,BIF_BROWSEINCLUDEFILES��ʾ�ļ�Ҳ�ܱ�ѡ��
	bi.lpfn = NULL;							// �����¼��Ļص�����
	bi.lParam = NULL;						// Ӧ�ó��򴫸��ص������Ĳ���
	bi.iImage = 0;							// �ļ��жԻ����ͼƬ����

	// SHBrowseForFolder������ʾһ�����û�����ѡ���ļ��еĶԻ���
	// ����ֵ��ָ��ѡ�����ļ������Ӧ����ѡ���Ŀ¼��ַ��·����ʶ��ָ��
	LPITEMIDLIST pItemIDList = SHBrowseForFolder(&bi);
	if(pItemIDList)
	{
		// ��·����ʶ��ָ��ת��Ϊ·��
		if(SHGetPathFromIDList(pItemIDList,szPath))	// �ж��Ƿ����ļ���·��
			ReturnPath = szPath;					
	}
	else
		ReturnPath = "";	// ·��Ϊ��
	
	AfxMessageBox(ReturnPath);
}

int CALLBACK BrowseCallBackFun(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	switch (uMsg)
	{
	case BFFM_INITIALIZED:	// ѡ���ļ��жԻ����ʼ��	
		// ����Ĭ��·��
		::SendMessage(hwnd, BFFM_SETSELECTION, TRUE, lpData);

		// ��STATUSTEXT������ʾ��ǰ·��
		::SendMessage(hwnd, BFFM_SETSTATUSTEXT, 0, lpData);

		// ����ѡ���ļ��жԻ���ı���
		::SetWindowText(hwnd, TEXT("�������ø�����Ŀ¼"));
		break;

	case BFFM_SELCHANGED:	// ѡ���ļ��б��ʱ
		{
			TCHAR pszPath[MAX_PATH] = {0};
			// ��ȡ��ǰ·��
			SHGetPathFromIDList((LPCITEMIDLIST)lParam, pszPath);
			// ��STATUSTEXT��������ʾ��ǰ·��
			::SendMessage(hwnd, BFFM_SETSTATUSTEXT, TRUE, (LPARAM)pszPath);
		}
		break;
	}

	return 0;
}


void CMy11201Dlg::OnBnClickedButton2()
{
	CString ReturnPath = _T("");
	TCHAR szPath[_MAX_PATH] = {0};			// ����·������
	BROWSEINFO bi;
	ZeroMemory(&bi, sizeof(BROWSEINFO));
	bi.hwndOwner = GetSafeHwnd();			// HWND���	or bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;						// ���ÿ�ʼ����λ�ã�ΪNULLĬ�ϴ�the desktop folder��ʼ
	bi.lpszTitle =_T("Choose a directory");	// ��ʾλ�ڶԻ������ϲ��ı���
	bi.pszDisplayName = szPath;				// ��ѡ�е��ļ��л�������ַ
	bi.ulFlags = BIF_RETURNONLYFSDIRS | BIF_STATUSTEXT | BIF_USENEWUI;	// ָ���Ի������ۺ͹��ܵı�־,BIF_BROWSEINCLUDEFILES��ʾ�ļ�Ҳ�ܱ�ѡ��
	bi.lpfn = BrowseCallBackFun;			// �����¼��Ļص�����
	bi.lParam = (LPARAM)_T("D:\\");		// Ӧ�ó��򴫸��ص������Ĳ���
	bi.iImage = 0;							// �ļ��жԻ����ͼƬ����

	// SHBrowseForFolder������ʾһ�����û�����ѡ���ļ��еĶԻ���
	// ����ֵ��ָ��ѡ�����ļ������Ӧ����ѡ���Ŀ¼��ַ��·����ʶ��ָ��
	LPITEMIDLIST pItemIDList = SHBrowseForFolder(&bi);
	if(pItemIDList)
	{
		// ��·����ʶ��ָ��ת��Ϊ·��
		if(SHGetPathFromIDList(pItemIDList,szPath))	// �ж��Ƿ����ļ���·��
			ReturnPath = szPath;					
	}
	else
		ReturnPath = _T("");	// ·��Ϊ��

	AfxMessageBox(ReturnPath);
}


// ����ָ��������ָ�����ļ��д��ڣ���������˫��ĳ���ļ��д�
//CSIDL_DRIVES���ҵĵ���
//CSIDL_BITBUCKET ����վ
//CSIDL_CONTROLS �������
//CSIDL_DESKTOP Windows ����Desktop
//CSIDL_DESKTOPDIRECTORY Desktop��Ŀ¼
//CSIDL_DRIVES �ҵĵ���
//CSIDL_FONTS ����Ŀ¼
//CSIDL_NETHOOD �����ھ�
//CSIDL_NETWORK �����ھ�����Ŀ¼
//CSIDL_PERSONAL �ҵ��ĵ�
//CSIDL_PRINTERS ��ӡ��
//CSIDL_PROGRAMS ������
//CSIDL_RECENT ����򿪵��ĵ�
//CSIDL_SENDTO �����͵����˵���
//CSIDL_STARTMENU �����������˵���
//CSIDL_STARTUP ����Ŀ¼
//CSIDL_TEMPLATES �ĵ�ģ��
void CMy11201Dlg::OnBnClickedButton3()
{
	// ���汻ע�͵��ļ��仰����û�������ã���ע�ʹ򿪵õ��Ľ����һ����

	//LPMALLOC pMalloc;
	LPITEMIDLIST pidl;
	if (SUCCEEDED(SHGetSpecialFolderLocation(NULL, CSIDL_DRIVES, &pidl)))
	{
		SHELLEXECUTEINFO sei;
		ZeroMemory(&sei, sizeof(sei));
		sei.cbSize = sizeof(sei);
		sei.fMask = SEE_MASK_IDLIST;
		sei.lpIDList = pidl;
		sei.lpVerb = _T("open");
		sei.hwnd = AfxGetMainWnd()->GetSafeHwnd();
		sei.nShow = BIF_RETURNONLYFSDIRS;
		ShellExecuteEx(&sei);

		//if (SUCCEEDED(SHGetMalloc(&pMalloc)))
		//{
		//	pMalloc->Free(pidl);
		//	pMalloc->Release();
		//}
	}
}

// �ļ�Ŀ¼ת��LPITEMIDLIST
void CMy11201Dlg::OnBnClickedButton4()
{
	// OpenDir(_T("C:\\"));
	OpenDir1(_T("D:\vs2010_projects"));
}

void CMy11201Dlg::OpenDir(LPTSTR pszPath)
{
	// ֱ�Ӵ�ĳ��������Ŀ¼
	LPITEMIDLIST pidl;
	LPMALLOC pMalloc;
	pidl = ParsePidlFromPath(pszPath);

	SHELLEXECUTEINFO sei;
	ZeroMemory(&sei, sizeof(sei));
	sei.cbSize = sizeof(sei);
	sei.fMask = SEE_MASK_IDLIST;
	sei.lpIDList = pidl;
	sei.lpVerb = _T("open");
	sei.hwnd = AfxGetMainWnd()->GetSafeHwnd();
	sei.nShow = BIF_RETURNONLYFSDIRS;
	ShellExecuteEx(&sei);

	if (SUCCEEDED(SHGetMalloc(&pMalloc)))
	{
		pMalloc->Free(pidl);
		pMalloc->Release();
	}
}

void CMy11201Dlg::OpenDir1(LPTSTR pszPath)
{
	BROWSEINFO bi;
	ZeroMemory(&bi, sizeof(BROWSEINFO));
	TCHAR szName[MAX_PATH] = {0};
	bi.pidlRoot = ParsePidlFromPath(pszPath);
	bi.hwndOwner = GetSafeHwnd();
	bi.pszDisplayName = szName;
	bi.lpszTitle = _T("browse directory");
	bi.ulFlags = BIF_RETURNONLYFSDIRS;

	LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
	if (NULL != pidl && SHGetPathFromIDList(pidl, szName))
		AfxMessageBox(szName);
	else
		AfxMessageBox(_T(""));
}

LPITEMIDLIST CMy11201Dlg::ParsePidlFromPath(LPTSTR pszPath)
{
	OLECHAR szOldChar[MAX_PATH] = {0};
	LPSHELLFOLDER IpsfDeskTop;
	LPITEMIDLIST lpifq;
	ULONG ulEaten, ulAttribs;
	HRESULT hres;

	SHGetDesktopFolder(&IpsfDeskTop);
	hres = IpsfDeskTop->ParseDisplayName(NULL, NULL, pszPath, &ulEaten, &lpifq, &ulAttribs);
	hres = IpsfDeskTop->Release();

	if (FAILED(hres))
		return NULL;
	return lpifq;
}
