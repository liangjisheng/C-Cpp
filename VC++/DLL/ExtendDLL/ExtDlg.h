#if !defined(AFX_EXTDLG_H__B73DD3CA_3D07_4C0E_A718_892AF99B14E5__INCLUDED_)
#define AFX_EXTDLG_H__B73DD3CA_3D07_4C0E_A718_892AF99B14E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"Resource.h"
// AFX_EXT_CLASS 使得CExtDlg这个类被导出
class AFX_EXT_CLASS CExtDlg : public CDialog
{
// Construction
public:
	CExtDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CExtDlg)
	enum { IDD = IDD_DIALOG1 };	// 加上个DLL
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CExtDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CExtDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EXTDLG_H__B73DD3CA_3D07_4C0E_A718_892AF99B14E5__INCLUDED_)
