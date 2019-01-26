// 1144.h : main header file for the 1144 application
//

#if !defined(AFX_1144_H__01F95028_4ED6_4BE5_A3E4_A41E9DDE2300__INCLUDED_)
#define AFX_1144_H__01F95028_4ED6_4BE5_A3E4_A41E9DDE2300__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1144App:
// See 1144.cpp for the implementation of this class
//

class CMy1144App : public CWinApp
{
public:
	CMy1144App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1144App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1144App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1144_H__01F95028_4ED6_4BE5_A3E4_A41E9DDE2300__INCLUDED_)
