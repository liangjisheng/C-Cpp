// 1057Dlg.h : header file
//

#if !defined(AFX_1057DLG_H__F97D74A1_DB46_4878_A40E_87182ADF2544__INCLUDED_)
#define AFX_1057DLG_H__F97D74A1_DB46_4878_A40E_87182ADF2544__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1057Dlg dialog

class CMy1057Dlg : public CDialog
{
// Construction
public:
	CBrush m_Brush;
	int m_nRed;
	CMy1057Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy1057Dlg)
	enum { IDD = IDD_MY1057_DIALOG };
	CSliderCtrl	m_sliderBlue;
	CSliderCtrl	m_sliderGreen;
	CScrollBar	m_scrollRed;
	CListBox	m_List;
	int		m_nGreen;
	int		m_nBlue;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1057Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1057Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCourse();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1057DLG_H__F97D74A1_DB46_4878_A40E_87182ADF2544__INCLUDED_)
