// 1001.h : main header file for the 1001 application
//

#if !defined(AFX_1001_H__A51FC994_26B9_443A_A33F_D0AC9147596A__INCLUDED_)
#define AFX_1001_H__A51FC994_26B9_443A_A33F_D0AC9147596A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1001App:
// See 1001.cpp for the implementation of this class
//

class CMy1001App : public CWinApp
{
public:
	CMy1001App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1001App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1001App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1001_H__A51FC994_26B9_443A_A33F_D0AC9147596A__INCLUDED_)
