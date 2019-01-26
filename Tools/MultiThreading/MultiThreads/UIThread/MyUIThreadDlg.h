#pragma once


// CMyUIThreadDlg dialog

class CMyUIThreadDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMyUIThreadDlg)

public:
	CMyUIThreadDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CMyUIThreadDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
