// 1254.h : main header file for the 1254 application
//

#if !defined(AFX_1254_H__C626FF46_61ED_4DA7_8F2A_67B34A173E0F__INCLUDED_)
#define AFX_1254_H__C626FF46_61ED_4DA7_8F2A_67B34A173E0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1254App:
// See 1254.cpp for the implementation of this class
//

class CMy1254App : public CWinApp
{
public:
	CMy1254App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1254App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1254App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1254_H__C626FF46_61ED_4DA7_8F2A_67B34A173E0F__INCLUDED_)
