// 1251.h : main header file for the 1251 application
//

#if !defined(AFX_1251_H__1A03DA0A_E009_476D_95E9_4A40CA74CB61__INCLUDED_)
#define AFX_1251_H__1A03DA0A_E009_476D_95E9_4A40CA74CB61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1251App:
// See 1251.cpp for the implementation of this class
//

class CMy1251App : public CWinApp
{
public:
	CMy1251App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1251App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1251App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1251_H__1A03DA0A_E009_476D_95E9_4A40CA74CB61__INCLUDED_)
