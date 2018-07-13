// ConvertImage.h : main header file for the CONVERTIMAGE application
//

#if !defined(AFX_CONVERTIMAGE_H__A129E373_F96D_445B_8C91_E3A38834F8BC__INCLUDED_)
#define AFX_CONVERTIMAGE_H__A129E373_F96D_445B_8C91_E3A38834F8BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CConvertImageApp:
// See ConvertImage.cpp for the implementation of this class
//

class CConvertImageApp : public CWinApp
{
public:
	CConvertImageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConvertImageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CConvertImageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONVERTIMAGE_H__A129E373_F96D_445B_8C91_E3A38834F8BC__INCLUDED_)
