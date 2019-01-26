// 1037.h : main header file for the 1037 application
//

#if !defined(AFX_1037_H__2AB5F477_E23F_4E6B_9460_D139E1418C62__INCLUDED_)
#define AFX_1037_H__2AB5F477_E23F_4E6B_9460_D139E1418C62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1037App:
// See 1037.cpp for the implementation of this class
//

class CMy1037App : public CWinApp
{
public:
	CMy1037App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1037App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1037App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1037_H__2AB5F477_E23F_4E6B_9460_D139E1418C62__INCLUDED_)
