// 1037Dlg.h : header file
//

#if !defined(AFX_1037DLG_H__D602C379_F251_4C21_A26B_3498FF5599CA__INCLUDED_)
#define AFX_1037DLG_H__D602C379_F251_4C21_A26B_3498FF5599CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define WM_SOCKET WM_USER+100

/////////////////////////////////////////////////////////////////////////////
// CMy1037Dlg dialog

class CMy1037Dlg : public CDialog
{
// Construction
public:
	CMy1037Dlg(CWnd* pParent = NULL);	// standard constructor
	SOCKET s,s1;
	sockaddr_in addr,addr1;

// Dialog Data
	//{{AFX_DATA(CMy1037Dlg)
	enum { IDD = IDD_MY1037_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1037Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon,hi[2];

	// Generated message map functions
	//{{AFX_MSG(CMy1037Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSocket(WPARAM wParam,LPARAM lParam);
	afx_msg void OnSend();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1037DLG_H__D602C379_F251_4C21_A26B_3498FF5599CA__INCLUDED_)
