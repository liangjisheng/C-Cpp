CMy820View::CMy820View()
{
	flag=0;
}

void CMy820View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CDC* dc=GetDC();	// 取得当前绘图设备的指针
	CPen newpen(PS_SOLID,0,RGB(255,0,0));
	CPen* oldpen;
	if(flag==0) {
		flag=1;
		start=end=point;
	}
	else {
		oldpen=dc->SelectObject(&newpen);
		dc->SetROP2(R2_XORPEN);	// 画线模式为异或
		dc->MoveTo(start);
		dc->LineTo(end);
		end=point;
		dc->SetROP2(R2_COPYPEN);// 画线模式为复制画笔
		dc->MoveTo(start);
		dc->LineTo(end);
		dc->SelectObject(oldpen);
		flag=0;	//设置直线起点输入状态
	}
	ReleaseDC(dc);

	CView::OnLButtonDown(nFlags, point);
}

void CMy820View::OnMouseMove(UINT nFlags, CPoint point) 
{
	CDC* dc=GetDC();
	CPen newpen(PS_SOLID,0,RGB(255,0,0));
	CPen* oldpen=dc->SelectObject(&newpen);
	dc->SetROP2(R2_XORPEN);
	if(flag==1) {
		dc->MoveTo(start);
		dc->LineTo(end);
		end=point;
		dc->MoveTo(start);// 显示原来的背景色
		dc->LineTo(end);
	}
	dc->SetROP2(R2_COPYPEN);
	dc->SelectObject(oldpen);
	ReleaseDC(dc);

	CView::OnMouseMove(nFlags, point);
}

void CMy820View::OnRButtonDown(UINT nFlags, CPoint point) 
{
	CDC* dc=GetDC();
	CPen newpen(PS_SOLID,0,RGB(255,0,0));
	CPen* oldpen=dc->SelectObject(&newpen);
	if(flag==1) {
		dc->SetROP2(R2_XORPEN);
		dc->MoveTo(start);
		dc->LineTo(end);
		dc->SetROP2(R2_COPYPEN);
		flag=0;
	}
	dc->SelectObject(oldpen);
	ReleaseDC(dc);

	CView::OnRButtonDown(nFlags, point);
}
