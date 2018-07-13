#if !defined(AFX_CUSTOMTREE_H__D10744EE_4A91_4445_B55E_9A3550905CEE__INCLUDED_)
#define AFX_CUSTOMTREE_H__D10744EE_4A91_4445_B55E_9A3550905CEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CustomTree.h : header file
//

// �������ؼ��ı���λͼʱ������Ҫ������ؼ���ԭʼͼ���ڽ�ԭʼ
// ͼ�������һ���ڴ滭�������ϣ�Ȼ����Ҫ���¶���һ����������
// ����λͼ�����ڸû��������ϣ����������������������������
// �����ؼ��ı�����

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
		CreateCompatibleDC(pDC);	// �������ڴ���ݵ��豸������
		m_Bmp = new CBitmap;
		// ��ʼ���ڴ����λͼ
		m_Bmp->CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());
		m_OldBmp = SelectObject(m_Bmp);
		m_pDC = pDC;
		m_Rect = rect;
	}
	~CMemDC()
	{
		m_pDC->BitBlt(m_Rect.left,m_Rect.top,m_Rect.Width(),m_Rect.Height(),
			this,m_Rect.left,m_Rect.top,SRCCOPY);	// ����λͼ
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
