
// 0425-1View.h : interface of the CMy04251View class
//

#pragma once


class CMy04251View : public CView
{
protected: // create from serialization only
	CMy04251View();
	DECLARE_DYNCREATE(CMy04251View)

// Attributes
public:
	CMy04251Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMy04251View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CImage m_Image;
	CString m_strRunPath;
// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
	afx_msg void OnFileSaveAs();
	void FilterImage(CImage* image, int nType);
	void MakeBlackAndWhite(CImage* image);

	void GetRunPath();
	virtual void OnInitialUpdate();
	void SaveImage();
	afx_msg void OnCimageSave();
	afx_msg void OnCimageShowimage();
	afx_msg void OnCimageShowpng();
};

#ifndef _DEBUG  // debug version in 0425-1View.cpp
inline CMy04251Doc* CMy04251View::GetDocument() const
   { return reinterpret_cast<CMy04251Doc*>(m_pDocument); }
#endif

