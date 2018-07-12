void CMy818View::OnDraw(CDC* pDC)
{
	CMy818Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CString s="黑龙江工程学院";
	TEXTMETRIC tm;
	int x=20,y=30;
	pDC->SetTextColor(RGB(255,0,0));
	pDC->SelectStockObject(ANSI_FIXED_FONT);
	pDC->TextOut(x,y,s+"ANSI_FIXED_FONT");
	pDC->GetTextMetrics(&tm);
	y+=tm.tmHeight+10*tm.tmExternalLeading;
	
	pDC->SetTextColor(RGB(0,255,0));
	pDC->SelectStockObject(SYSTEM_FIXED_FONT);
	pDC->TextOut(x,y,s+"SYSTEM_FIXED_FOTN");
	pDC->GetTextMetrics(&tm);
	y+=tm.tmHeight+10*tm.tmExternalLeading;

	pDC->SetTextColor(RGB(0,0,255));
	pDC->SelectStockObject(DEVICE_DEFAULT_FONT);
	pDC->TextOut(x,y,s+"DEVICE_DEFAULT_FOTN");
	pDC->GetTextMetrics(&tm);
	y+=tm.tmHeight+10*tm.tmExternalLeading;

	pDC->SetTextAlign(TA_LEFT);
	pDC->SetTextColor(RGB(0,128,255));
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextCharacterExtra(10);
	pDC->Rectangle(x,y,x+300,y+20);
	pDC->TextOut(x,y,s);

	CFont zt;
	zt.CreateFont(
		100,		// 定义字体高度为100个逻辑单位
		0,			// 字体宽度为0时,由系统取最佳高度比
		0,			// 每行文本与X轴的夹角为0
		0,			// 每个文字与X轴的夹角为0
		1000,		// 定义字体的笔画粗细度为最粗
		1,			// 定义为斜体
		1,			// 定义下划线
		0,			// 定义无删除线
		ANSI_CHARSET,	// 字符集
		OUT_DEFAULT_PRECIS,	// 输出精度
		CLIP_DEFAULT_PRECIS,	// 裁剪精度
		DEFAULT_QUALITY,		// 字体质量
		DEFAULT_PITCH,
		"自定义字体"
		);
	pDC->SelectObject(zt);
	pDC->TextOut(x,y+50,s);

	CFont nowFont;
	LOGFONT logfont;
	memset(&logfont,0,sizeof(logfont));
	logfont.lfWeight=60;
	logfont.lfHeight=60;
	logfont.lfEscapement=30*10;
	lstrcpy(logfont.lfFaceName,"自定义字体");
	nowFont.CreateFontIndirect(&logfont);
	pDC->SelectObject(nowFont);
	pDC->SetTextColor(RGB(192,192,192));
	pDC->SetBkColor(RGB(128,128,192));
	pDC->SetBkMode(OPAQUE);
	pDC->SetTextCharacterExtra(20);
	pDC->TextOut(150,y+150,s);
}