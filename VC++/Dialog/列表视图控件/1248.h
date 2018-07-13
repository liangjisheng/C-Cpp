// 1248.h : main header file for the 1248 application
//

#if !defined(AFX_1248_H__51459A98_123F_47F8_A945_4A48D32EA906__INCLUDED_)
#define AFX_1248_H__51459A98_123F_47F8_A945_4A48D32EA906__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1248App:
// See 1248.cpp for the implementation of this class
//

class CMy1248App : public CWinApp
{
public:
	CMy1248App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1248App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1248App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1248_H__51459A98_123F_47F8_A945_4A48D32EA906__INCLUDED_)
