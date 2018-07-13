// 1237.h : main header file for the 1237 application
//

#if !defined(AFX_1237_H__F46B53DA_48E0_4A47_AEC1_5659B96B0716__INCLUDED_)
#define AFX_1237_H__F46B53DA_48E0_4A47_AEC1_5659B96B0716__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1237App:
// See 1237.cpp for the implementation of this class
//

class CMy1237App : public CWinApp
{
public:
	CMy1237App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1237App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1237App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1237_H__F46B53DA_48E0_4A47_AEC1_5659B96B0716__INCLUDED_)
