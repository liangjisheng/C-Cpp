// 1254Dlg.h : header file
//

#if !defined(AFX_1254DLG_H__BFB71D27_BCDD_4A3D_93E1_6A94924CB937__INCLUDED_)
#define AFX_1254DLG_H__BFB71D27_BCDD_4A3D_93E1_6A94924CB937__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include"Client.h"
#include"Employee.h"
#include"Providedlg.h"

class CMy1254Dlg : public CDialog
{
// Construction
public:
	CMy1254Dlg(CWnd* pParent = NULL);	// standard constructor
	CImageList m_ImageList;
	CEmployee* m_eDlg;
	CClient* m_cDlg;
	CProvidedlg* m_pDlg;
// Dialog Data
	//{{AFX_DATA(CMy1254Dlg)
	enum { IDD = IDD_MY1254_DIALOG };
	CTabCtrl	m_Tab;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1254Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1254Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1254DLG_H__BFB71D27_BCDD_4A3D_93E1_6A94924CB937__INCLUDED_)
