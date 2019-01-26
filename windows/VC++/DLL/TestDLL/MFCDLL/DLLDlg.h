#pragma once


// CDLLDlg dialog

class CDLLDlg : public CDialog
{
	DECLARE_DYNAMIC(CDLLDlg)

public:
	CDLLDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDLLDlg();

// Dialog Data
	enum { IDD = IDD_DLL_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
