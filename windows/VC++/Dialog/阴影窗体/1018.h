// 1018.h : main header file for the 1018 application
//

#if !defined(AFX_1018_H__5EBAEA15_8382_417B_96C5_DDDB9D175D36__INCLUDED_)
#define AFX_1018_H__5EBAEA15_8382_417B_96C5_DDDB9D175D36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1018App:
// See 1018.cpp for the implementation of this class
//

class CMy1018App : public CWinApp
{
public:
	CMy1018App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1018App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1018App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1018_H__5EBAEA15_8382_417B_96C5_DDDB9D175D36__INCLUDED_)
