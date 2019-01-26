// 986.h : main header file for the 986 application
//

#if !defined(AFX_986_H__CA2997D5_6945_487C_851F_AA9012C8684C__INCLUDED_)
#define AFX_986_H__CA2997D5_6945_487C_851F_AA9012C8684C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy986App:
// See 986.cpp for the implementation of this class
//

class CMy986App : public CWinApp
{
public:
	CMy986App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy986App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy986App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_986_H__CA2997D5_6945_487C_851F_AA9012C8684C__INCLUDED_)
