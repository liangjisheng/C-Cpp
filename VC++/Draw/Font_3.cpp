int CMy932View::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// 1为定时标识，1000表示每隔1000毫秒触发一次,NULL指定OnTime()为响应函数
	SetTimer(1,1000,NULL);	
	
	return 0;
}

void CMy932View::OnTimer(UINT nIDEvent) 
{
	LOGFONT lf;
	CRect rect;
	GetClientRect(&rect);
	CFont * pOldFont;
	CFont OldFont;
	CDC * pDC=GetDC();
	pOldFont=pDC->SelectObject(&OldFont);
	pDC->FillRect(rect,WHITE_BRUSH);
	CFont font;
	UINT m_Orientation=0;

	// 设置字体结构
	lf.lfCharSet=GB2312_CHARSET;
	lf.lfClipPrecision=CLIP_STROKE_PRECIS;
	lf.lfEscapement=0;	// 文本输出角度
	strcpy(lf.lfFaceName,"黑体");
	lf.lfHeight=50;
	lf.lfItalic=true;
	lf.lfOrientation=m_Orientation;	// 字符基线与X轴的夹角
	lf.lfOutPrecision=OUT_STROKE_PRECIS;
	lf.lfPitchAndFamily=VARIABLE_PITCH | FF_MODERN;
	lf.lfQuality=DRAFT_QUALITY;
	lf.lfStrikeOut=true;	// 指定是否突出字符
	lf.lfUnderline=true;
	lf.lfWeight=FW_NORMAL;
	lf.lfWidth=0;

	font.CreateFontIndirect(&lf);
	pDC->SetBkColor(RGB(rand()%255,rand()%255,rand()%255));
	pDC->SetTextColor(RGB(rand()%255,rand()%255,rand()%255));
	pDC->SelectObject(font);
	pDC->TextOut(rand()%rect.right,rand()%rect.bottom,
		"Visual C++ 6.0 编程入门");
	m_Orientation+=9;	// 改变角度

	pDC->SelectObject(pOldFont);
	ReleaseDC(pDC);
	CView::OnTimer(nIDEvent);
}
