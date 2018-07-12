CMy1066View::CMy1066View()
{
	bCtrldown=bShiftdown=bShiftup=bShiftB=false;
	bCtrlup=false;
}

void CMy1066View::OnDraw(CDC* pDC)
{
	CMy1066Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	int Height=tm.tmHeight;
	if(bShiftdown) {
		pDC->TextOut(30,0,"用户按下了Shift键");
		bShiftdown=false;
	}
	if(bShiftup) {
		pDC->TextOut(30,Height,"用户释放了Shift键");	
		bShiftup=false;
	}
	if(bShiftB) {
		pDC->TextOut(30,2*Height,"用户按下b键");
		bShiftB=false;
	}
	if(bCtrldown) {
		pDC->TextOut(30,3*Height,"用户按下了Ctrl键");
		bCtrldown=false;
	}
	if(bCtrlup) {
		pDC->TextOut(30,4*Height,"用户释放了Ctrl键");
		bCtrlup=false;
	}

	// 创建插入符
	CreateSolidCaret(tm.tmAveCharWidth/8,tm.tmHeight);
	pDC->TextOut(0,0,"asdf");
	// 获取字符的宽高
	CSize s=pDC->GetTextExtent("asdf");
	POINT caretpos;
	caretpos.x=s.cx;
	caretpos.y=0;
	HideCaret();	// 隐藏插入符
	SetCaretPos(caretpos);	// 设置插入符的位置
	ShowCaret();	// 在当前位置显示插入符
}

void CMy1066View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// 获取原鼠标有效的活动区域
	GetClipCursor(&rcOldClip);
	startPoint=point;
	SetCapture();	// 鼠标捕捉
	CView::OnLButtonDown(nFlags, point);
}

void CMy1066View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	ClipCursor(&rcOldClip);	// 恢复原来的鼠标活动区域
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}

void CMy1066View::OnMouseMove(UINT nFlags, CPoint point) 
{
	CDC * pDC=GetDC();
	HCURSOR cursor;
	RECT rcClip;	// 限制矩形区域
	if((nFlags & MK_LBUTTON)==MK_LBUTTON) {
		GetWindowRect(&rcClip);
		ClipCursor(&rcClip);	// 限制鼠标的移动
		// 载入标准的十字光标
		cursor=AfxGetApp()->LoadStandardCursor(IDC_CROSS);
		SetCursor(cursor);
		pDC->MoveTo(startPoint.x,startPoint.y);
		pDC->LineTo(point.x,point.y);
		startPoint=point;
	}
	CView::OnMouseMove(nFlags, point);
}

void CMy1066View::OnRButtonDown(UINT nFlags, CPoint point) 
{
	CDC * pDC=GetDC();
	pDC->SelectStockObject(WHITE_BRUSH);
	CRect r;
	GetClientRect(&r);
	pDC->FillRect(r,WHITE_BRUSH);
	CView::OnRButtonDown(nFlags, point);
}

void CMy1066View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if(nChar=='b' || nChar=='B') {
		//if(bShiftdown) {
			bShiftB=true;
		//	bShiftdown=false;
			Invalidate(true);	// 调用OnDraw()
		//}
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CMy1066View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if(nChar==VK_SHIFT) {
		bShiftdown=true;
		bShiftup=false;
		Invalidate(true);
	}
	if(nChar==VK_CONTROL) {
		bCtrldown=true;
		bCtrlup=false;
		Invalidate(true);
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CMy1066View::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	if(nChar==VK_SHIFT) {
		bShiftdown=false;
		bShiftup=true;
		Invalidate(true);
	}
	if(nChar==VK_CONTROL) {
		bCtrldown=false;
		bCtrlup=true;
		Invalidate(true);
	}
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}

void CMy1066View::OnUseExplain() 
{
	CString str;
	str="使用说明\r\n";
	str+="单击左键开始画图\r\n";
	str+="单击右键清除客户区\r\n";
	str+="响应shift,Ctrl,b键的按下和释放\r\n";
	MessageBox(str,"title",MB_OK | MB_ICONINFORMATION);
}
