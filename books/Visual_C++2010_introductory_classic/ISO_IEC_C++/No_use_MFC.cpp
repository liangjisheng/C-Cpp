// ��дһ��������mfc�ĳ��򣬵���һ�����ڣ�
// Ҫ�õ������ĳ���ֻ���mfc��������������
// Ӧ�ó�����ʹ����࣬������Ҫ��дWinMain()����
// ��ΪWinMain()����mfc�ں�̨�Զ��ṩ��
#include <afxwin.h>		// For the class library

// �Լ���Ӧ�ó�����
class COurApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};

// �Լ��Ĵ�����,CFrameWnd�ṩ�����͹���
// Ӧ�ó��򴰿������һ�У�����Ҫ���Ǹ����������
// һ�����캯��������ָ�����ڵı�����
class COurWnd : public CFrameWnd
{
public:
	COurWnd()
	{
		// ��һ������Ϊ0������ϣ�������Ĵ���ʹ�û����Ĭ������
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