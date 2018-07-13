// 1261Doc.h : interface of the CMy1261Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_1261DOC_H__53581395_5467_453A_B32E_FE73A1C70C00__INCLUDED_)
#define AFX_1261DOC_H__53581395_5467_453A_B32E_FE73A1C70C00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// ÿһ��CLine�ṹ�����һ��ֱ�ߣ�
struct CLine
{
	CPoint start;
	CPoint end;
	COLORREF color;
	int thick;		// ������ϸ
	int style;		// ������ʽ��ʵ�߻����ߣ�
};


class CMy1261Doc : public CDocument
{
protected: // create from serialization only
	CMy1261Doc();
	DECLARE_DYNCREATE(CMy1261Doc)

// Attributes
public:
	CObList list;	// ����list����CLine�ṹ��
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1261Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMy1261Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMy1261Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1261DOC_H__53581395_5467_453A_B32E_FE73A1C70C00__INCLUDED_)
