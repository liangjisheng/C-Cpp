
// 1207-1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1207-1.h"
#include "1207-1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
// MFC����operator new����Ϊ�˷��㶨λ�ڴ�й©�����غ��operator new
// ���¼���������ÿ���ڴ��Ӧ��__FILE__��__LINE__��Ϣ
#define new DEBUG_NEW
// #include <vector>
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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

CMy12071Dlg::CMy12071Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMy12071Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy12071Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy12071Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CAPTURESCREEN_1, &CMy12071Dlg::OnBnClickedButtonCapturescreen1)
	ON_BN_CLICKED(IDC_BUTTON_CAPTURESCREEN_2, &CMy12071Dlg::OnBnClickedButtonCapturescreen2)
	ON_BN_CLICKED(IDC_CAPTURESCREEN_GDI, &CMy12071Dlg::OnBnClickedCapturescreenGdi)
	ON_BN_CLICKED(IDC_BUTTON_GDIDRAWLINE, &CMy12071Dlg::OnBnClickedButtonGdidrawline)
	ON_BN_CLICKED(IDC_BUTTON_GDI_1, &CMy12071Dlg::OnBnClickedButtonGdi1)
END_MESSAGE_MAP()


// CMy12071Dlg message handlers

BOOL CMy12071Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy12071Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMy12071Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMy12071Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy12071Dlg::OnBnClickedButtonCapturescreen1()
{
	// ���m_hWnd�����Ӧ�Ĵ���δ�ö�(TopMost),���ö�����
	if (!(::GetWindowLong(this->m_hWnd, GWL_EXSTYLE) & WS_EX_TOPMOST))
		::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	CString strImageSavePath = _T("screen.bmp");
	ScreenCapture(this->m_hWnd, 32, strImageSavePath);
}

