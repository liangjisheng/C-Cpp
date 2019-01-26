// 1017.h : main header file for the 1017 application
//

#if !defined(AFX_1017_H__2DDAC11A_7529_4710_8006_DF72B5B8868E__INCLUDED_)
#define AFX_1017_H__2DDAC11A_7529_4710_8006_DF72B5B8868E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1017App:
// See 1017.cpp for the implementation of this class
//

class CMy1017App : public CWinApp
{
public:
	CMy1017App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1017App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1017App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1017_H__2DDAC11A_7529_4710_8006_DF72B5B8868E__INCLUDED_)
