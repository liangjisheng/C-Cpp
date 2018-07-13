// 1034Dlg.h : header file
//

#if !defined(AFX_1034DLG_H__6F37CF1C_2FCE_4369_A896_938D7AA3FA46__INCLUDED_)
#define AFX_1034DLG_H__6F37CF1C_2FCE_4369_A896_938D7AA3FA46__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
static int WM_FINDREPLACEMESSAGE=RegisterWindowMessage(FINDMSGSTRING);

/////////////////////////////////////////////////////////////////////////////
// CMy1034Dlg dialog

class CMy1034Dlg : public CDialog
{
// Construction
public:
	CMy1034Dlg(CWnd* pParent = NULL);	// standard constructor
	CFindReplaceDialog * pfindreplacedlg;
	// CPrintDialog printdlg;

// Dialog Data
	//{{AFX_DATA(CMy1034Dlg)
	enum { IDD = IDD_MY1034_DIALOG };
	CEdit	m_edit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1034Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy1034Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnColorDialog();
	afx_msg void OnFontDialog();
	afx_msg void OnPagesetupDialog();
	afx_msg void OnFindreplaceDialog();
	afx_msg long OnFindReplace(WPARAM wParam,LPARAM lParam);
	afx_msg void OnChangeText();
	afx_msg void OnFileDialog();
	afx_msg void OnFileDialogSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1034DLG_H__6F37CF1C_2FCE_4369_A896_938D7AA3FA46__INCLUDED_)
