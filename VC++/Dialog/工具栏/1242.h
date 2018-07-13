// 1242.h : main header file for the 1242 application
//

#if !defined(AFX_1242_H__4F5820E5_9D9B_499E_8729_5D50B6FFADB0__INCLUDED_)
#define AFX_1242_H__4F5820E5_9D9B_499E_8729_5D50B6FFADB0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1242App:
// See 1242.cpp for the implementation of this class
//

class CMy1242App : public CWinApp
{
public:
	CMy1242App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1242App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1242App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1242_H__4F5820E5_9D9B_499E_8729_5D50B6FFADB0__INCLUDED_)
