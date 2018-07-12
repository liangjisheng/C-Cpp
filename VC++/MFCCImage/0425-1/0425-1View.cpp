
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

	// ��ȡCImage֧�ֵ�ͼ���ļ��Ĺ����ַ���
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
		MessageBox(_T("����ͼ���ļ�ʧ��"));
		return;
	}

	// ���������ڱ���������
	CString str = _T("");
	str.LoadString(AFX_IDS_APP_TITLE);
	AfxGetMainWnd()->SetWindowText(str + _T("-") + dlg.GetFileName());

	Invalidate();			// ǿ�Ƶ���OnDarw()
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
	strFilter = _T("λͼ�ļ�|*.bmp|JPEGͼ���ļ�|*.jpg|GIFͼ���ļ�|*.gif|PNGͼ���ļ�|*.png||");
	CFileDialog dlg(FALSE, NULL, NULL, NULL, strFilter);
	if(IDOK != dlg.DoModal())
		return;
	else
		nFilterExtension = dlg.m_ofn.nFileExtension;

	CString strFileName = _T("");
	CString strExtension = _T("");
	strFileName = dlg.m_ofn.lpstrFile;
	// ���������ļ���û�к�׺�Ļ���ִ�������if
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


// �ữ���񻯴���
// ��ͼ�����У�����һЩ��ѧ�ֶζ�ͼ����г�ȥ������ǿ�����ȡ��������
// ��ͼ��ռ�ı任����ν"ͼ��ռ�ı任"�ǽ�����һ����֮Ϊģ��ľֲ�
// ����������ɵģ���ͬ��ģ����в�ͬ��ͼ��Ч��.

// 1�ữ
// ͼ����ữ�ǳ�ȥͼ���е�״������һ����Ч��������ν�ữ����ָͼ�����κ�
// һ�����������������ص���ɫֵ�Ĵ�С������ֶ�ͻ��һ�ִ�������
// �м��е��Ƶı�ʾ����Ԫ�أ������Ǹ�Ԫ����Ϊ������Ԫ�ء������ԣ�
// ����ģ��(��֮ΪBoxģ��)�ǽ�ͼ����ÿ��������������(����������)��
// 9�����ص�ƽ��ֵȡ������������Ľ���ڳ����ͬʱ��Ҳ����ͼ��ĶԱȶȣ�
// ʹͼ�������ģ����Ϊ�˱�����һȱ�ݣ����ǶԸ��������Ȩϵ����
// ��ԭ����ģ���޸�
// �µ�ģ���һ�����ȥ��״������ͬʱ�ܽϺõر���ԭͼ��ĶԱȶȣ�
// ��˸�ģ��õ��˹㷺��Ӧ�á��������ģ����ͨ����ά��˹(Gauss)�����õ���
// �ʳ�Ϊ��˹ģ�塣

// 2��
// �񻯺��ữǡǡ�෴����ͨ����ǿ��Ƶ��������ͼ���е�ģ����
// ����ֳ�Ϊ��ͨ�˲����񻯴�������ǿͼ���ԵЧ����ͬʱ������ͼ���������
// ���õ���ģ����������˹ģ��
// �ô�ģ�崦����ͼ���������������Եõ���ǿ��
// ����������Ĳ��ֽ���ýϰ����������߲��ֽ���ñȽ�������
// ʹ�ó����ģ���������ʱ��Ҫ���ǵ������Ĵ���
// ��ν����㣬ָ���Ǵ���255��С��0�ĵ㡣����ʱ��
// �������255�ĵ�ȡ255����С��0�ĵ�ȡ����ֵ��


void CMy04251View::FilterImage(CImage* image, int nType)
{
	if(image->IsNull())
		return;

	int smoothGauss[9] = {1, 2, 1, 2, 4, 2, 1, 2, 1};	// ��˹ģ��
	// ������˹ģ��
	int sharpLaplacian[9] = {-1, -1, -1, -1, 9, -1, -1, -1, -1};
	int opTemp[9];
	float aver;			// ϵ��

	if(nType > 1)
		nType = 0;
	switch(nType)
	{
	case 0:				// ��˹ģ��
		aver = (float)(1.0 / 16.0);
		memcpy(opTemp, smoothGauss, 9 * sizeof(int));
		break;
	case 1:				// ������˹ģ��
		aver = 1.0;
		memcpy(opTemp, sharpLaplacian, 9 * sizeof(int));
		break;
	}

	int i, j;
	int nWidth = image->GetWidth();
	int nHeight = image->GetHeight();
	// i,j ��1��ʼ��ʾ����������ص㲻����
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

			// ���������
			if(rr > 255) rr = 255;
			else if(rr < 0) rr = -rr;
			if(gg > 255) gg = 255;
			else if(gg < 0) gg = -gg;
			if(bb > 255) bb = 255;
			else if(bb < 0) bb = -bb;

			// ��λ��д�ѱ���ǰһ�����ر��µ����ظ���
			image->SetPixel(i - 1, j - 1, RGB(rr, gg, bb));
		}
	}
}


// �������ͼ���ļ�ʹ����ɫ����������ʾ�豸��ɫ����ʾ������
// �����һ�Ų�ɫͼƬ��ɺ�ɫͼƬʱ��Ҫ����CImage::IsIndexed
// ���ж��Ƿ�ʹ����ɫ���������޸���ɫ������ֱ�ӽ����ؽ�����ɫ���á�

void CMy04251View::MakeBlackAndWhite(CImage* image)
{
	if(image->IsNull())
		return;

	if(!image->IsIndexed())
	{
		// û��ʹ����ɫ��ֱ���޸�������ɫ
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
		// ��ȡ���޸���ɫ��
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
	//Img.Draw(this->GetDC()->m_hDC, rc);		// ������ͼƬ��������StretchBlt

	// Bitblt����ͬCDC���Bitblt����һ������һ��һ�ظ���ͼ����ʾ����Ļ�ϣ�
	// ֧�ֶ�Դͼ��ȡ����Ҳ���Ƿ�ɫ��ʾ��
	// ��������ͨ��BitBlt�����һ��������ʵ�֣��������ΪNOTSRCCOPY���Ƿ�ɫ��ʾ�� 
	Img.BitBlt(this->GetDC()->m_hDC, rc, CPoint(0, 0), SRCCOPY);

	// MaskBlt���Խ�ͼƬ��Ŀ��ͼƬ��������Ĺ�դ�������������봦��
	// PlgBlt�������Խ�ͼƬ�����ƽ���ı��ν�����ʾ��
	// StretchBlt�������Խ�ͼƬ����������ʾ��
}


// PNG ͼƬ��͸����������һƬ��ɫ�������ŷ�������ʵ��΢��GDI+��������⣬
// PNGͼƬ��ARGB��ʹ��GDI+����ͼƬ��ʱ��GDI+��Ĭ���Ѿ������� Ԥʣ���㣨PARGB����
// ��ÿ���ص�ʵ��ֵ���Ѿ���ALPHAֵ��������˵Ľ����ʵ������������û����Ԥ�ˣ�
// ��ʹ��͸��ͼƬ������ALPHAͨ����ʱ ��CImage�ڲ����ǵ��õ�AlphaBlend��
// û��Ԥ�˵�ͼ����Ԥ�˵�ͼƬ����Ľ���������൱��һ�źʹ��ױ���������Ԥʣ��
// ����ͼ�����ǳ��ְ� ɫ������
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


