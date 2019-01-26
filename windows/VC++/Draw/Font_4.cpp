void CMy938View::OnDraw(CDC* pDC)
{
	CMy938Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	for(int i=0;i<10;i++) {
		CFont myFont;
		myFont.CreateFont(56,
			20, //宽度(旋转后的字体高度)
			i*360, //角度 以0.1度为单位
			0,//Orientation
			10, //磅数
			FALSE, //斜体
			FALSE, //下划线   
			FALSE, //删除线
			DEFAULT_CHARSET, //使用缺省字符集
			OUT_DEFAULT_PRECIS, //缺省输出精度
			CLIP_DEFAULT_PRECIS,//缺省裁减精度
			DEFAULT_QUALITY, //nQuality=缺省值
			DEFAULT_PITCH, //nPitchAndFamily=缺省值  
			"黑体"); //字体名
		CFont *pOldFont=(CFont*)pDC->SelectObject(&myFont);
		CRect rtClient;  
		GetClientRect(&rtClient);  
		pDC->TextOut(rtClient.Width()/2+30,rtClient.Height()/8,"无边落木萧萧下");
		pDC->SelectObject(pOldFont);
		myFont.DeleteObject();

		Sleep(1000);
	}
	
	LOGFONT lf;
	lf.lfWeight=10;
	lf.lfHeight=56;
	lf.lfWidth=20;
	lf.lfUnderline=FALSE;
	lf.lfStrikeOut=FALSE;
	lf.lfItalic=FALSE;
	lf.lfEscapement=2700;
	lf.lfCharSet=DEFAULT_CHARSET;
	strcpy(lf.lfFaceName,"黑体"); 

   /* CFont myLogFont; 
	myLogFont.CreateFontIndirect(&lf); 
	pOldFont=dc.SelectObject(&myLogFont);
	dc.TextOut(rtClient.Width()/2-30,rtClient.Height()/8,"不尽长江滚滚来");  
	dc.SelectObject(pOldFont);
	myLogFont.DeleteObject();*/
}