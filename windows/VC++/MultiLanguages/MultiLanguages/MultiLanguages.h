
// MultiLanguages.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMultiLanguagesApp:
// �йش����ʵ�֣������ MultiLanguages.cpp
//

class CMultiLanguagesApp : public CWinApp
{
public:
	CMultiLanguagesApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMultiLanguagesApp theApp;