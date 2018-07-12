void CMy809View::OnDraw(CDC* pDC)
{
	CMy809Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CPen *pPen,*pOldPen;
	CBrush *pBrush,*pOldBrush;
	CRect r(10,10,110,110);
	pDC->Rectangle(r);
	r.OffsetRect(100,0);
	pOldBrush=(CBrush*)pDC->SelectStockObject(GRAY_BRUSH);
	pDC->Rectangle(r);
	pDC->SelectObject(pOldBrush);

	r.OffsetRect(100,0);
	int left,top,right,bottom;
	clock_t start=clock();
	long delay=3*CLOCKS_PER_SEC;
	while(clock()-start<delay) {
		pBrush=new CBrush(RGB(rand()%256,rand()%256,rand()%256));
		pOldBrush=(CBrush*)pDC->SelectObject(pBrush);
		left=r.left+rand()%100;top=r.top+rand()%100;
		right=r.left+rand()%100;bottom=r.top+rand()%100;
		pDC->FillRect(CRect(left,top,right,bottom),pBrush);
		pDC->SelectObject(pOldBrush);
		delete pBrush;
	}
}