
// MFCMenu2.h : MFCMenu2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCMenu2App:
// �йش����ʵ�֣������ MFCMenu2.cpp
//

class CMFCMenu2App : public CWinAppEx
{
public:
	CMFCMenu2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCMenu2App theApp;
