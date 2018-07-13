// 965.h : main header file for the 965 application
//

#if !defined(AFX_965_H__92CB8311_1775_4C67_89F2_ADE9B089AA0B__INCLUDED_)
#define AFX_965_H__92CB8311_1775_4C67_89F2_ADE9B089AA0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy965App:
// See 965.cpp for the implementation of this class
//

class CMy965App : public CWinApp
{
public:
	CMy965App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy965App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy965App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_965_H__92CB8311_1775_4C67_89F2_ADE9B089AA0B__INCLUDED_)
