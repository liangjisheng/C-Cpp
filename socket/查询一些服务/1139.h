// 1139.h : main header file for the 1139 application
//

#if !defined(AFX_1139_H__D8E5F949_A607_414C_91C3_AA2509062F96__INCLUDED_)
#define AFX_1139_H__D8E5F949_A607_414C_91C3_AA2509062F96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1139App:
// See 1139.cpp for the implementation of this class
//

class CMy1139App : public CWinApp
{
public:
	CMy1139App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1139App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1139App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1139_H__D8E5F949_A607_414C_91C3_AA2509062F96__INCLUDED_)
