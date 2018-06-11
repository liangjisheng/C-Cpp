// 1043.h : main header file for the 1043 application
//

#if !defined(AFX_1043_H__37CAB5EC_C1BF_415D_8486_5059ED1C72B9__INCLUDED_)
#define AFX_1043_H__37CAB5EC_C1BF_415D_8486_5059ED1C72B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1043App:
// See 1043.cpp for the implementation of this class
//

class CMy1043App : public CWinApp
{
public:
	CMy1043App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1043App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1043App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1043_H__37CAB5EC_C1BF_415D_8486_5059ED1C72B9__INCLUDED_)
