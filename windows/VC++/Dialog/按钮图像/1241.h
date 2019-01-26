// 1241.h : main header file for the 1241 application
//

#if !defined(AFX_1241_H__F9500687_64B8_47E8_A732_2E3B27CAB22F__INCLUDED_)
#define AFX_1241_H__F9500687_64B8_47E8_A732_2E3B27CAB22F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1241App:
// See 1241.cpp for the implementation of this class
//

class CMy1241App : public CWinApp
{
public:
	CMy1241App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1241App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1241App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1241_H__F9500687_64B8_47E8_A732_2E3B27CAB22F__INCLUDED_)
