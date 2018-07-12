void CMy808View::OnDraw(CDC* pDC)
{
	CMy808Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CPen *pPen,*pOldPen;
	CBrush *pBrush,*pOldBrush;
	pPen=new CPen(PS_SOLID,3,RGB(0,0,0));
	pOldPen=(CPen*)pDC->SelectObject(pPen);
	pBrush=new CBrush(HS_DIAGCROSS,RGB(0,0,255));
	pOldBrush=(CBrush*)pDC->SelectObject(pBrush);
	//pDC->SetBkMode(OPAQUE);

	pDC->SetMapMode(MM_TEXT);
	pDC->SetArcDirection(AD_COUNTERCLOCKWISE);
	pDC->Pie(20,20,200,200,180,20,180,200);
	pDC->SetViewportOrg(320,0);
	pDC->Chord(20,20,200,200,180,20,180,200);

	pDC->SetArcDirection(AD_CLOCKWISE);
	pDC->SetViewportOrg(50,0);
	pDC->Pie(20,20,200,200,180,20,180,200);
	pDC->SetViewportOrg(370,0);
	pDC->Chord(20,20,200,200,180,20,180,200);

	pDC->SelectObject(pOldPen);
	delete pPen;
	pDC->SelectObject(pOldBrush);
	delete pBrush;
}