
// "MyExtentionModule.h"
// CMyModuleResourceOverride���졢���������Զ������Դ���л���
// ���У�CMyModuleResourceOverride��ľ�̬��Ա����m_theExtensionModule
// ������ȫ�ֵ�AFX_EXTENSION_MODULE����˲���Ҫ��ʽ��ָ��Ҫ�л����ĸ���Դ
// �þ�̬��Ա����Ӧ����ȫ�ֵ�AFX_EXTENSION_MODULE���󱻶���֮����ɶ��塣
// ���Խ���ͷ�ļ�����"stdafx.h"ͷ�ļ��У�����һ�δ�д#include "MyExtensionModule.h"

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
