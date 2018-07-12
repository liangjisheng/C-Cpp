void CMy812View::OnDraw(CDC* pDC)
{
	CMy812Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect cr;
	GetClientRect(&cr);
	pDC->SetMapMode(MM_ISOTROPIC);// 设置映射模式
	pDC->SetWindowExt(1000,1000);
	pDC->SetViewportExt(cr.right,-cr.bottom);
	pDC->SetViewportOrg(cr.right/2,cr.bottom/2);
	pDC->FillSolidRect(-750,-500,1500,1000,RGB(255,0,0));
	CPoint p(0,0);
	CRect r;

	r.SetRect(p.x-400,p.y-400,p.x+400,p.y+400);
	pDC->SelectStockObject(WHITE_BRUSH);
	pDC->SelectStockObject(WHITE_PEN);
	pDC->Pie(r,CPoint(p.x,p.y+400),CPoint(p.x,p.y-400));// 绘制左半圆

	pDC->SetArcDirection(AD_CLOCKWISE);
	pDC->SelectStockObject(BLACK_PEN);
	pDC->SelectStockObject(BLACK_BRUSH);
	pDC->Pie(r,CPoint(p.x,p.y+400),CPoint(p.x,p.y-400));// 绘制右半圆

	r.SetRect(p.x-200,p.y,p.x+200,p.y-400);
	pDC->SelectStockObject(WHITE_BRUSH);
	pDC->SelectStockObject(WHITE_PEN);
	pDC->Pie(r,p,CPoint(p.x,p.y-400));

	r.SetRect(p.x-200,p.y+400,p.x+200,p.y);
	pDC->SelectStockObject(BLACK_BRUSH);
	pDC->SelectStockObject(BLACK_PEN);
	pDC->Pie(r,p,CPoint(p.x,p.y-400));

	r.SetRect(p.x-20,p.y-180,p.x+20,p.y-220);
	pDC->Ellipse(r);
	r.SetRect(p.x-20,p.y+220,p.x+20,p.y+180);
	pDC->SelectStockObject(WHITE_BRUSH);
	pDC->SelectStockObject(WHITE_PEN);
	pDC->Ellipse(r);
}