/**
 * ��ȡ����ͼƬ�������浽����
 * hWnd: ���ھ��
 * lpFileName: ������ļ���
 * wbitCount: λ��
 * lpRect: ���ڴ�С
 * ����λͼ���
*/
HBITMAP CMy12071Dlg::ScreenCapture(HWND hWnd, WORD wbitCount, LPCTSTR lpFileName /* = NULL */)
{
	RECT rc;

	// ָ����Ļ����
	//rc = {0, 0, 800, 500};

	// ��ȡָ�����ڵ���Ļ����
	::GetWindowRect(hWnd, &rc);

	HBITMAP hBitmap;
	//ͨ��ָ��DISPLAY����ȡһ����ʾ�豸(��ʾ��)�����Ļ���
	HDC hScreenDC = CreateDC(_T("DISPLAY"), NULL, NULL, NULL);
	// ����һ����ָ���豸���ݵ��ڴ��豸�����Ļ���(DC)
	HDC hmemDC = CreateCompatibleDC(hScreenDC);

	//��ȡָ���豸�����ܲ������˴���ȡ��Ļ��ȣ�
	int nScreenWidth = GetDeviceCaps(hScreenDC, HORZRES);
	//��ȡָ���豸�����ܲ������˴���ȡ��Ļ�߶ȣ�
	int nScreenHeight = GetDeviceCaps(hScreenDC, VERTRES);
	HBITMAP hOldBM;
	PVOID lpData;	// �ڴ����ɹ����ص�ָ���������ڴ����׵�ַָ��
	int startX = rc.left;	// ��ͼXλ��
	int startY = rc.top;	// ��ͼYλ��
	int width = rc.right - rc.left;		// ��ͼ���
	int height = rc.bottom - rc.top;	// ��ͼ�߶�

	// BITMAPINFOHEADER�ṹ�������ĳ�Ա������ͼ��ĳߴ硢ԭʼ�豸����ɫ��ʽ���Լ�����ѹ������
	BITMAPINFOHEADER bmInfo;
	BITMAPFILEHEADER bmFileHeader;
	HANDLE bmFile, hpal, holdPal = NULL;
	DWORD dwWritten;

	// ����һ�ų�width����height�Ļ��������ں������ͼ��
	hBitmap = CreateCompatibleBitmap(hScreenDC, width, height);
	// ѡ��һ����ָ�����豸�����Ļ����У����¶����滻��ǰ����ͬ���͵Ķ���
	hOldBM = (HBITMAP)SelectObject(hmemDC, hBitmap);
	// �ú�����ָ����Դ�豸���������е����ؽ���λ�飨bit_block��ת�����Դ��͵�Ŀ���豸����
	BitBlt(hmemDC, 0, 0, width, height, hScreenDC, startX, startY, SRCCOPY);
	hBitmap = (HBITMAP)SelectObject(hmemDC, hOldBM);

	if (NULL == lpFileName)
	{
		DeleteDC(hScreenDC);
		DeleteDC(hmemDC);
		return hBitmap;
	}

	long BitmapSize = ((((width * 32) + 32) / 32) * 4) * height;
	// ������ָ���Ķ��Ϸ����ڴ棬���ҷ������ڴ治���ƶ�(HEAP_NO_SERIALIZE, ��ʹ��������ȡ)
	lpData = HeapAlloc(GetProcessHeap(), HEAP_NO_SERIALIZE, BitmapSize);
	ZeroMemory(lpData, BitmapSize);
	ZeroMemory(&bmInfo, sizeof(BITMAPINFOHEADER));
	bmInfo.biSize = sizeof(BITMAPINFOHEADER);
	bmInfo.biWidth = width;
	bmInfo.biHeight = height;
	bmInfo.biPlanes = 1;			// ����Ϊ1
	bmInfo.biBitCount = wbitCount;	//����ͼ���λ��������8λ��16λ��32λλ��Խ�߷ֱ���Խ��
	bmInfo.biCompression = BI_RGB;	//λͼ�Ƿ�ѹ�� BI_RGBΪ��ѹ�� 

	ZeroMemory(&bmFileHeader, sizeof(BITMAPFILEHEADER));
	DWORD BitsOffset = sizeof(BITMAPFILEHEADER) + bmInfo.biSize;
	DWORD ImageSize = ((((bmInfo.biWidth * bmInfo.biBitCount) + 31) / 32) * 4) * bmInfo.biHeight;
	DWORD FileSize = BitsOffset + ImageSize;
	bmFileHeader.bfType = 0x4d42;	// 'B' + ('M' << 8);
	bmFileHeader.bfSize = FileSize;
	bmFileHeader.bfOffBits = BitsOffset;

	hpal = GetStockObject(DEFAULT_PALETTE);
	if (hpal)
	{
		holdPal = SelectPalette(hmemDC, (HPALETTE)hpal, FALSE);
		RealizePalette(hmemDC);
	}
	GetDIBits(hmemDC, hBitmap, 0, bmInfo.biHeight, lpData, (BITMAPINFO *)&bmInfo, DIB_RGB_COLORS);
	if (holdPal)
	{
		SelectPalette(hmemDC, (HPALETTE)holdPal, TRUE);
		RealizePalette(hmemDC);
	}
	bmFile = CreateFile(lpFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (bmFile == INVALID_HANDLE_VALUE)
		AfxMessageBox(_T("Create File Error"));

	WriteFile(bmFile, &bmFileHeader, sizeof(BITMAPFILEHEADER), &dwWritten, NULL);
	WriteFile(bmFile, &bmInfo, sizeof(BITMAPINFOHEADER), &dwWritten, NULL);
	WriteFile(bmFile, lpData, ImageSize, &dwWritten, NULL);
	CloseHandle(bmFile);
	HeapFree(GetProcessHeap(), HEAP_NO_SERIALIZE, lpData);
	::ReleaseDC(0, hScreenDC);
	DeleteDC(hmemDC);
	
	return hBitmap;
}


void CMy12071Dlg::OnBnClickedButtonCapturescreen2()
{
	RECT rc;

	// ָ����Ļ����
	//rc = {0, 0, 800, 500};

	// ��ȡָ�����ڵ���Ļ����
	GetWindowRect(&rc);

	HBITMAP hBmp = CopyScreenToBitmap(&rc);
	BOOL bSaveSuccess = SaveBitmapToFile(hBmp, _T("a.bmp"));
	if (bSaveSuccess)
		MessageBox(_T("Save bmp file successful"));
	else
		AfxMessageBox(_T("Save bmp file failed"));
}

HBITMAP CMy12071Dlg::CopyScreenToBitmap(LPRECT lpRect)
{
	HDC hSrcDC, hMemDC;				// ��Ļ���ڴ��豸������
	HBITMAP hBitmap, hOldBitmap;	// λͼ���
	int nX, nY, nX2, nY2;			// ѡ����������
	int nWidth, nHeight;			// λͼ��Ⱥ͸߶�
	int xScrn, yScrn;				// ��Ļ�ֱ���

	if (IsRectEmpty(lpRect))
		return NULL;

	// Ϊ��Ļ�����豸������
	hSrcDC = CreateDC(_T("DISPLAY"), NULL, NULL, NULL);
	// Ϊ��Ļ�豸�����������ݵ��ڴ��豸������
	hMemDC = CreateCompatibleDC(hSrcDC);

	nX = lpRect->left;
	nY = lpRect->top;
	nX2 = lpRect->right;
	nY2 = lpRect->bottom;

	xScrn = GetDeviceCaps(hSrcDC, HORZRES);		// ��ȡ��Ļ��ˮƽ�ֱ���
	yScrn = GetDeviceCaps(hSrcDC, VERTRES);

	if (nX < 0)
		nX = 0;
	if (nY < 0)
		nY = 0;
	if (nX2 > xScrn)
		nX2 = xScrn;
	if (nY2 > yScrn)
		nY2 = yScrn;
	nWidth = nX2 - nX;
	nHeight = nY2 - nY;

	// ����һ������Ļ�豸���ݵ�λͼ
	hBitmap = CreateCompatibleBitmap(hSrcDC, nWidth, nHeight);
	// ����λͼѡ���ڴ��豸��������
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);
	// ����Ļ�豸�����������ڴ��豸������
	BitBlt(hMemDC, 0, 0, nWidth, nHeight, hSrcDC, nX, nY, SRCCOPY);
	// �õ���Ļλͼ�ľ��
	hBitmap = (HBITMAP)SelectObject(hMemDC, hOldBitmap);

	DeleteDC(hSrcDC);
	DeleteDC(hMemDC);

	return hBitmap;
}

