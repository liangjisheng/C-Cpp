// 1096.h : main header file for the 1096 DLL
//

#if !defined(AFX_1096_H__32553375_58D1_4721_ACE5_4A59A671E0AC__INCLUDED_)
#define AFX_1096_H__32553375_58D1_4721_ACE5_4A59A671E0AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1096App
// See 1096.cpp for the implementation of this class
//

class CMy1096App : public CWinApp
{
public:
	CMy1096App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1096App)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CMy1096App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1096_H__32553375_58D1_4721_ACE5_4A59A671E0AC__INCLUDED_)
