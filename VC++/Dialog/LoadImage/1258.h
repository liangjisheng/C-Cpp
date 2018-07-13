// 1258.h : main header file for the 1258 application
//

#if !defined(AFX_1258_H__DA7C32E4_3C18_43B5_A35D_E2345F93C71D__INCLUDED_)
#define AFX_1258_H__DA7C32E4_3C18_43B5_A35D_E2345F93C71D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1258App:
// See 1258.cpp for the implementation of this class
//

class CMy1258App : public CWinApp
{
public:
	CMy1258App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1258App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMy1258App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1258_H__DA7C32E4_3C18_43B5_A35D_E2345F93C71D__INCLUDED_)
