void CMy810View::OnDraw(CDC* pDC)
{
	CMy810Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CBrush *pBrush1,*pBrush2;
	CRect r(50,50,220,200);
	pBrush1=new CBrush(HS_DIAGCROSS,RGB(255,0,0));
	pBrush2=new CBrush(HS_BDIAGONAL,RGB(0,0,0));
	pDC->FillRect(r,pBrush1);
	r+=CSize(70,70);
	pDC->SetBkColor(RGB(192,128,192));
	pDC->FillRect(r,pBrush2);
	delete pBrush1;
	delete pBrush2;
	r+=CSize(70,-40);
	pDC->FillSolidRect(r,RGB(0,128,255));
}