// 1264Dlg.h : header file
//

#if !defined(AFX_1264DLG_H__F17DEAC1_16C2_494F_A0C2_CC026CE72262__INCLUDED_)
#define AFX_1264DLG_H__F17DEAC1_16C2_494F_A0C2_CC026CE72262__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy1264Dlg dialog

class CMy1264Dlg : public CDialog
{
// Construction
public:
	CMy1264Dlg(CWnd* pParent = NULL);	// standard constructor
	
	CToolBar m_ToolBar;
	CImageList m_ImageList;
	CString str[7];
	CFont m_Font;
	int screenX,screenY;
	int printX,printY;
	double rateX,rateY;
	BOOL m_IsWay;			// ¥Ú”°∑ΩœÚ

public:
	void DrawText(CDC* pDC,BOOL IsPrinted);

// Dialog Data
	//{{AFX_DATA(CMy1264Dlg)
	enum { IDD = IDD_MY1264_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1264Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	int m_LeftMargin;
	int m_TopMargin;
	// Generated message map functions
	//{{AFX_MSG(CMy1264Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	afx_msg void OnPrintSet();
	afx_msg void OnPrint();
	afx_msg void OnExit();
	afx_msg void OnPageSetup();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1264DLG_H__F17DEAC1_16C2_494F_A0C2_CC026CE72262__INCLUDED_)
