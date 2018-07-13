// 1058.h : main header file for the 1058 application
//

#if !defined(AFX_1058_H__BE5500FD_1C45_49B4_A3D2_4ADEEDB0DE1C__INCLUDED_)
#define AFX_1058_H__BE5500FD_1C45_49B4_A3D2_4ADEEDB0DE1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1058App:
// See 1058.cpp for the implementation of this class
//

class CMy1058App : public CWinApp
{
public:
	CMy1058App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1058App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1058App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1058_H__BE5500FD_1C45_49B4_A3D2_4ADEEDB0DE1C__INCLUDED_)
