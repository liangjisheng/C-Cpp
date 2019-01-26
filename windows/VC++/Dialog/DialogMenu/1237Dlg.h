// 1237Dlg.h : header file
//

#if !defined(AFX_1237DLG_H__40E0FCEA_55DC_47B2_83D6_4AA06C5D9423__INCLUDED_)
#define AFX_1237DLG_H__40E0FCEA_55DC_47B2_83D6_4AA06C5D9423__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1237Dlg dialog

class CMy1237Dlg : public CDialog
{
// Construction
public:
	CMy1237Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy1237Dlg)
	enum { IDD = IDD_MY1237_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1237Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1237Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMenu11();
	afx_msg void OnMenu12();
	afx_msg void OnMenu13();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1237DLG_H__40E0FCEA_55DC_47B2_83D6_4AA06C5D9423__INCLUDED_)
