CMy822View::CMy822View()
{
	Isfirst=0;
	old_t=t=0;
	xo=200;yo=200;
	length=300;
	radius=80;
	hight=80;
}

void CMy822View::OnDraw(CDC* pDC)
{
	CMy822Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	Isfirst=0;						//由于窗口刷新，设定为初次
	CPen newP1(PS_SOLID,1,RGB(0,0,0)); 
	CPen *oldP=(CPen *)pDC->SelectObject(&newP1); 
	pDC->SetROP2(R2_COPYPEN);		//设置画线模式为复制画笔
	pDC->MoveTo(xo+radius, yo+hight+12); 
	pDC->LineTo(xo+radius+length+50, yo+hight+12); 
	int d; 
	for(d=xo+radius; d<=xo+radius+length+50; d+=10) 
	{ 
		pDC->MoveTo(d-10, yo+hight+22); 
		pDC->LineTo(d, yo+hight+12);  
	} 
	CPen newP2(PS_DASHDOT,1,RGB(0,0,0)); 
	pDC->SelectObject(&newP2); 
	pDC->MoveTo(xo-radius-20, yo); 
	pDC->LineTo(xo+radius+20, yo); 
	pDC->MoveTo(xo, yo-radius-20); 
	pDC->LineTo(xo, yo+radius+20); 
	pDC->SelectStockObject(HOLLOW_BRUSH); //设置空画刷
	CPen newP3(PS_SOLID,5,RGB(0,0,192)); 
	pDC->SelectObject(&newP3); 
	pDC->Ellipse(xo-radius,yo-radius,xo+radius,yo+radius); 
	CPen newP4(PS_SOLID,2,RGB(0,0,0)); 
	pDC->SelectObject(&newP4); 
	pDC->Ellipse(xo-3,yo-3,xo+3,yo+3); 
	pDC->SelectObject(oldP); 
}

void CMy822View::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	int nTimer=SetTimer(ID_TIMER,50,NULL);
	ASSERT(nTimer!=0);
}

void CMy822View::OnDestroy() 
{
	CView::OnDestroy();
	
	KillTimer(ID_TIMER);
}

void CMy822View::draw_crank(CClientDC &dc, int a)
{
	int xa,ya,xb,yb;
	xa=xo+(int)(radius*cos((float)a*0.01745));
	ya=yo-(int)(radius*sin((float)a*0.01745));
	yb=yo+hight;
	xb=xa+(int)sqrt(length*length-(yb-ya)*(yb-ya));
	dc.MoveTo(xo,yo);
	dc.LineTo(xa,ya);dc.LineTo(xb,yb);
	dc.Ellipse(xa-3,ya-3,xa+3,ya+3);
	dc.Ellipse(xb-3,yb-3,xb+3,yb+3);
	dc.Rectangle(xb-15,yb-10,xb+15,yb+10);
}

void CMy822View::OnTimer(UINT nIDEvent) 
{
	CClientDC dc(this); 
	OnPrepareDC(&dc); 
	CPen newP(PS_SOLID,5,RGB(0,255,255)); 
	CPen *oldP=dc.SelectObject(&newP); 
	dc.SetROP2(R2_XORPEN);					//设置画线模式为异或
	dc.SelectStockObject(HOLLOW_BRUSH);		//设置空画刷
	if(Isfirst!=0) draw_crank(dc,old_t);	//如果不是初次，则擦除上次图形
	draw_crank(dc,t);						//画出新位置的图形
	old_t=t;								//保存当前位置
	dc.SetROP2(R2_COPYPEN);					//设置画线模式为复制画笔
	dc.SelectObject(oldP); 
	Isfirst=1;								//设定为不是初次
	t+=3;									//曲柄旋转的角度增量为3度
	if(t>360)t-=360; 
	CView::OnTimer(nIDEvent);
}