/**
 * ����������ͨ��λͼ�������һ��λͼ���ļ�
 * hBitmap: λͼ���
 * lpFileName: �����ļ���
 * ����ֵ: TRUE�ɹ���FALSEʧ��
*/
BOOL CMy12071Dlg::SaveBitmapToFile(HBITMAP hBitmap, LPCTSTR lpFileName)
{
	HDC hDC;		// �豸������
	int iBits;		// ��ǰ��ʾ�ֱ�����ÿ��������ռ�ֽ���
	WORD wBitCount;	// λͼ��ÿ��������ռ�ֽ���
	DWORD dwPaletteSize = 0;	// ��ɫ���С
	DWORD dwBmBitsSize;			// λͼ���ݴ�С
	DWORD dwDIBSize;			// λͼ�ļ���С
	DWORD dwWritten;			// д���ļ��ֽ���
	BITMAP Bitmap;				// λͼ���Խṹ
	BITMAPFILEHEADER bmfHdr;	// λͼ�ļ�ͷ
	BITMAPINFOHEADER bi;		// λͼ��Ϣͷ
	LPBITMAPINFOHEADER lpbi;	// ָ��λͼ��Ϣͷ�ṹ

	HANDLE fh, hDib;			// �����ļ��������ڴ���
	HPALETTE hPal, hOldPal = NULL;	// ��ɫ����

	// ����λͼ�ļ�ÿ��������ռ�ֽ���
	hDC = CreateDC(_T("DISPLAY"), NULL, NULL, NULL);
	iBits = GetDeviceCaps(hDC, BITSPIXEL);
	iBits = iBits * GetDeviceCaps(hDC, PLANES);
	DeleteDC(hDC);

	if (iBits <= 1)
		wBitCount = 1;
	else if (iBits <= 4)
		wBitCount = 4;
	else if (iBits <= 8)
		wBitCount = 8;
	else if (iBits <= 24)
		wBitCount = 24;
	else
		wBitCount = 32;

	if (wBitCount <= 8)
		dwPaletteSize = (1 << wBitCount) * sizeof(RGBQUAD);		// �����ɫ���С

	// ����λͼ��Ϣͷ�ṹ
	GetObject(hBitmap, sizeof(BITMAP), &Bitmap);
	bi.biSize = sizeof(BITMAPINFOHEADER);
	bi.biWidth = Bitmap.bmWidth;
	bi.biHeight = Bitmap.bmHeight;
	bi.biPlanes = 1;
	bi.biBitCount = wBitCount;
	bi.biCompression = BI_RGB;		// ��ѹ��
	bi.biSizeImage = 0;
	bi.biXPelsPerMeter = 0;
	bi.biYPelsPerMeter = 0;
	bi.biClrUsed = 0;
	bi.biClrImportant = 0;
	dwBmBitsSize = ((Bitmap.bmWidth * wBitCount + 31) / 32) * 4 * Bitmap.bmHeight;

	// Ϊλͼ���ݷ����ڴ�
	hDib = GlobalAlloc(GHND, dwBmBitsSize + dwPaletteSize + sizeof(BITMAPINFOHEADER));
	lpbi = (LPBITMAPINFOHEADER)GlobalLock(hDib);
	*lpbi = bi;

	// �����ɫ��
	hPal = (HPALETTE)GetStockObject(DEFAULT_PALETTE);
	if (hPal)
	{
		hDC = ::GetDC(NULL);
		hOldPal = SelectPalette(hDC, hPal, FALSE);
		RealizePalette(hDC);
	}

	// ��ȡ�õ�ɫ�����µ�����ֵ
	GetDIBits(hDC, hBitmap, 0, (UINT)Bitmap.bmHeight, 
		(LPSTR)lpbi + sizeof(BITMAPINFOHEADER) + dwPaletteSize, 
		(BITMAPINFO *)lpbi, DIB_RGB_COLORS);

	// �ָ���ɫ��
	if (hOldPal)
	{
		SelectPalette(hDC, hOldPal, TRUE);
		RealizePalette(hDC);
		::ReleaseDC(NULL, hDC);
	}

	// ����λͼ�ļ�
	fh = CreateFile(lpFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	if (fh == INVALID_HANDLE_VALUE)
		return FALSE;

	// ����λͼ�ļ�ͷ
	bmfHdr.bfType = 0x4d42;		// �ļ�����Ϊ"BM"
	// ��λͼ�ļ���С����ɿ��Կ�����һ��λͼ�Ĺ����У�λͼ�ļ�ͷ��λͼ��Ϣͷ����ɫ�壬ʵ�ʵ�λͼ����
	dwDIBSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + dwPaletteSize + dwBmBitsSize;
	bmfHdr.bfSize = dwDIBSize;
	bmfHdr.bfReserved1 = 0;
	bmfHdr.bfReserved2 = 0;
	// λͼ�ļ�ͷ�����ƫ��ָʵ�����������λͼ��ʼ�Ĵ�С
	bmfHdr.bfOffBits = (DWORD)sizeof(BITMAPFILEHEADER) + (DWORD)sizeof(BITMAPINFOHEADER) + dwPaletteSize;

	WriteFile(fh, (LPSTR)&bmfHdr, sizeof(BITMAPFILEHEADER), &dwWritten, NULL);
	WriteFile(fh, (LPSTR)lpbi, dwDIBSize, &dwWritten, NULL);

	GlobalUnlock(hDib);
	GlobalFree(hDib);
	CloseHandle(fh);

	return TRUE;
}


void CMy12071Dlg::OnBnClickedCapturescreenGdi()
{
	// ÿ��10���ӽ�һ����Ļ
	//while (1)
	//{
		//Sleep(10 * 1000);
	for (int i = 0; i < 5; ++i)
	{
		Sleep(500);
		SYSTEMTIME sysTime;
		// ��ȡUTCʱ��(��������ʱ��)����ȫ���׼ʱ��
		// �й��ڶ�8������������Ҫ��8��Ҳ����ֱ��ʹ��GetLocalTime()��ȡ����ʱ��
		GetSystemTime(&sysTime);

		CString strFileName;
		strFileName.Format(_T("D:\\vs2010_projects\\1207-1\\screens\\%d_%d_%d_%d_%d_%d_%d.jpg"),
			sysTime.wYear, sysTime.wMonth, sysTime.wDay,
			sysTime.wHour + 8, sysTime.wMinute, sysTime.wSecond, sysTime.wMilliseconds);
		GetYou(strFileName);
	}
	//}
}

void CMy12071Dlg::GetYou(const CString &strFileName)
{
	HWND hwnd = ::GetDesktopWindow();		// ��ȡ���洰�ھ��
	HDC hdc = ::GetWindowDC(NULL);
	int x = GetDeviceCaps(hdc, HORZRES);
	int y = GetDeviceCaps(hdc, VERTRES);
	HBITMAP hbmp = ::CreateCompatibleBitmap(hdc, x, y);
	HBITMAP hold;
	HDC hmemdc = ::CreateCompatibleDC(hdc);
	hold = (HBITMAP)::SelectObject(hmemdc, hbmp);
	BitBlt(hmemdc, 0, 0, x, y, hdc, 0, 0, SRCCOPY);
	SelectObject(hmemdc, hold);

	int xs = GetSystemMetrics(SM_CXSCREEN);
	int ys = GetSystemMetrics(SM_CYSCREEN);
	Bitmap bit(xs, ys), bit2(hbmp, NULL);
	Graphics g(&bit);
	g.ScaleTransform((float)xs / x, (float)ys / y);
	g.DrawImage(&bit2, 0, 0);

	CLSID encoderClsid;
	ULONG quality = 30;
	EncoderParameters encoderParameters;
	encoderParameters.Count = 1;
	encoderParameters.Parameter[0].Guid = EncoderQuality;
	encoderParameters.Parameter[0].Type = EncoderParameterValueTypeLong;
	encoderParameters.Parameter[0].NumberOfValues = 1;
	encoderParameters.Parameter[0].Value = &quality;

	GetEncoderClsid(L"image/jpeg", &encoderClsid);
	bit.Save(strFileName, &encoderClsid, &encoderParameters);

	::DeleteObject(hbmp);
	::DeleteObject(hmemdc);
}

int CMy12071Dlg::GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT num = 0;		// number of image encoders
	UINT size = 0;		// size of the image encoders array in bytes

	ImageCodecInfo *pImageCodecInfo = NULL;
	GetImageEncodersSize(&num, &size);
	if (0 == size)
		return -1;		// failure
	pImageCodecInfo = (ImageCodecInfo *)malloc(size);
	if (NULL == pImageCodecInfo)
		return -1;		// failure

	GetImageEncoders(num, size, pImageCodecInfo);

	for (UINT j = 0; j < num; ++j)
	{
		if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;	// success
		}
	}

	free(pImageCodecInfo);
	return -1;			// failure
}


