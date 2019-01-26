// 981.h : main header file for the 981 application
//

#if !defined(AFX_981_H__C89DCC56_B576_465F_80FA_040519DE86D1__INCLUDED_)
#define AFX_981_H__C89DCC56_B576_465F_80FA_040519DE86D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy981App:
// See 981.cpp for the implementation of this class
//

class CMy981App : public CWinApp
{
public:
	CMy981App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy981App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy981App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_981_H__C89DCC56_B576_465F_80FA_040519DE86D1__INCLUDED_)
