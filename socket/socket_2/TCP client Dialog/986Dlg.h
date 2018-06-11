// 986Dlg.h : header file
//

#if !defined(AFX_986DLG_H__9F1D1D81_68C5_4965_A183_B051B3DE5223__INCLUDED_)
#define AFX_986DLG_H__9F1D1D81_68C5_4965_A183_B051B3DE5223__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#define WM_SOCKET WM_USER+100

/////////////////////////////////////////////////////////////////////////////
// CMy986Dlg dialog

class CMy986Dlg : public CDialog
{
// Construction
public:
	CMy986Dlg(CWnd* pParent = NULL);	// standard constructor
	SOCKET s;	// 定义套接字对象	
	sockaddr_in addr;	// 套接字地址结构

// Dialog Data
	//{{AFX_DATA(CMy986Dlg)
	enum { IDD = IDD_MY986_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy986Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy986Dlg)
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

#endif // !defined(AFX_986DLG_H__9F1D1D81_68C5_4965_A183_B051B3DE5223__INCLUDED_)
