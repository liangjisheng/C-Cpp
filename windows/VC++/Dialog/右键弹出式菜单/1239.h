// 1239.h : main header file for the 1239 application
//

#if !defined(AFX_1239_H__50286F16_D0B1_4825_956A_6B56FA8612A3__INCLUDED_)
#define AFX_1239_H__50286F16_D0B1_4825_956A_6B56FA8612A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy1239App:
// See 1239.cpp for the implementation of this class
//

class CMy1239App : public CWinApp
{
public:
	CMy1239App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy1239App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy1239App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_1239_H__50286F16_D0B1_4825_956A_6B56FA8612A3__INCLUDED_)
