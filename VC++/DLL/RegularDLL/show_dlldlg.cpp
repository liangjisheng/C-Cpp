#include"StdAfx.h"
#include"HelloDlg.h"

extern "C" void __declspec(dllexport) showDlg()
{
	// 需要调用AFX_MANAGE_STATE宏，此宏的功能是进行模块状态的切换，
	// 而AfxGetStaticModuleState()函数是在程序堆栈上创建一个
	// AFX_MODULE_STATE类型的实例，以切换当前运行的模块状态。
	// 在动态链接MFC的常规DLL的每个接口函数中都需要调用此语句，
	// 或是在调用DLL的地方使用资源切换的方式。
	// 不管哪种方式都需要进行运行程序状态切换，才可以完成对资源对话框的调用。
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CHelloDlg dlldlg;
	dlldlg.DoModal();
}