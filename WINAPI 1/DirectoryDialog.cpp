
#include <Windows.h>
#include <CommDlg.h>
#include <ShlObj.h>

#pragma comment(lib, "Shell32.lib")

int APIENTRY WinMain( __in HINSTANCE hInstance, 
	__in_opt HINSTANCE hPrevInstance, 
	__in LPSTR lpCmdLine, 
	__in int nShowCmd )
{
loop:
	OPENFILENAME ofn = {0};
	TCHAR strFilename[MAX_PATH] = {0};		// 接收文件名
	ofn.lStructSize = sizeof(OPENFILENAME);
	// 拥有者窗口句柄，为NULL表示对话框是非模态的，实际中一般都要有这个
	ofn.hwndOwner = NULL;		
	ofn.lpstrFilter = TEXT("所有文件\0*.*\0C/C++ File\0*.cpp;*.c;*.h\0\0");
	ofn.nFilterIndex = 1;		// 过滤器索引
	ofn.lpstrFile = strFilename;	// 接受返回的文件名
	ofn.nMaxFile = sizeof(strFilename);		// 缓冲区长度
	ofn.lpstrInitialDir = NULL;				// 初始目录
	ofn.lpstrTitle = TEXT("请选择一个文件");		// 使用系统默认标题留空即可
	// 文件、目录必须存在，隐藏只读项
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY;

	if(GetOpenFileName(&ofn))
		MessageBox(NULL, strFilename, TEXT("选择的文件"), MB_OKCANCEL);
	else
	{
		MessageBox(NULL, TEXT("请选择一个文件"), NULL, MB_ICONERROR);
		goto loop;
	}

	system("pause");
	return 0;
}