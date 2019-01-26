// 1001Dlg.h : header file
//

#if !defined(AFX_1001DLG_H__F5477EE1_7AF4_4DC3_9D77_8F0069BBCC1A__INCLUDED_)
#define AFX_1001DLG_H__F5477EE1_7AF4_4DC3_9D77_8F0069BBCC1A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1001Dlg dialog

class CMy1001Dlg : public CDialog
{
// Construction
public:
	CMy1001Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy1001Dlg)
	enum { IDD = IDD_MY1001_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1001Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1001Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1001DLG_H__F5477EE1_7AF4_4DC3_9D77_8F0069BBCC1A__INCLUDED_)
