
// CPorpertyPage.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCPorpertyPageApp: 
// �йش����ʵ�֣������ CPorpertyPage.cpp
//

class CCPorpertyPageApp : public CWinApp
{
public:
	CCPorpertyPageApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCPorpertyPageApp theApp;