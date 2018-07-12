
// GDI+画图时，通过调用Image::FromIstream获取Image*指针，而IStream*
// 是通过CreateStreamOnHGlobal得到的。
// 使用GDI+实现把bmp图片格式转换成JPEG格式(在内存中)，然后通过网络
// 发送到另一端，另一端接受显示

// 先用Image加载图片，然后创建流，通过Image类的Save函数以JPEG格式把
// 图片数据保存到流中，之后读取数据，在用Image类的FromStream从流中
// 加载(还原)

#include <Windows.h>
#define  ULONG_PTR ULONG;
#include <GdiPlus.h>
#include <iostream>

using namespace Gdiplus;
#pragma comment(lib, "Gdiplus.lib")
using std::cout;
using std::endl;
using std::wcout;


// 获取图片格式CLSID的自定义函数
int GetEncoderClsid(const WCHAR* format, CLSID* pClsid);


int main()
{
	struct Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG pGdiToken;
	GdiplusStartup(pGdiToken);		// 初始化GDI+
	Image image(L"head.bmp");
	CLSID encoderClsid;

	// 获取JPEG图片格式CLSID
	GetEncoderClsid(L"image/jpeg", &encoderClsid);
	// 创建流
	IStream *pStream;
	CreateStreamOnHGlobal(NULL, TRUE, &pStream);
	image.Save(pStream, &encoderClsid);			// 以JPEG图片格式存储数据到流中
	// 获得流对应的内存句柄
	HGLOBAL hMem;
	GetHGlobalFromStream(pStream, &hMem);
	DWORD dwSize = GlobalSize(hMem);			// 获得内存块的大小

	// 在创建一块内存句柄，用于目标流
	HGLOBAL hDesMem = GlobalAlloc(GMEM_MOVEABLE, dwSize);
	IStream *pDesStream;
	CreateStreamOnHGlobal(hDesMem, TRUE, &pDesStream);
	// 获得内存块首地址
	BYTE *pImgData = (BYTE *)GlobalLock(hMem);
	BYTE *pDesData = (BYTE *)GlobalLock(hDesMem);
	// 复制内存，如果通过网络，就把pImgData里的数据发送过去
	CopyMemory(pDesData, pImgData, dwSize);
	GlobalUnlock(hMem);
	GlobalUnlock(hDesMem);

	// 重建Image
	Image *pImg = Image::FromStream(pDesStream);
	HWND hWnd = FindWindow(NULL, L"无标题.txt-记事本");
	HDC hDC = GetDC(hWnd);
	Graphics graphics(hDC);
	while(TRUE)
	{
		// 绘制图片，测试是否正确
		graphics.DrawImage(pImg, 0, 0, 300, 300);
		Sleep(500);
	}

	system("pause");
	return 0;
}


int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT num = 0, size = 0;
	ImageCodecInfo *pImageCodecInfo = NULL;
	GetImageEncodersSize(&num, &size);
	if(0 == size)
		return -1;

	pImageCodecInfo = (ImageCodecInfo *)(malloc(size));
	if(pImageCodecInfo == NULL)
		return -1;
	GetImageEncoders(num, size, pImageCodecInfo);
	for(UINT j = 0; j < num; ++j)
	{
		if(wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;
		}
	}
	free(pImageCodecInfo);
	pImageCodecInfo = NULL;
	return -1;
}
