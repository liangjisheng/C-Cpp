// 1034.h : main header file for the 1034 application
//

#if !defined(AFX_1034_H__4346EE09_83CA_4FE1_926D_2ED25F397A88__INCLUDED_)
#define AFX_1034_H__4346EE09_83CA_4FE1_926D_2ED25F397A88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1034App:
// See 1034.cpp for the implementation of this class
//

class CMy1034App : public CWinApp
{
public:
	CMy1034App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1034App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1034App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1034_H__4346EE09_83CA_4FE1_926D_2ED25F397A88__INCLUDED_)
