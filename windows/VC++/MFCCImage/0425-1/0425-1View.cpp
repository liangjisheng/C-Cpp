
// 0425-1View.cpp : implementation of the CMy04251View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "0425-1.h"
#endif

#include "0425-1Doc.h"
#include "0425-1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy04251View

IMPLEMENT_DYNCREATE(CMy04251View, CView)

BEGIN_MESSAGE_MAP(CMy04251View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMy04251View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FILE_OPEN, &CMy04251View::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE_AS, &CMy04251View::OnFileSaveAs)
	ON_COMMAND(ID_CIMAGE_SAVE, &CMy04251View::OnCimageSave)
	ON_COMMAND(ID_CIMAGE_SHOWIMAGE, &CMy04251View::OnCimageShowimage)
	ON_COMMAND(ID_CIMAGE_SHOWPNG, &CMy04251View::OnCimageShowpng)
END_MESSAGE_MAP()

// CMy04251View construction/destruction

CMy04251View::CMy04251View()
{
	m_strRunPath = _T("");
}

CMy04251View::~CMy04251View()
{
}

BOOL CMy04251View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMy04251View drawing

void CMy04251View::OnDraw(CDC* pDC)
{
	CMy04251Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if(!m_Image.IsNull())
		m_Image.Draw(pDC->m_hDC, 0, 0);
}


// CMy04251View printing


void CMy04251View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMy04251View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMy04251View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMy04251View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMy04251View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMy04251View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMy04251View diagnostics

#ifdef _DEBUG
void CMy04251View::AssertValid() const
{
	CView::AssertValid();
}

void CMy04251View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMy04251Doc* CMy04251View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMy04251Doc)));
	return (CMy04251Doc*)m_pDocument;
}
#endif //_DEBUG


void CMy04251View::GetRunPath()
{
	TCHAR szPath[MAX_PATH] = {0};
	GetModuleFileName(NULL, szPath, MAX_PATH);
	m_strRunPath = szPath;
	m_strRunPath = m_strRunPath.Left(m_strRunPath.ReverseFind(_T('\\')) + 1);
}


void CMy04251View::OnFileOpen()
{
	CString strFilter;
	CSimpleArray<GUID> aguidFileTypes;
	HRESULT hResult;

	// 获取CImage支持的图像文件的过滤字符串
	hResult = m_Image.GetExporterFilterString(strFilter, aguidFileTypes,
		_T("All Image Files"));
	if(FAILED(hResult))
	{
		MessageBox(_T("GetExporterFilterString call failed."));
		return;
	}

	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST, strFilter);
	if(IDOK != dlg.DoModal())
		return ;

	m_Image.Destroy();
	hResult = m_Image.Load(dlg.GetFileName());
	if(FAILED(hResult))
	{
		MessageBox(_T("调用图像文件失败"));
		return;
	}

	// 设置主窗口标题栏内容
	CString str = _T("");
	str.LoadString(AFX_IDS_APP_TITLE);
	AfxGetMainWnd()->SetWindowText(str + _T("-") + dlg.GetFileName());

	Invalidate();			// 强制调用OnDarw()
}


void CMy04251View::OnFileSaveAs()
{
	if(m_Image.IsNull())
	{
		MessageBox(_T("not open an Image."));
		return;
	}

	int nFilterExtension = 0;
	CString strFilter = _T("");
	strFilter = _T("位图文件|*.bmp|JPEG图像文件|*.jpg|GIF图像文件|*.gif|PNG图像文件|*.png||");
	CFileDialog dlg(FALSE, NULL, NULL, NULL, strFilter);
	if(IDOK != dlg.DoModal())
		return;
	else
		nFilterExtension = dlg.m_ofn.nFileExtension;

	CString strFileName = _T("");
	CString strExtension = _T("");
	strFileName = dlg.m_ofn.lpstrFile;
	// 如果输入的文件名没有后缀的话，执行下面的if
	if(nFilterExtension == 34)
	{
		switch(dlg.m_ofn.nFilterIndex)
		{
		case 1:
			strExtension = _T("bmp");
			break;
		case 2:
			strExtension = _T("jpg");
			break;
		case 3:
			strExtension = _T("gif");
			break;
		case 4:
			strExtension = _T("png");
			break;
		default:
			break;
		}
		strFileName = strFileName + _T('.') + strExtension;
	}

	HRESULT hResult = m_Image.Save(strFileName);
	if(FAILED(hResult))
		MessageBox(_T("save image failed."));
}


