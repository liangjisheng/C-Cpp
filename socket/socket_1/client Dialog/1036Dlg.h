// 1036Dlg.h : header file
//

#if !defined(AFX_1036DLG_H__15D411BE_0B06_43AB_9012_11C6F882A90B__INCLUDED_)
#define AFX_1036DLG_H__15D411BE_0B06_43AB_9012_11C6F882A90B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define WM_SOCKET WM_USER+100

/////////////////////////////////////////////////////////////////////////////
// CMy1036Dlg dialog

class CMy1036Dlg : public CDialog
{
// Construction
public:
	CMy1036Dlg(CWnd* pParent = NULL);	// standard constructor
	SOCKET s;
	sockaddr_in addr;

// Dialog Data
	//{{AFX_DATA(CMy1036Dlg)
	enum { IDD = IDD_MY1036_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1036Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1036Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	afx_msg void OnSend();
	afx_msg void OnSocket(WPARAM wParam,LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1036DLG_H__15D411BE_0B06_43AB_9012_11C6F882A90B__INCLUDED_)
