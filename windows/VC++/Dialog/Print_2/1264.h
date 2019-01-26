// 1264.h : main header file for the 1264 application
//

#if !defined(AFX_1264_H__11AB6E44_8A4E_43EB_9D18_6C62F4F6E2D7__INCLUDED_)
#define AFX_1264_H__11AB6E44_8A4E_43EB_9D18_6C62F4F6E2D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1264App:
// See 1264.cpp for the implementation of this class
//

class CMy1264App : public CWinApp
{
public:
	CMy1264App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1264App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1264App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1264_H__11AB6E44_8A4E_43EB_9D18_6C62F4F6E2D7__INCLUDED_)
