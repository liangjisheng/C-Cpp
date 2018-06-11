// 1036.h : main header file for the 1036 application
//

#if !defined(AFX_1036_H__92DF0124_6082_4E92_81E9_33F6F547A683__INCLUDED_)
#define AFX_1036_H__92DF0124_6082_4E92_81E9_33F6F547A683__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1036App:
// See 1036.cpp for the implementation of this class
//

class CMy1036App : public CWinApp
{
public:
	CMy1036App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1036App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1036App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1036_H__92DF0124_6082_4E92_81E9_33F6F547A683__INCLUDED_)
