// 1000.h : main header file for the 1000 application
//

#if !defined(AFX_1000_H__732D1A44_4F28_4BC4_9DFB_55D8E53C65A1__INCLUDED_)
#define AFX_1000_H__732D1A44_4F28_4BC4_9DFB_55D8E53C65A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1000App:
// See 1000.cpp for the implementation of this class
//

class CMy1000App : public CWinApp
{
public:
	CMy1000App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1000App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1000App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1000_H__732D1A44_4F28_4BC4_9DFB_55D8E53C65A1__INCLUDED_)
