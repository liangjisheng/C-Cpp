
// 1207-1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "1207-1.h"
#include "1207-1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
// MFC重载operator new，是为了方便定位内存泄漏，重载后的operator new
// 会记录下所分配的每块内存对应的__FILE__和__LINE__信息
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
	// 如果m_hWnd句柄对应的窗口未置顶(TopMost),则置顶窗口
	if (!(::GetWindowLong(this->m_hWnd, GWL_EXSTYLE) & WS_EX_TOPMOST))
		::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

	CString strImageSavePath = _T("screen.bmp");
	ScreenCapture(this->m_hWnd, 32, strImageSavePath);
}

/**
 * 截取窗口图片，并保存到本地
 * hWnd: 窗口句柄
 * lpFileName: 保存的文件名
 * wbitCount: 位深
 * lpRect: 窗口大小
 * 返回位图句柄
*/
HBITMAP CMy12071Dlg::ScreenCapture(HWND hWnd, WORD wbitCount, LPCTSTR lpFileName /* = NULL */)
{
	RECT rc;

	// 指定屏幕坐标
	//rc = {0, 0, 800, 500};

	// 获取指定窗口的屏幕坐标
	::GetWindowRect(hWnd, &rc);

	HBITMAP hBitmap;
	//通过指定DISPLAY来获取一个显示设备(显示器)上下文环境
	HDC hScreenDC = CreateDC(_T("DISPLAY"), NULL, NULL, NULL);
	// 创建一个与指定设备兼容的内存设备上下文环境(DC)
	HDC hmemDC = CreateCompatibleDC(hScreenDC);

	//获取指定设备的性能参数（此处获取屏幕宽度）
	int nScreenWidth = GetDeviceCaps(hScreenDC, HORZRES);
	//获取指定设备的性能参数（此处获取屏幕高度）
	int nScreenHeight = GetDeviceCaps(hScreenDC, VERTRES);
	HBITMAP hOldBM;
	PVOID lpData;	// 内存分配成功返回的指向所分配内存块的首地址指针
	int startX = rc.left;	// 截图X位置
	int startY = rc.top;	// 截图Y位置
	int width = rc.right - rc.left;		// 截图宽度
	int height = rc.bottom - rc.top;	// 截图高度

	// BITMAPINFOHEADER结构所包含的成员表明了图像的尺寸、原始设备的颜色格式、以及数据压缩方案
	BITMAPINFOHEADER bmInfo;
	BITMAPFILEHEADER bmFileHeader;
	HANDLE bmFile, hpal, holdPal = NULL;
	DWORD dwWritten;

	// 创建一张长width，宽height的画布，用于后面绘制图形
	hBitmap = CreateCompatibleBitmap(hScreenDC, width, height);
	// 选择一对象到指定的设备上下文环境中，该新对象替换先前的相同类型的对象
	hOldBM = (HBITMAP)SelectObject(hmemDC, hBitmap);
	// 该函数对指定的源设备环境区域中的像素进行位块（bit_block）转换，以传送到目标设备环境
	BitBlt(hmemDC, 0, 0, width, height, hScreenDC, startX, startY, SRCCOPY);
	hBitmap = (HBITMAP)SelectObject(hmemDC, hOldBM);

	if (NULL == lpFileName)
	{
		DeleteDC(hScreenDC);
		DeleteDC(hmemDC);
		return hBitmap;
	}

	long BitmapSize = ((((width * 32) + 32) / 32) * 4) * height;
	// 用来在指定的堆上分配内存，并且分配后的内存不可移动(HEAP_NO_SERIALIZE, 不使用连续存取)
	lpData = HeapAlloc(GetProcessHeap(), HEAP_NO_SERIALIZE, BitmapSize);
	ZeroMemory(lpData, BitmapSize);
	ZeroMemory(&bmInfo, sizeof(BITMAPINFOHEADER));
	bmInfo.biSize = sizeof(BITMAPINFOHEADER);
	bmInfo.biWidth = width;
	bmInfo.biHeight = height;
	bmInfo.biPlanes = 1;			// 必须为1
	bmInfo.biBitCount = wbitCount;	//设置图像的位数。比如8位，16位，32位位数越高分辨率越高
	bmInfo.biCompression = BI_RGB;	//位图是否压缩 BI_RGB为不压缩 

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

	// 指定屏幕坐标
	//rc = {0, 0, 800, 500};

	// 获取指定窗口的屏幕坐标
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
	HDC hSrcDC, hMemDC;				// 屏幕和内存设备描述表
	HBITMAP hBitmap, hOldBitmap;	// 位图句柄
	int nX, nY, nX2, nY2;			// 选定区域坐标
	int nWidth, nHeight;			// 位图跨度和高度
	int xScrn, yScrn;				// 屏幕分辨率

	if (IsRectEmpty(lpRect))
		return NULL;

	// 为屏幕创建设备描述表
	hSrcDC = CreateDC(_T("DISPLAY"), NULL, NULL, NULL);
	// 为屏幕设备描述表创建兼容的内存设备描述表
	hMemDC = CreateCompatibleDC(hSrcDC);

	nX = lpRect->left;
	nY = lpRect->top;
	nX2 = lpRect->right;
	nY2 = lpRect->bottom;

	xScrn = GetDeviceCaps(hSrcDC, HORZRES);		// 获取屏幕的水平分辨率
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

	// 创建一个与屏幕设备兼容的位图
	hBitmap = CreateCompatibleBitmap(hSrcDC, nWidth, nHeight);
	// 把新位图选到内存设备描述表中
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);
	// 把屏幕设备描述表拷贝到内存设备描述表
	BitBlt(hMemDC, 0, 0, nWidth, nHeight, hSrcDC, nX, nY, SRCCOPY);
	// 得到屏幕位图的句柄
	hBitmap = (HBITMAP)SelectObject(hMemDC, hOldBitmap);

	DeleteDC(hSrcDC);
	DeleteDC(hMemDC);

	return hBitmap;
}

