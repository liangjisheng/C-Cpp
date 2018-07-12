void CMy797View::OnDraw(CDC* pDC)
{
	CMy797Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CPen *pPen,*pOldPen;
	pPen=new CPen(PS_SOLID,3,RGB(0,0,0));
	pOldPen=(CPen*)pDC->SelectObject(pPen);
	POINT pp[12]={50,100,50,200,200,200,200,100,
				  170,100,170,50,80,50,80,100,
				70,120,70,180,180,180,180,120};
	BYTE pt[12]={PT_MOVETO,PT_LINETO,PT_LINETO,PT_LINETO,PT_LINETO,
		PT_BEZIERTO,PT_BEZIERTO,PT_BEZIERTO|PT_CLOSEFIGURE,
		PT_MOVETO,PT_LINETO,PT_LINETO,PT_LINETO|PT_CLOSEFIGURE
	};
	pDC->PolyDraw(pp,pt,12);
	pDC->SelectObject(pOldPen);
	delete pPen;
}