void CMy12071Dlg::OnBnClickedButtonGdidrawline()
{
	HDC hdc;
	Pen *mypen;
	Graphics *myGraphics;
	HWND hWnd = this->m_hWnd;

	hdc = ::GetDC(hWnd);
	// ��ͬ������ָȫ�������ռ������������ռ�֮�䣬���������࣬ȫ�������ڲ���
	// �ڽ�������ʱ����һ���������ռ�Ḳ�ǵ���һ���Ķ��壬������ʾ������һ���Ķ���
	// ���������new���õĲ��������cpp�ļ���ͷ��DEBUG_NEW��������GdiplusBase.h
	// �����ص�new����Ϊ�ʼ����������ʱ�򣬲�û������3��������new������Ҫ��
	// GdiplusBase.h����
	mypen = new Pen(Gdiplus::Color(255, 255, 0, 0), 3);
	myGraphics = new Graphics(hdc);
	myGraphics->DrawLine(mypen, 20, 10, 50, 50);

	delete myGraphics;
	delete mypen;
	::ReleaseDC(hWnd, hdc);

	// ������޸�һЩ��������ô�ͻ����error C2660: 'new' : function does not take 3 parameters
	// �������취���: 1.�����ڵ�cpp�ļ��е�#define new DEBUG_NEWע�͵�
	// ����VC��һ��BUG��΢������û�н��
	// 2.������GdiplusBase.h�ļ���class GdiplusBase�м�������Ĵ���
	//void* (operator new)(size_t nSize, LPCSTR lpszFileName, int nLine)
	//{
	//	return DllExports::GdipAlloc(nSize);
	//}

	//void (operator delete)(void* p, LPCSTR lpszFileName, int nLine)
	//{
	//	DllExports::GdipFree(p);
	//}

	// ���⣬�µİ汾��GDI+������Ҫ#define ULONG_PTR void*��仰
}

