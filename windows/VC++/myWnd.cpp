#include <afxwin.h>
#define MAX_BUBBLE 250

class CMyWnd : public CFrameWnd
{
	CRect m_rectBubble[MAX_BUBBLE];
	int m_nBubbleCount;
public:
	CMyWnd() { m_nBubbleCount = 0; }
protected:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CMyWnd, CFrameWnd)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()


void CMyWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	if(m_nBubbleCount < MAX_BUBBLE)
	{
		int r = rand() % 50 + 10;
		CRect rect(point.x - r, point.y - r, point.x + r, point.y + r);
		m_rectBubble[m_nBubbleCount] = rect;
		m_nBubbleCount++;
		InvalidateRect(rect, FALSE);		// 更新指定区域，不擦除其它背景
	}
}


void CMyWnd::OnPaint()
{
	CPaintDC dc(this);
	CBrush brushNew;
	CPen penNew;
	brushNew.CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
	penNew.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	dc.SelectObject(&brushNew);
	dc.SelectObject(&penNew);
	for(int i = 0; i < m_nBubbleCount; i++)
		dc.Ellipse(m_rectBubble[i]);
}


// 应用程序类
class CMyApp : public CWinApp
{
public:
	BOOL InitInstance();
};


BOOL CMyApp::InitInstance()
{
	CMyWnd *pFrame = new CMyWnd;
	pFrame->Create(0, _T("吹彩色泡泡"));
	pFrame->ShowWindow(m_nCmdShow);
	this->m_pMainWnd = pFrame;
	return TRUE;
}

CMyApp ThisApp;


