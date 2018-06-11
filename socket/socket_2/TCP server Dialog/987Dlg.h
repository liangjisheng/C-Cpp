// 987Dlg.h : header file
//

#if !defined(AFX_987DLG_H__A64915E6_19B0_408E_B09D_6ADBF643F2C3__INCLUDED_)
#define AFX_987DLG_H__A64915E6_19B0_408E_B09D_6ADBF643F2C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define WM_SOCKET WM_USER+100

/////////////////////////////////////////////////////////////////////////////
// CMy987Dlg dialog

class CMy987Dlg : public CDialog
{
// Construction
public:
	CMy987Dlg(CWnd* pParent = NULL);	// standard constructor
	SOCKET s,s1;
	sockaddr_in addr,addr1;

// Dialog Data
	//{{AFX_DATA(CMy987Dlg)
	enum { IDD = IDD_MY987_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy987Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy987Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSocket(WPARAM wParam,LPARAM lParam);
	afx_msg void OnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_987DLG_H__A64915E6_19B0_408E_B09D_6ADBF643F2C3__INCLUDED_)
