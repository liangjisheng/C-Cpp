// 编写一个不是用mfc的程序，弹出一个窗口，
// 要得到完整的程序，只需从mfc中派生出两个类
// 应用程序类和窗口类，而不需要编写WinMain()函数
// 因为WinMain()是由mfc在后台自动提供的
#include <afxwin.h>		// For the class library

// 自己的应用程序类
class COurApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

// 自己的窗口类,CFrameWnd提供创建和管理
// 应用程序窗口所需的一切，所需要的是给派生类添加
// 一个构造函数，允许指定窗口的标题栏
class COurWnd : public CFrameWnd
{
public:
	COurWnd()
	{
		// 第一个参数为0，表明希望创建的窗口使用基类的默认属性
		Create(0,L"Our Dumb MFC Application");
	}
};

// Function to create an instance of the main application window
BOOL COurApp::InitInstance(void)
{
	// Constructor a window object in the free store
	m_pMainWnd = new COurWnd;
	m_pMainWnd->ShowWindow(m_nCmdShow);
	return TRUE;
}

// Application object definition at global scope
COurApp AnApplication;	// Define an application object