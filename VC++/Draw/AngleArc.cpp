void CMy796View::OnDraw(CDC* pDC)
{
	CMy796Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CPen *pPen,*pOldPen;
	pPen=new CPen(PS_SOLID,3,RGB(0,0,0));
	pOldPen=(CPen*)pDC->SelectObject(pPen);
	int r=40;
	CPoint p(10,100);
	pDC->MoveTo(p);
	int i;
	p.Offset(r,0);	// 设置第一段弧的圆心
	for(i=0;i<7;i++) {
		pDC->AngleArc(p.x,p.y,r,180,-180);
		p.Offset(100,0);
	}
	pDC->SelectObject(pOldPen);
	delete pPen;
}