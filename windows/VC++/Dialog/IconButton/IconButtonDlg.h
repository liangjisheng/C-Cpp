// IconButtonDlg.h : header file
//

#if !defined(AFX_ICONBUTTONDLG_H__26B42108_471E_49DA_B841_05ECD20AE79C__INCLUDED_)
#define AFX_ICONBUTTONDLG_H__26B42108_471E_49DA_B841_05ECD20AE79C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CIconButtonDlg dialog
#include "IconBtn.h"

class CIconButtonDlg : public CDialog
{
// Construction
public:
	CIconButtonDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CIconButtonDlg)
	enum { IDD = IDD_ICONBUTTON_DIALOG };
	CIconBtn	m_Exit;
	CIconBtn	m_Save;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIconButtonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CImageList m_ImageList;
	// Generated message map functions
	//{{AFX_MSG(CIconButtonDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSaveButton();
	afx_msg void OnExitButton();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICONBUTTONDLG_H__26B42108_471E_49DA_B841_05ECD20AE79C__INCLUDED_)
