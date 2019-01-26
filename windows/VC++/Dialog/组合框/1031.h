// 1031.h : main header file for the 1031 application
//

#if !defined(AFX_1031_H__4C996730_8E8B_48F2_8C45_7318E0980E2E__INCLUDED_)
#define AFX_1031_H__4C996730_8E8B_48F2_8C45_7318E0980E2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1031App:
// See 1031.cpp for the implementation of this class
//

class CMy1031App : public CWinApp
{
public:
	CMy1031App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1031App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1031App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1031_H__4C996730_8E8B_48F2_8C45_7318E0980E2E__INCLUDED_)
