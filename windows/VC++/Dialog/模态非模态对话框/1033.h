// 1033.h : main header file for the 1033 application
//

#if !defined(AFX_1033_H__C8DA3F84_C983_4FF1_83DF_D95921B187AE__INCLUDED_)
#define AFX_1033_H__C8DA3F84_C983_4FF1_83DF_D95921B187AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1033App:
// See 1033.cpp for the implementation of this class
//

class CMy1033App : public CWinApp
{
public:
	CMy1033App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1033App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1033App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1033_H__C8DA3F84_C983_4FF1_83DF_D95921B187AE__INCLUDED_)
