// 1263.h : main header file for the 1263 application
//

#if !defined(AFX_1263_H__784FD5AC_26E2_41F1_93C5_54D006B4B93A__INCLUDED_)
#define AFX_1263_H__784FD5AC_26E2_41F1_93C5_54D006B4B93A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1263App:
// See 1263.cpp for the implementation of this class
//

class CMy1263App : public CWinApp
{
public:
	CMy1263App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1263App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1263App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1263_H__784FD5AC_26E2_41F1_93C5_54D006B4B93A__INCLUDED_)
