// LoadExtDllDlg.h : main header file for the LOADEXTDLLDLG application
//

#if !defined(AFX_LOADEXTDLLDLG_H__C9F1F5E5_7486_48B9_99E0_8062A59441C4__INCLUDED_)
#define AFX_LOADEXTDLLDLG_H__C9F1F5E5_7486_48B9_99E0_8062A59441C4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLoadExtDllDlgApp:
// See LoadExtDllDlg.cpp for the implementation of this class
//

class CLoadExtDllDlgApp : public CWinApp
{
public:
	CLoadExtDllDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoadExtDllDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLoadExtDllDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOADEXTDLLDLG_H__C9F1F5E5_7486_48B9_99E0_8062A59441C4__INCLUDED_)
