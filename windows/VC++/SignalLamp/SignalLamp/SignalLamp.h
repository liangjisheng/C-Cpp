// SignalLamp.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSignalLampApp:
// �йش����ʵ�֣������ SignalLamp.cpp
//

class CSignalLampApp : public CWinApp
{
public:
	CSignalLampApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSignalLampApp theApp;