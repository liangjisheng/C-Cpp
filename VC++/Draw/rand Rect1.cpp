void CMy794View::OnDraw(CDC* pDC)
{
	CMy794Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CPen *pPen,*pOldPen;
	CBrush *pBrush,*pOldBrush;
	CRect r(30,20,80,240);
	COLORREF ps[4]={RGB(0,255,255),RGB(192,192,192),
					RGB(255,255,0),RGB(192,0,255)};
	int i;
	for(i=0;i<4;i++) {
		pBrush=new CBrush(ps[i]);
		pOldBrush=(CBrush*)pDC->SelectObject(pBrush);
		pDC->Rectangle(r);
		r+=CPoint(50,0);
		pDC->SelectObject(pOldBrush);
		delete pBrush;
	}

	pPen=new CPen(PS_SOLID,8,RGB(192,0,128));
	pOldPen=(CPen*)pDC->SelectObject(pPen);
	pOldBrush=(CBrush*)pDC->SelectStockObject(HOLLOW_BRUSH);
	r=CRect(50,50,210,210);
	int rop2[4]={R2_XORPEN,R2_NOT,R2_WHITE,R2_COPYPEN};
	for(i=0;i<4;i++) {
		pDC->SetROP2(rop2[i]);	// 设置绘图方式
		pDC->Rectangle(r);
		r.DeflateRect(18,18);
	}
	pDC->SelectObject(pPen);
	delete pPen;
	pDC->SelectObject(pOldBrush);

	srand((unsigned)time(NULL));
	CRect ra(250,20,250,250);
	//double second=5;
	clock_t start=clock();
	clock_t delay=5*CLOCKS_PER_SEC;
	//int left,top,wi,hi;
	while(1) {
		pBrush=new CBrush(RGB(rand()%256,rand()%256,rand()%256));
		pOldBrush=(CBrush*)pDC->SelectObject(pBrush);
		pDC->Rectangle(ra.left+rand()%250,ra.top+rand()%250,
						ra.left+rand()%250,ra.top+rand()%250);

		/*pBrush->CreateSolidBrush(RGB(rand()%256,rand()%256,rand()%256));
		pOldBrush=(CBrush*)pDC->SelectObject(pBrush);
		left=ra.left+rand()%ra.Width(); top=ra.top+rand()%ra.Height();
		wi=rand()%(ra.Width()-(left-ra.left));
		hi=rand()%(ra.Height()-(top-ra.top));
		pDC->FillRect(CRect(left,top,wi,hi),pBrush);*/

		pDC->SelectObject(pOldBrush);
		delete pBrush;
		if(clock()-start>delay) {
			start+=2*delay;
			Sleep(delay);
		}
	}

}