// 柔化和锐化处理
// 在图像处理中，常用一些数学手段对图像进行除去噪声、强调或抽取轮廓特征
// 等图像空间的变换。所谓"图像空间的变换"是借助于一个称之为模板的局部
// 像素域来完成的，不同的模板具有不同的图像效果.

// 1柔化
// 图像的柔化是除去图像中点状噪声是一个有效方法。所谓柔化，是指图像上任何
// 一个像素与其相邻像素的颜色值的大小不会出现陡突的一种处理方法。
// 中间有底纹的表示中心元素，即用那个元素作为处理后的元素。很明显，
// 上述模板(称之为Box模板)是将图像上每个像素用它近旁(包括它本身)的
// 9个像素的平均值取代。这样处理的结果在除噪的同时，也降低图像的对比度，
// 使图像的轮廓模糊。为了避免这一缺陷，我们对各点引入加权系数，
// 将原来的模板修改
// 新的模板可一方面除去点状噪声，同时能较好地保留原图像的对比度，
// 因此该模板得到了广泛的应用。由于这个模板是通过二维高斯(Gauss)函数得到的
// 故称为高斯模板。

// 2锐化
// 锐化和柔化恰恰相反，它通过增强高频分量减少图像中的模糊，
// 因此又称为高通滤波。锐化处理在增强图像边缘效果的同时增加了图像的噪声。
// 常用的锐化模板是拉普拉斯模板
// 用此模板处理后的图像，轮廓线条将明显得到增强。
// 轮廓线以外的部分将变得较暗，而轮廓线部分将变得比较明亮。
// 使用程序对模板进行运算时，要考虑到溢出点的处理。
// 所谓溢出点，指的是大于255或小于0的点。处理时，
// 可令大于255的点取255，而小于0的点取其正值。


void CMy04251View::FilterImage(CImage* image, int nType)
{
	if(image->IsNull())
		return;

	int smoothGauss[9] = {1, 2, 1, 2, 4, 2, 1, 2, 1};	// 高斯模板
	// 拉普拉斯模板
	int sharpLaplacian[9] = {-1, -1, -1, -1, 9, -1, -1, -1, -1};
	int opTemp[9];
	float aver;			// 系数

	if(nType > 1)
		nType = 0;
	switch(nType)
	{
	case 0:				// 高斯模板
		aver = (float)(1.0 / 16.0);
		memcpy(opTemp, smoothGauss, 9 * sizeof(int));
		break;
	case 1:				// 拉普拉斯模板
		aver = 1.0;
		memcpy(opTemp, sharpLaplacian, 9 * sizeof(int));
		break;
	}

	int i, j;
	int nWidth = image->GetWidth();
	int nHeight = image->GetHeight();
	// i,j 从1开始表示最外面的像素点不处理
	for(i = 1; i < nWidth - 1; i++)
	{
		for(j = 1; j < nHeight - 1; j++)
		{
			int rr = 0, gg = 0, bb = 0;
			int index = 0;
			for(int col = -1; col <= 1; col++)
			{
				for(int row = -1; row <= 1; row++)
				{
					COLORREF clr = image->GetPixel(i+row, j+col);
					rr += GetRValue(clr) * opTemp[index];
					gg += GetGValue(clr) * opTemp[index];
					bb += GetBValue(clr) * opTemp[index];
					index++;
				}
			}

			rr = (int)(rr * aver);
			gg = (int)(gg * aver);
			bb = (int)(bb * aver);

			// 处理溢出点
			if(rr > 255) rr = 255;
			else if(rr < 0) rr = -rr;
			if(gg > 255) gg = 255;
			else if(gg < 0) gg = -gg;
			if(bb > 255) bb = 255;
			else if(bb < 0) bb = -bb;

			// 错位重写已避免前一个像素被新的像素覆盖
			image->SetPixel(i - 1, j - 1, RGB(rr, gg, bb));
		}
	}
}


// 由于许多图像文件使用颜色表来发挥显示设备的色彩显示能力，
// 因而将一张彩色图片变成黑色图片时需要调用CImage::IsIndexed
// 来判断是否使用颜色表，若是则修改颜色表，否则直接将像素进行颜色设置。

