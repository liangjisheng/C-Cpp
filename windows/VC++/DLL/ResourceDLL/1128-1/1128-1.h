
// 1128-1.h : main header file for the 1128-1 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMy11281App:
// See 1128-1.cpp for the implementation of this class
//

class CMy11281App : public CWinAppEx
{
public:
	CMy11281App();
	CString m_strCurrentPath;
	void SetLang(BOOL bEnglish);
	BOOL GetLang(void);
	BOOL m_bEnglish;
	BOOL m_bRestart;
	HINSTANCE m_hLangDLL;

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnChinese();
	afx_msg void OnEnglish();
};

extern CMy11281App theApp;
