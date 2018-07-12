void CMy1053View::OnDraw(CDC* pDC)
{
	CMy1053Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	/*for(int i=0;i<50;i++)
		pDC->SetPixel(CPoint(200+i,200),RGB(255,0,0));
	CRect r;
	r.SetRect(CPoint(0,0),CPoint(200,200));
	pDC->SelectStockObject(LTGRAY_BRUSH);
	pDC->SelectStockObject(WHITE_PEN);
	pDC->FillRect(&r,new CBrush(RGB(255,0,0)));
	pDC->MoveTo(0,0);
	pDC->LineTo(200,200);
	pDC->MoveTo(200,0);
	pDC->LineTo(0,200);
	pDC->SelectStockObject(BLACK_PEN);
	pDC->MoveTo(10,10);
	pDC->LineTo(10,100);
	CRect rect(20,20,100,100);
	pDC->Rectangle(rect);
	pDC->Ellipse(&rect);
	CPoint poly[4];
	poly[0]=(0,0);
	poly[1]=(50,50);
	poly[2]=(50,100);
	poly[3]=(0,50);
	pDC->Polygon(poly,4);
	
	// PS_DASHDOT,PS_DASHDOTDOT,PS_DOT,PS_INSIDEFRAME,PS_NULL
	CPen mypen1(PS_SOLID,2,RGB(255,0,0));
	CPen mypen2;
	mypen2.CreatePen(PS_DOT,2,RGB(255,0,0));
	CBrush bs1,bs2,bs3,bs4;
	bs1.CreateSolidBrush(RGB(255,0,0));
	// 创建阴影线画刷
	// HS_BDIAGONAL,HS_FDIAGONAL,HS_DIAGCROSS,HS_HORIZONTAL,HS_VERTICAL
	bs2.CreateHatchBrush(HS_CROSS,RGB(255,0,0));
	// 创建位图画刷
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);
	bs3.CreatePatternBrush(&bmp);

	pDC->SetMapMode(MM_ANISOTROPIC);
	CPen * pOldPen;
	CPen npen;
	npen.CreatePen(PS_SOLID,5,RGB(0,0,255));
	pOldPen=pDC->SelectObject(&npen);
	CBrush brush1;
	CBrush * brush2;
	brush1.CreateSolidBrush(RGB(0,0,128));
	brush2=pDC->SelectObject(&brush1);
	pDC->RoundRect(200,100,330,200,15,15);
	pDC->SelectStockObject(LTGRAY_BRUSH);
	pDC->Pie(350,50,420,150,360,50,400,50);
	CBrush brush3;
	brush3.CreateHatchBrush(HS_DIAGCROSS,RGB(125,125,125));
	pDC->SelectObject(&brush3);
	pDC->Ellipse(50,50,150,150);*/
	SetTimer(1,100,NULL);

	pDC->SetMapMode(m_mode);
	pDC->SetWindowExt(150,150);
	pDC->SetViewportExt(150,100);
	pDC->SetViewportOrg(50,60);
	pDC->SelectStockObject(BLACK_BRUSH);
	pDC->RoundRect(0,0,150,150,30,30);
	pDC->SelectStockObject(WHITE_BRUSH);
	pDC->Ellipse(0,10,150,140);
}

void CMy1053View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if((i++%2)==0) m_mode=MM_ISOTROPIC;
	else m_mode=MM_ANISOTROPIC;
	this->InvalidateRect(NULL,true);
	CView::OnLButtonDown(nFlags, point);
}

void CMy1053View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if((i++%2)==0) m_mode=MM_ISOTROPIC;
	else m_mode=MM_ANISOTROPIC;
	this->InvalidateRect(NULL,true);
	CView::OnTimer(nIDEvent);
}
