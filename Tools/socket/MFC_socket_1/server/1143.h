// 1143.h : main header file for the 1143 application
//

#if !defined(AFX_1143_H__460F75FE_3D88_4D8B_B6DC_77F6077DFFAA__INCLUDED_)
#define AFX_1143_H__460F75FE_3D88_4D8B_B6DC_77F6077DFFAA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1143App:
// See 1143.cpp for the implementation of this class
//

class CMy1143App : public CWinApp
{
public:
	CMy1143App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1143App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1143App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1143_H__460F75FE_3D88_4D8B_B6DC_77F6077DFFAA__INCLUDED_)
