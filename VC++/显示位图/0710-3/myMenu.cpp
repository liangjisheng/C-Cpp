// 在窗口中显示一个位图文件，设计一个菜单，使图像能放大、缩小和正常显示

#include <afxwin.h>
#include "resource.h"

class CMyWnd : public CFrameWnd
{
	CBitmap m_Bitmap;
	float m_fTimes;
	int m_nHeight;
	int m_nWidth;
public:
	CMyWnd();
	BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	afx_msg void OnShrink();
	afx_msg void OnBestFit();
	afx_msg void OnZoomOut();
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};


BEGIN_MESSAGE_MAP(CMyWnd, CFrameWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_SHRINK, OnShrink)
	ON_COMMAND(ID_BESTFIT, OnBestFit)
	ON_COMMAND(ID_ZOOMOUT, OnZoomOut)
END_MESSAGE_MAP()


CMyWnd::CMyWnd()
{
	BITMAP bm;
	m_Bitmap.LoadBitmap(IDB_BITMAP1);
	m_Bitmap.GetBitmap(&bm);			// 读取位图信息
	m_nWidth = bm.bmWidth;
	m_nHeight = bm.bmHeight;
	m_fTimes = 1.0;
}


BOOL CMyWnd::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.hMenu = LoadMenu(NULL, MAKEINTRESOURCE(IDR_MENU1));
	return CFrameWnd::PreCreateWindow(cs);
}


// 缩小图像
void CMyWnd::OnShrink()
{
	m_fTimes = 0.5;
	Invalidate();
}


// 放大图像
void CMyWnd::OnZoomOut()
{
	m_fTimes = 2.0;
	Invalidate();
}


// 正常显示
void CMyWnd::OnBestFit()
{
	m_fTimes = 1.0;
	Invalidate();
}


void CMyWnd::OnPaint()
{
	CPaintDC dc(this);
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(&m_Bitmap);
	dc.StretchBlt(0, 0, (int)(m_nWidth * m_fTimes), (int)(m_nHeight * m_fTimes),
		&MemDC, 0, 0, m_nWidth, m_nHeight, SRCCOPY);
}


class CMyApp : public CWinApp
{
public:
	BOOL InitInstance();
};


BOOL CMyApp::InitInstance()
{
	CMyWnd *pFrame = new CMyWnd;
	pFrame->Create(0, _T("Show Bitmap 1.0"));
	pFrame->ShowWindow(SW_SHOWMAXIMIZED);
	pFrame->UpdateWindow();
	this->m_pMainWnd = pFrame;
	return TRUE;
}


CMyApp ThisApp;


