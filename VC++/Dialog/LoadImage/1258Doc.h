// 1258Doc.h : interface of the CMy1258Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_1258DOC_H__94F067E9_2DE5_4756_A423_FDB28A4691C0__INCLUDED_)
#define AFX_1258DOC_H__94F067E9_2DE5_4756_A423_FDB28A4691C0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMy1258Doc : public CDocument
{
protected: // create from serialization only
	CMy1258Doc();
	DECLARE_DYNCREATE(CMy1258Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1258Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy1258Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy1258Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1258DOC_H__94F067E9_2DE5_4756_A423_FDB28A4691C0__INCLUDED_)
