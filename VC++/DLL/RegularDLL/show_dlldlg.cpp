#include"StdAfx.h"
#include"HelloDlg.h"

extern "C" void __declspec(dllexport) showDlg()
{
	// ��Ҫ����AFX_MANAGE_STATE�꣬�˺�Ĺ����ǽ���ģ��״̬���л���
	// ��AfxGetStaticModuleState()�������ڳ����ջ�ϴ���һ��
	// AFX_MODULE_STATE���͵�ʵ�������л���ǰ���е�ģ��״̬��
	// �ڶ�̬����MFC�ĳ���DLL��ÿ���ӿں����ж���Ҫ���ô���䣬
	// �����ڵ���DLL�ĵط�ʹ����Դ�л��ķ�ʽ��
	// �������ַ�ʽ����Ҫ�������г���״̬�л����ſ�����ɶ���Դ�Ի���ĵ��á�
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CHelloDlg dlldlg;
	dlldlg.DoModal();
}