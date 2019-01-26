// 1245.h : main header file for the 1245 application
//

#if !defined(AFX_1245_H__B4B06434_6361_40AC_87A7_BA3EFC170CB7__INCLUDED_)
#define AFX_1245_H__B4B06434_6361_40AC_87A7_BA3EFC170CB7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1245App:
// See 1245.cpp for the implementation of this class
//

class CMy1245App : public CWinApp
{
public:
	CMy1245App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1245App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1245App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1245_H__B4B06434_6361_40AC_87A7_BA3EFC170CB7__INCLUDED_)
