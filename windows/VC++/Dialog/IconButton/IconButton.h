// IconButton.h : main header file for the ICONBUTTON application
//

#if !defined(AFX_ICONBUTTON_H__C5F8139B_82F1_4650_B84A_7171D51DC9E3__INCLUDED_)
#define AFX_ICONBUTTON_H__C5F8139B_82F1_4650_B84A_7171D51DC9E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CIconButtonApp:
// See IconButton.cpp for the implementation of this class
//

class CIconButtonApp : public CWinApp
{
public:
	CIconButtonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIconButtonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CIconButtonApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ICONBUTTON_H__C5F8139B_82F1_4650_B84A_7171D51DC9E3__INCLUDED_)
