// 999.h : main header file for the 999 application
//

#if !defined(AFX_999_H__B2FEB1C7_7FFF_46A4_97B8_A3939E140B6F__INCLUDED_)
#define AFX_999_H__B2FEB1C7_7FFF_46A4_97B8_A3939E140B6F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy999App:
// See 999.cpp for the implementation of this class
//

class CMy999App : public CWinApp
{
public:
	CMy999App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy999App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy999App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_999_H__B2FEB1C7_7FFF_46A4_97B8_A3939E140B6F__INCLUDED_)
