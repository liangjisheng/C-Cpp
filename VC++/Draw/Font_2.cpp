void CMy931View::OnDraw(CDC* pDC)
{
	CMy931Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	int nFontH;	// 字体高度
	int pos=0;	// 文本在Y轴上的位置
	CString csFontType[]={"Webdings","Arial black","Monotype Corsiva",
		"楷体_GB2312","隶书","黑体","华云彩文","华文新魏","华文行楷"};
	CFont oldFont;
	CFont * poldFont=pDC->SelectObject(&oldFont);
	UINT nCharset;	// 字体名称数组索引
	BYTE bItalic;	// 斜体标识
	BYTE bUnderline;	// 下划线标识
	int x;
	for(x=0;x<9;x++) {
		CFont font;
		nFontH=16+x*6;	// 创建字体高度
		switch(x) {
		case 0:
			nCharset=SYMBOL_CHARSET;	// 符号字符集
			bItalic=false;
			bUnderline=false;
			break;
		case 1:
			nCharset=ANSI_CHARSET;
			bItalic=!bItalic;
			bUnderline=!bUnderline;
			break;
		case 2:
			nCharset=ANSI_CHARSET;
			bItalic=!bItalic;
			bUnderline=!bUnderline;
			break;
		default:
			nCharset=GB2312_CHARSET;
			bItalic=!bItalic;
			bUnderline=!bUnderline;
		}
		font.CreateFont(
			-nFontH,
			0,
			0,
			0,
			FW_NORMAL,
			bItalic,
			bUnderline,
			false,
			nCharset,
			OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,
			DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_MODERN,
			csFontType[x]
			);
		pDC->SelectObject(&font);
		pos+=nFontH;
		pDC->TextOut(20,pos,"Visual C++ 6.0 字体展示");
	}
	pDC->SelectObject(poldFont);
}