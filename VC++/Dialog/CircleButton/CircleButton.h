// CircleButton.h : main header file for the CIRCLEBUTTON application
//

#if !defined(AFX_CIRCLEBUTTON_H__492FDF86_67B9_47DD_A16D_224361FC88BF__INCLUDED_)
#define AFX_CIRCLEBUTTON_H__492FDF86_67B9_47DD_A16D_224361FC88BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCircleButtonApp:
// See CircleButton.cpp for the implementation of this class
//

class CCircleButtonApp : public CWinApp
{
public:
	CCircleButtonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCircleButtonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCircleButtonApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CIRCLEBUTTON_H__492FDF86_67B9_47DD_A16D_224361FC88BF__INCLUDED_)
