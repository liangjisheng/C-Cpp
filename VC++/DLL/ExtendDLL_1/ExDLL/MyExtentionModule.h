
// "MyExtentionModule.h"
// CMyModuleResourceOverride构造、析构函数自动完成资源的切换。
// 其中，CMyModuleResourceOverride类的静态成员变量m_theExtensionModule
// 引用了全局的AFX_EXTENSION_MODULE，因此不需要显式的指明要切换到哪个资源
// 该静态成员变量应该在全局的AFX_EXTENSION_MODULE对象被定义之后完成定义。
// 可以将该头文件放在"stdafx.h"头文件中，避免一次次写#include "MyExtensionModule.h"

#pragma once

class CMyModuleResourceOverride
{
public:
	CMyModuleResourceOverride();
	~CMyModuleResourceOverride();

private:
	HINSTANCE m_hInstanceOld;

private:
	static AFX_EXTENSION_MODULE& m_theExtensionModule;
};

CMyModuleResourceOverride::CMyModuleResourceOverride()
: m_hInstanceOld(::AfxGetResourceHandle())
{
	::AfxSetResourceHandle(m_theExtensionModule.hModule);
}

CMyModuleResourceOverride::~CMyModuleResourceOverride()
{
	::AfxSetResourceHandle(m_hInstanceOld);
}

#define IMPLEMENT_MODULE_RESOURCE_OVERRIDE(module)\
	AFX_EXTENSION_MODULE& CMyModuleResourceOverride::m_theExtensionModule = module;
