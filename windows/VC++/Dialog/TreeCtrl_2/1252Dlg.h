// 1252Dlg.h : header file
//

#if !defined(AFX_1252DLG_H__B0E8CE43_C3DC_440F_9C23_4890B64BCDA8__INCLUDED_)
#define AFX_1252DLG_H__B0E8CE43_C3DC_440F_9C23_4890B64BCDA8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1252Dlg dialog

class CMy1252Dlg : public CDialog
{
// Construction
public:
	CMy1252Dlg(CWnd* pParent = NULL);	// standard constructor
	CImageList m_ImageList;
// Dialog Data
	//{{AFX_DATA(CMy1252Dlg)
	enum { IDD = IDD_MY1252_DIALOG };
	CTreeCtrl	m_Tree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1252Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1252Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnEndlabeleditTree1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1252DLG_H__B0E8CE43_C3DC_440F_9C23_4890B64BCDA8__INCLUDED_)