void CMy12071Dlg::OnBnClickedButtonGdi1()
{
	int X0_Room = 100, Y0_Room = 100, Width_Room = 200, Height_Room = 200;
	CRect RectForm;
	GetClientRect(&RectForm);
	Bitmap bmp(RectForm.right, RectForm.bottom);
	Graphics GraphBuf(&bmp);
	Pen redPen(Color(255, 0, 0));

	int FontSize = 20;
	FontFamily fontFamily(_T("��Բ"));
	Gdiplus::Font font(&fontFamily, FontSize, FontStyleRegular, UnitPoint);

	SolidBrush GrayBrush(Color::Gray);
	SolidBrush YelloBrush(Color::Yellow);
	CString TextSttr = _T("A��");
	PointF TextXY(0, 0);

	TextXY.X = X0_Room + Width_Room / 2 - TextSttr.GetLength() * FontSize / 2;
	TextXY.Y = Y0_Room - FontSize - 15;
	GraphBuf.DrawString(TextSttr, TextSttr.GetLength(), &font, TextXY, &GrayBrush);
	TextSttr = _T("B��");
	TextXY.X = TextXY.X + Width_Room;
	GraphBuf.DrawString(TextSttr, TextSttr.GetLength(), &font, TextXY, &GrayBrush);
	GraphBuf.DrawRectangle(&redPen, X0_Room, Y0_Room, Width_Room, Height_Room);
	GraphBuf.DrawRectangle(&redPen, X0_Room + Width_Room, Y0_Room, Width_Room, Height_Room);

	Graphics Graph_ShowOnWindow(this->GetDC()->m_hDC);
	Graph_ShowOnWindow.DrawImage(&bmp, 0, 0);
}
