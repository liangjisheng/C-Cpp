// 1018Dlg.h : header file
//

#if !defined(AFX_1018DLG_H__1BB6E52F_8F8B_4763_B201_BDAF12FA89AF__INCLUDED_)
#define AFX_1018DLG_H__1BB6E52F_8F8B_4763_B201_BDAF12FA89AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"Shaddlg1.h"
#include"Shaddlg2.h"

/////////////////////////////////////////////////////////////////////////////
// CMy1018Dlg dialog

class CMy1018Dlg : public CDialog
{
// Construction
public:
	CFont m_font;
	CMy1018Dlg(CWnd* pParent = NULL);	// standard constructor
	CShaddlg1 dlg1;
	CShaddlg2 dlg2;

// Dialog Data
	//{{AFX_DATA(CMy1018Dlg)
	enum { IDD = IDD_MY1018_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1018Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1018Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnMove(int x, int y);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1018DLG_H__1BB6E52F_8F8B_4763_B201_BDAF12FA89AF__INCLUDED_)
