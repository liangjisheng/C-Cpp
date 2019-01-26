// 1121.h : main header file for the 1121 application
//

#if !defined(AFX_1121_H__1F85D199_143E_473D_B623_E5D78F8DF0C3__INCLUDED_)
#define AFX_1121_H__1F85D199_143E_473D_B623_E5D78F8DF0C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1121App:
// See 1121.cpp for the implementation of this class
//

class CMy1121App : public CWinApp
{
public:
	CMy1121App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1121App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1121App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1121_H__1F85D199_143E_473D_B623_E5D78F8DF0C3__INCLUDED_)
