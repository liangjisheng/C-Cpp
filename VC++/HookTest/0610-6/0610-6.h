#pragma once
#include "stdafx.h"

class AFX_EXT_CLASS CHookTest : public CObject
{
public:
	CHookTest();
	virtual ~CHookTest();
	BOOL StartHook();
	BOOL StopHook();
};