// 1250.h : main header file for the 1250 application
//

#if !defined(AFX_1250_H__6A4D7847_0F58_43EF_B61E_4D7F69D8F98B__INCLUDED_)
#define AFX_1250_H__6A4D7847_0F58_43EF_B61E_4D7F69D8F98B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1250App:
// See 1250.cpp for the implementation of this class
//

class CMy1250App : public CWinApp
{
public:
	CMy1250App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1250App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1250App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1250_H__6A4D7847_0F58_43EF_B61E_4D7F69D8F98B__INCLUDED_)
