// 1016.h : main header file for the 1016 application
//

#if !defined(AFX_1016_H__7B205351_2E36_4B9E_9CB1_06EA878A04D1__INCLUDED_)
#define AFX_1016_H__7B205351_2E36_4B9E_9CB1_06EA878A04D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1016App:
// See 1016.cpp for the implementation of this class
//

class CMy1016App : public CWinApp
{
public:
	CMy1016App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1016App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1016App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1016_H__7B205351_2E36_4B9E_9CB1_06EA878A04D1__INCLUDED_)
