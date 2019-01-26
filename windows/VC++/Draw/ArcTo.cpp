void CMy795View::OnDraw(CDC* pDC)
{
	CMy795Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CPen *pPen,*pOldPen;
	CRect r(10,50,65,150);
	CPoint p1,p2;
	pPen=new CPen(PS_SOLID,3,RGB(0,0,0));
	pOldPen=(CPen*)pDC->SelectObject(pPen);
	int y=(r.top+r.bottom)/2;
	int i;
	for(i=0;i<14;i++) {
		if(i%2) pDC->SetArcDirection(AD_COUNTERCLOCKWISE);
		else pDC->SetArcDirection(AD_CLOCKWISE);
		p1=CPoint(r.left,y);
		p2=CPoint(r.right,y);
		if(i==0) pDC->MoveTo(p1);
		pDC->ArcTo(r,p1,p2);
		r+=CSize(70,0);
	}

	pDC->SelectObject(pOldPen);
	delete pPen;
}