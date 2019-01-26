// 1009.h : main header file for the 1009 application
//

#if !defined(AFX_1009_H__D9396EC0_16E7_4DEB_A5B5_BEB45C42DD10__INCLUDED_)
#define AFX_1009_H__D9396EC0_16E7_4DEB_A5B5_BEB45C42DD10__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1009App:
// See 1009.cpp for the implementation of this class
//

class CMy1009App : public CWinApp
{
public:
	CMy1009App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1009App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1009App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1009_H__D9396EC0_16E7_4DEB_A5B5_BEB45C42DD10__INCLUDED_)