void CMy04251View::MakeBlackAndWhite(CImage* image)
{
	if(image->IsNull())
		return;

	if(!image->IsIndexed())
	{
		// 没有使用颜色表，直接修改像素颜色
		COLORREF pixel;
		int maxY = image->GetHeight(), maxX = image->GetWidth();
		byte r, g, b, avg;
		for(int x = 0; x < maxX; x++)
		{
			for(int y = 0; y < maxY; y++)
			{
				pixel = image->GetPixel(x, y);
				r = GetRValue(pixel);
				g = GetGValue(pixel);
				b = GetBValue(pixel);
				avg = (int)((r + g + b) / 3);
				image->SetPixelRGB(x, y, avg, avg, avg);
			}
		}
	}
	else
	{
		// 获取并修改颜色表
		int MaxColors = image->GetMaxColorTableEntries();
		RGBQUAD* ColorTable;
		ColorTable = new RGBQUAD[MaxColors];
		image->GetColorTable(0, MaxColors, ColorTable);
		for(int i = 0; i < MaxColors; i++)
		{
			int avg = (ColorTable[i].rgbBlue + ColorTable[i].rgbGreen + ColorTable[i].rgbRed) / 3;
			ColorTable[i].rgbBlue = avg;
			ColorTable[i].rgbGreen = avg;
			ColorTable[i].rgbRed = avg;
		}
		image->SetColorTable(0, MaxColors, ColorTable);
		delete ColorTable;
	}
}


void CMy04251View::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	GetRunPath();
}


void CMy04251View::SaveImage()
{
	CRect rect;
	this->GetClientRect(rect);
	CImage image;
	image.Create(rect.Width(), rect.Height(), 24);
	CDC* DCpoint = this->GetDC();
	DCpoint->Ellipse(20, 20, 200, 200);
	CDC dstDC;
	dstDC.CreateCompatibleDC(DCpoint);
	dstDC.SelectObject(image);
	dstDC.BitBlt(0, 0, rect.Width(), rect.Height(), DCpoint, 0, 0, SRCCOPY);

	HRESULT hRet = image.Save(_T("Save_1.jpg"));
	if(FAILED(hRet))
		AfxMessageBox(_T("save image failed."));
	else
		MessageBox(_T("save image success."), _T("tip"), MB_OKCANCEL | MB_ICONINFORMATION);

	DCpoint->DeleteDC();
	//delete DCpoint;
}


void CMy04251View::OnCimageSave()
{
	SaveImage();
}


void CMy04251View::OnCimageShowimage()
{
	CRect rc;
	this->GetClientRect(rc);

	CImage Img;
	Img.Load(_T("0.jpg"));
	//Img.Draw(this->GetDC()->m_hDC, rc);		// 会拉伸图片，类似于StretchBlt

	// Bitblt方法同CDC类的Bitblt函数一样，是一比一地复制图像并显示在屏幕上，
	// 支持对源图像取反，也就是反色显示。
	// 这样功能通过BitBlt的最后一个参数来实现，比如参数为NOTSRCCOPY就是反色显示。 
	Img.BitBlt(this->GetDC()->m_hDC, rc, CPoint(0, 0), SRCCOPY);

	// MaskBlt可以将图片与目的图片进行特殊的光栅操作并进行掩码处理。
	// PlgBlt函数可以将图片拉伸成平行四边形进行显示。
	// StretchBlt函数可以将图片进行拉伸显示。
}


// PNG 图片的透明背景总是一片白色，后来才发现这其实是微软GDI+的设计问题，
// PNG图片是ARGB，使用GDI+载入图片的时候，GDI+会默认已经进行了 预剩运算（PARGB），
// 即每象素的实际值是已经和ALPHA值按比例相乘的结果，实际上它根本就没有做预乘，
// 在使用透明图片的象素ALPHA通道的时 候，CImage内部正是调用的AlphaBlend，
// 没有预乘的图当作预乘的图片处理的结果就是这相当于一张和纯白背景进行了预剩，
// 所以图象总是出现白 色背景。
void CMy04251View::OnCimageShowpng()
{
	CImage img;
	HRESULT hRet = img.Load(_T("test.png"));
	if(FAILED(hRet))
		return ;

	for(int i = 0; i < img.GetWidth(); i++)
	{
		for(int j = 0; j < img.GetHeight(); j++)
		{
			unsigned char* pucColor = 
				reinterpret_cast<unsigned char*>(img.GetPixelAddress(i, j));
			pucColor[0] = pucColor[0] * pucColor[3] / 255;
			pucColor[1] = pucColor[1] * pucColor[3] / 255;
			pucColor[2] = pucColor[2] * pucColor[3] / 255;
		}
	}

	hRet = img.Save(_T("testProcess.png"));
	if(FAILED(hRet))
		AfxMessageBox(_T("save image failed."));
	else
		AfxMessageBox(_T("save image success."));
}


