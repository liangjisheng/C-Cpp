// 1258View.h : interface of the CMy1258View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_1258VIEW_H__16854570_32AA_47E5_8EB2_6702E14A16E3__INCLUDED_)
#define AFX_1258VIEW_H__16854570_32AA_47E5_8EB2_6702E14A16E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy1258View : public CView
{
protected: // create from serialization only
	CMy1258View();
	DECLARE_DYNCREATE(CMy1258View)

// Attributes
public:
	CMy1258Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1258View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy1258View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy1258View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in 1258View.cpp
inline CMy1258Doc* CMy1258View::GetDocument()
   { return (CMy1258Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1258VIEW_H__16854570_32AA_47E5_8EB2_6702E14A16E3__INCLUDED_)
