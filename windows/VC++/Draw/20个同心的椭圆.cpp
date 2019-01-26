void CMy813View::OnDraw(CDC* pDC)
{
	CMy813Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect cr;
	GetClientRect(&cr);
	pDC->SetMapMode(MM_ISOTROPIC);
	pDC->SetWindowExt(2000,2000);
	pDC->SetViewportExt(cr.right,-cr.bottom);
	pDC->SetViewportOrg(cr.right/2,cr.bottom/2);
	pDC->SelectStockObject(HOLLOW_BRUSH);
	int i;
	CRect r(-1000,0,1000,0);
	for(i=1;i<=20;i++) {
		if(r.Height()==0 || r.Width()==0) {
			pDC->MoveTo(r.TopLeft());
			pDC->LineTo(r.BottomRight());
		}
		else
			pDC->Ellipse(r);
		r.left+=50;
		r.top+=50;
		r.right-=50;
		r.bottom-=50;
	}
}