/**
 * 函数描述：通过位图句柄保存一个位图到文件
 * hBitmap: 位图句柄
 * lpFileName: 保存文件名
 * 返回值: TRUE成功，FALSE失败
*/
BOOL CMy12071Dlg::SaveBitmapToFile(HBITMAP hBitmap, LPCTSTR lpFileName)
{
	HDC hDC;		// 设备描述表
	int iBits;		// 当前显示分辨率下每个像素所占字节数
	WORD wBitCount;	// 位图中每个像素所占字节数
	DWORD dwPaletteSize = 0;	// 调色板大小
	DWORD dwBmBitsSize;			// 位图数据大小
	DWORD dwDIBSize;			// 位图文件大小
	DWORD dwWritten;			// 写入文件字节数
	BITMAP Bitmap;				// 位图属性结构
	BITMAPFILEHEADER bmfHdr;	// 位图文件头
	BITMAPINFOHEADER bi;		// 位图信息头
	LPBITMAPINFOHEADER lpbi;	// 指向位图信息头结构

	HANDLE fh, hDib;			// 定义文件，分配内存句柄
	HPALETTE hPal, hOldPal = NULL;	// 调色板句柄

	// 计算位图文件每个像素所占字节数
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
		dwPaletteSize = (1 << wBitCount) * sizeof(RGBQUAD);		// 计算调色板大小

	// 设置位图信息头结构
	GetObject(hBitmap, sizeof(BITMAP), &Bitmap);
	bi.biSize = sizeof(BITMAPINFOHEADER);
	bi.biWidth = Bitmap.bmWidth;
	bi.biHeight = Bitmap.bmHeight;
	bi.biPlanes = 1;
	bi.biBitCount = wBitCount;
	bi.biCompression = BI_RGB;		// 不压缩
	bi.biSizeImage = 0;
	bi.biXPelsPerMeter = 0;
	bi.biYPelsPerMeter = 0;
	bi.biClrUsed = 0;
	bi.biClrImportant = 0;
	dwBmBitsSize = ((Bitmap.bmWidth * wBitCount + 31) / 32) * 4 * Bitmap.bmHeight;

	// 为位图内容分配内存
	hDib = GlobalAlloc(GHND, dwBmBitsSize + dwPaletteSize + sizeof(BITMAPINFOHEADER));
	lpbi = (LPBITMAPINFOHEADER)GlobalLock(hDib);
	*lpbi = bi;

	// 处理调色板
	hPal = (HPALETTE)GetStockObject(DEFAULT_PALETTE);
	if (hPal)
	{
		hDC = ::GetDC(NULL);
		hOldPal = SelectPalette(hDC, hPal, FALSE);
		RealizePalette(hDC);
	}

	// 获取该调色板下新的像素值
	GetDIBits(hDC, hBitmap, 0, (UINT)Bitmap.bmHeight, 
		(LPSTR)lpbi + sizeof(BITMAPINFOHEADER) + dwPaletteSize, 
		(BITMAPINFO *)lpbi, DIB_RGB_COLORS);

	// 恢复调色板
	if (hOldPal)
	{
		SelectPalette(hDC, hOldPal, TRUE);
		RealizePalette(hDC);
		::ReleaseDC(NULL, hDC);
	}

	// 创建位图文件
	fh = CreateFile(lpFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN, NULL);
	if (fh == INVALID_HANDLE_VALUE)
		return FALSE;

	// 设置位图文件头
	bmfHdr.bfType = 0x4d42;		// 文件类型为"BM"
	// 从位图文件大小的组成可以看出，一个位图的构成有：位图文件头、位图信息头，调色板，实际的位图数据
	dwDIBSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + dwPaletteSize + dwBmBitsSize;
	bmfHdr.bfSize = dwDIBSize;
	bmfHdr.bfReserved1 = 0;
	bmfHdr.bfReserved2 = 0;
	// 位图文件头里面的偏移指实际数据相对于位图开始的大小
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
	// 每隔10秒钟截一次屏幕
	//while (1)
	//{
		//Sleep(10 * 1000);
	for (int i = 0; i < 5; ++i)
	{
		Sleep(500);
		SYSTEMTIME sysTime;
		// 获取UTC时间(格林威治时间)，即全球标准时间
		// 中国在东8区，所以下面要加8，也可以直接使用GetLocalTime()获取本地时间
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
	HWND hwnd = ::GetDesktopWindow();		// 获取桌面窗口句柄
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
	// 不同命名域（指全局命名空间与有名命名空间之间，父类与子类，全局与类内部）
	// 内进行重载时，下一级的命名空间会覆盖掉上一级的定义，除非显示调用上一级的定义
	// 所以这里的new调用的并不是这个cpp文件开头的DEBUG_NEW，而是在GdiplusBase.h
	// 中重载的new，因为最开始下载下来的时候，并没有重载3个参数的new，所以要在
	// GdiplusBase.h加上
	mypen = new Pen(Gdiplus::Color(255, 255, 0, 0), 3);
	myGraphics = new Graphics(hdc);
	myGraphics->DrawLine(mypen, 20, 10, 50, 50);

	delete myGraphics;
	delete mypen;
	::ReleaseDC(hWnd, hdc);

	// 如果不修改一些东西，那么就会出现error C2660: 'new' : function does not take 3 parameters
	// 有两个办法解决: 1.将所在的cpp文件中的#define new DEBUG_NEW注释掉
	// 这是VC的一个BUG，微软至今还没有解除
	// 2.或者在GdiplusBase.h文件中class GdiplusBase中加上下面的代码
	//void* (operator new)(size_t nSize, LPCSTR lpszFileName, int nLine)
	//{
	//	return DllExports::GdipAlloc(nSize);
	//}

	//void (operator delete)(void* p, LPCSTR lpszFileName, int nLine)
	//{
	//	DllExports::GdipFree(p);
	//}

	// 另外，新的版本的GDI+并不需要#define ULONG_PTR void*这句话
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
	FontFamily fontFamily(_T("幼圆"));
	Gdiplus::Font font(&fontFamily, FontSize, FontStyleRegular, UnitPoint);

	SolidBrush GrayBrush(Color::Gray);
	SolidBrush YelloBrush(Color::Yellow);
	CString TextSttr = _T("A区");
	PointF TextXY(0, 0);

	TextXY.X = X0_Room + Width_Room / 2 - TextSttr.GetLength() * FontSize / 2;
	TextXY.Y = Y0_Room - FontSize - 15;
	GraphBuf.DrawString(TextSttr, TextSttr.GetLength(), &font, TextXY, &GrayBrush);
	TextSttr = _T("B区");
	TextXY.X = TextXY.X + Width_Room;
	GraphBuf.DrawString(TextSttr, TextSttr.GetLength(), &font, TextXY, &GrayBrush);
	GraphBuf.DrawRectangle(&redPen, X0_Room, Y0_Room, Width_Room, Height_Room);
	GraphBuf.DrawRectangle(&redPen, X0_Room + Width_Room, Y0_Room, Width_Room, Height_Room);

	Graphics Graph_ShowOnWindow(this->GetDC()->m_hDC);
	Graph_ShowOnWindow.DrawImage(&bmp, 0, 0);
}
