#pragma once
#include "resource.h"

#ifdef EXDLL_CLASS
#define SG_DLL_EXP __declspec(dllexport)
#else
#define SG_DLL_EXP __declspec(dllimport)
#endif

// CMyDlg dialog

class SG_DLL_EXP CMyDlg : public CDialog
{
	DECLARE_DYNAMIC(CMyDlg)

public:
	CMyDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CMyDlg();

// Dialog Data
	enum { IDD = IDD_MY_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
