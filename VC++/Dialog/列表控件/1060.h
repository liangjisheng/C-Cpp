// 1060.h : main header file for the 1060 application
//

#if !defined(AFX_1060_H__48FE61D0_2263_46A7_BA17_72DB7A6A8C21__INCLUDED_)
#define AFX_1060_H__48FE61D0_2263_46A7_BA17_72DB7A6A8C21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1060App:
// See 1060.cpp for the implementation of this class
//

class CMy1060App : public CWinApp
{
public:
	CMy1060App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1060App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1060App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1060_H__48FE61D0_2263_46A7_BA17_72DB7A6A8C21__INCLUDED_)
