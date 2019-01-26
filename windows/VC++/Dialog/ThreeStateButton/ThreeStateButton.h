// ThreeStateButton.h : main header file for the THREESTATEBUTTON application
//

#if !defined(AFX_THREESTATEBUTTON_H__B79E1B3A_9A13_4BD0_8F9B_BBB83EDE3CEE__INCLUDED_)
#define AFX_THREESTATEBUTTON_H__B79E1B3A_9A13_4BD0_8F9B_BBB83EDE3CEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CThreeStateButtonApp:
// See ThreeStateButton.cpp for the implementation of this class
//

class CThreeStateButtonApp : public CWinApp
{
public:
	CThreeStateButtonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreeStateButtonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CThreeStateButtonApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREESTATEBUTTON_H__B79E1B3A_9A13_4BD0_8F9B_BBB83EDE3CEE__INCLUDED_)
