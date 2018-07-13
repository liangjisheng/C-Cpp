#if !defined(AFX_CUSTOMTREE_H__D10744EE_4A91_4445_B55E_9A3550905CEE__INCLUDED_)
#define AFX_CUSTOMTREE_H__D10744EE_4A91_4445_B55E_9A3550905CEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomTree.h : header file
//

// 绘制树控件的背景位图时，首先要获得树控件的原始图像，在将原始
// 图像绘制在一个内存画布对象上，然后需要重新定义一个画布对象，
// 并将位图绘制在该画布对象上，最后将两个画布对象进行与运算绘制
// 在树控件的背景上

class CMemDC : public CDC
{
private:
	CBitmap* m_Bmp;
	CBitmap* m_OldBmp;
	CDC* m_pDC;
	CRect m_Rect;
public:
	CMemDC(CDC* pDC,const CRect& rect) : CDC()
	{
		CreateCompatibleDC(pDC);	// 创建与内存兼容的设备上下文
		m_Bmp = new CBitmap;
		// 初始化内存兼容位图
		m_Bmp->CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());
		m_OldBmp = SelectObject(m_Bmp);
		m_pDC = pDC;
		m_Rect = rect;
	}
	~CMemDC()
	{
		m_pDC->BitBlt(m_Rect.left,m_Rect.top,m_Rect.Width(),m_Rect.Height(),
			this,m_Rect.left,m_Rect.top,SRCCOPY);	// 绘制位图
		SelectObject(m_OldBmp);
		if(m_Bmp != NULL)
			delete m_Bmp;
	}
};

/////////////////////////////////////////////////////////////////////////////
// CCustomTree window

class CCustomTree : public CTreeCtrl
{
// Construction
public:
	CCustomTree();

// Attributes
public:
	CBitmap m_Bitmap;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCustomTree)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCustomTree();

	// Generated message map functions
protected:
	//{{AFX_MSG(CCustomTree)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnItemexpanding(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemexpanded(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUSTOMTREE_H__D10744EE_4A91_4445_B55E_9A3550905CEE__INCLUDED_)
