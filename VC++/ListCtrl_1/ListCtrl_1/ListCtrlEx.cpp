// ListCtrlEx.cpp : 实现文件
//

#include "stdafx.h"
#include "ListCtrlEx.h"


// CListCtrlEx
IMPLEMENT_DYNAMIC(CListCtrlEx, CListCtrl)

/**
 * 构造函数
 */
CListCtrlEx::CListCtrlEx()
{
	m_hoverIndex			=	-1;									// 当前热点项目索引
	m_mouseTrack			=	true;								// 追踪鼠标移动事件
	m_if_hotLine			=	false;								// 默认不开启热点行更换颜色
	m_oddItemBkColor		=	0xFFFFFF;							// 奇数行背景颜色（默认白色）
	m_evenItemBkColor		=	0xFFFFFF;							// 偶数行背景颜色（默认白色）
	m_hoverItemBkColor		=	0xFFFFFF;							// 热点行背景颜色（默认白色）
	m_selectItemBkColor		=	GetSysColor(COLOR_HIGHLIGHT);		// 选中行背景颜色（默认蓝色）
	m_oddItemTextColor		=	GetSysColor(COLOR_BTNTEXT);			// 奇数行文本颜色（默认黑色）
	m_evenItemTextColor		=	GetSysColor(COLOR_BTNTEXT);			// 偶数行文本颜色（默认黑色）
	m_hoverItemTextColor	=	GetSysColor(COLOR_BTNTEXT);			// 热点行文本颜色（默认黑色）
	m_selectItemTextColor	=	GetSysColor(COLOR_BTNTEXT);			// 选中行文本颜色（默认黑色）
}


/**
 * 析构函数
 */
CListCtrlEx::~CListCtrlEx()
{
}


BEGIN_MESSAGE_MAP(CListCtrlEx, CListCtrl)
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, &CListCtrlEx::OnNMCustomdraw)
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_NOTIFY_REFLECT(LVN_COLUMNCLICK, &CListCtrlEx::OnLvnColumnclick)
END_MESSAGE_MAP()


/**
 * 排序回调函数
 */
static int CALLBACK SortFunction(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	CString &lp1 = *((CString *)lParam1);
	CString &lp2 = *((CString *)lParam2);
	int &sort = *(int *)lParamSort;

	if (sort == 0)
		return lp1.CompareNoCase(lp2);
	else
		return lp2.CompareNoCase(lp1);
}


/**
 * 鼠标在控件区域上移动时
 */
void CListCtrlEx::OnMouseMove(UINT nFlags, CPoint point)
{
	if(m_if_hotLine == true) {
		// 获取鼠标当前在哪一行上
		int	newIndex;										// 当前鼠标的一行
		int	oldIndex;										// 记录原来的一行(也就是离开前的那一行)

		newIndex = HitTest(point);
		if(newIndex != m_hoverIndex) {
			CRect rc;
			oldIndex = m_hoverIndex;
			m_hoverIndex = newIndex;

			// 刷新离开后的那一块区域
			if(oldIndex != -1) {
				GetItemRect(oldIndex, &rc, LVIR_BOUNDS);
				InvalidateRect(&rc);
			}
			// 刷新来到新的一块的区域
			if(m_hoverIndex != -1) {
				GetItemRect(m_hoverIndex, &rc, LVIR_BOUNDS);
				InvalidateRect(&rc);
			}
		}

		// 鼠标要追踪WM_MOUSELEAVE事件
		if (m_mouseTrack) {
			TRACKMOUSEEVENT csTME;
			csTME.cbSize = sizeof(csTME);
			csTME.dwFlags = TME_LEAVE;					// 指定要追踪的事件
			csTME.hwndTrack = m_hWnd;					// 指定要追踪的窗口 
			::_TrackMouseEvent(&csTME);					// 开启Windows的WM_MOUSELEAVE事件支持
			m_mouseTrack = false;						// 若已经追踪，则停止追踪 
		}
	}

	CListCtrl::OnMouseMove(nFlags, point);
}


/**
 * 鼠标离开控件区域时
 */
void CListCtrlEx::OnMouseLeave()
{
	if(m_if_hotLine == true) {
		// 开始追踪
		m_mouseTrack = true;
	
		if(m_hoverIndex != -1) {
			CRect rc;
			GetItemRect(m_hoverIndex,&rc,LVIR_BOUNDS);
			InvalidateRect(&rc);
			m_hoverIndex = -1;
			m_mouseTrack = true;
		}
	}

	CListCtrl::OnMouseLeave();
}


/**
 * 擦除背景
 */
BOOL CListCtrlEx::OnEraseBkgnd(CDC* pDC)
{
	return FALSE;
}


/**
 * 绘画
 */
void CListCtrlEx::OnPaint()
{
	CPaintDC dc(this);
	CRect rect;
    CRect headerRect;
    CDC memDC;
    CBitmap bitmap;

	GetClientRect(&rect);
	GetDlgItem(0)->GetWindowRect(&headerRect);
	memDC.CreateCompatibleDC(&dc);
	bitmap.CreateCompatibleBitmap(&dc, rect.Width(), rect.Height());
	memDC.SelectObject(&bitmap);
	memDC.FillSolidRect(&rect, RGB(255, 255, 255));
  
	// 调用默认的OnPaint(),把图形画在内存DC表上
	DefWindowProc(WM_PAINT, (WPARAM)memDC.m_hDC, (LPARAM)0);
	// 输出到显示设备
	dc.BitBlt(0, headerRect.Height(), rect.Width(), rect.Height(), &memDC, 0, headerRect.Height(), SRCCOPY);
	memDC.DeleteDC();
	bitmap.DeleteObject();
}


/**
 * 自绘
 */
void CListCtrlEx::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLVCUSTOMDRAW pNMCD = reinterpret_cast<LPNMLVCUSTOMDRAW>(pNMHDR);
	int	itemIndex = pNMCD->nmcd.dwItemSpec;

	if (pNMCD->nmcd.dwDrawStage == CDDS_PREPAINT) {
		*pResult = CDRF_NOTIFYITEMDRAW;
	}
	else if (pNMCD->nmcd.dwDrawStage == CDDS_ITEMPREPAINT) {
		// 选中行(鼠标选中的行)
		if(GetItemState(itemIndex,LVIS_SELECTED) == LVIS_SELECTED) {
			pNMCD->nmcd.uItemState = ~CDIS_SELECTED;
			pNMCD->clrTextBk = m_selectItemBkColor;
			pNMCD->clrText = pNMCD->clrFace = m_selectItemTextColor;
		}
		// CheckBox打钩行
		else if(GetCheck(itemIndex) && (GetExtendedStyle() & LVS_EX_CHECKBOXES)) {
			pNMCD->clrTextBk = m_selectItemBkColor;
			pNMCD->clrText = m_selectItemTextColor;
		}
		// 热点行(鼠标停在上方)
		else if(itemIndex==m_hoverIndex) {
			m_hoverItemBkColor = RGB(255, 0, 0);
			m_hoverItemTextColor = RGB(0, 0, 0);
			pNMCD->clrTextBk = m_hoverItemBkColor;
			pNMCD->clrText = m_hoverItemTextColor;
		}
		// 偶数行(比如 0、2、4、6)
		else if(itemIndex % 2==0){
			m_evenItemTextColor = RGB(0, 255, 0);
			pNMCD->clrTextBk=m_evenItemBkColor;
			pNMCD->clrText=m_evenItemTextColor;
		}
		// 奇数行(比如 1、3、5、7)
		else{
			m_oddItemTextColor = RGB(0, 0, 255);
			pNMCD->clrTextBk = m_oddItemBkColor;
			pNMCD->clrText = m_oddItemTextColor;
		}
		*pResult = CDRF_NEWFONT;
	}
}


/**
 * 点击表头(这里主要将列表中的数据进行排序)
 */
void CListCtrlEx::OnLvnColumnclick(NMHDR *pNMHDR, LRESULT *pResult)
{
	int count = 0;
	static int sort = 0;
	static int subItem = 0;
	CArray<CString,CString> itemData;
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	// 获取总共有多少行
	count = GetItemCount();
	itemData.SetSize(count);

	// 设置待排序的数据
	for (int i = 0; i < count; i++) {
		itemData[i] = GetItemText(i, pNMLV->iSubItem);
		SetItemData(i, (DWORD_PTR)&itemData[i]);		// 设置待排序的数据
	}

	// 若点击到另一列的表头中
	if (subItem != pNMLV->iSubItem) {
		sort = 0;
		subItem = pNMLV->iSubItem;
	}
	// 若点击在同一列的表头中(升序排列时，则改成降序;降序排列时，则改成升序)
	else {
		sort = (sort == 0 ? 1 : 0);
	}

	SortItems(SortFunction,(DWORD_PTR)&sort);			// 调用回调函数，进行排序
	*pResult = 0;
}


/**
 * 设置奇数行背景颜色
 *
 * @param oddItemBkColor 奇数行背景颜色
 */
void CListCtrlEx::SetOddItemBkColor(COLORREF oddItemBkColor)
{
	m_oddItemBkColor = oddItemBkColor;
}


/**
 * 设置奇数行文字颜色
 *
 * @param oddItemBkColor 奇数行文字颜色
 */
void CListCtrlEx::SetOddItemTextColor(COLORREF oddItemTextColor)
{
	m_oddItemTextColor = oddItemTextColor;
}


/**
 * 设置偶数行背景颜色
 *
 * @param evenItemBkColor 偶数行背景颜色
 */
void CListCtrlEx::SetEvenItemBkColor(COLORREF evenItemBkColor)
{
	m_evenItemBkColor = evenItemBkColor;
}


/**
 * 设置偶数行文字颜色
 *
 * @param evenItemTextColor 偶数文字颜色
 */
void CListCtrlEx::SetEvenItemTextColor(COLORREF evenItemTextColor)
{
	m_evenItemTextColor = evenItemTextColor;
}


/**
 * 设置热点行背景颜色
 *
 * @param hoverItemBkColor 热点行背景颜色
 */
void CListCtrlEx::SetHoverItemBkColor(COLORREF hoverItemBkColor)
{
	m_hoverItemBkColor = hoverItemBkColor;
	m_if_hotLine = true;
}


/**
 * 设置热点行文字颜色
 *
 * @param hoverItemTextColor 热点行文字颜色
 */
void CListCtrlEx::SetHoverItemTextColor(COLORREF hoverItemTextColor)
{
	m_hoverItemTextColor = hoverItemTextColor;
	m_if_hotLine = true;
}


/**
 * 设置选中行背景颜色
 *
 * @param selectItemBkColor 选中行背景颜色
 */
void CListCtrlEx::SetSelectItemBkColor(COLORREF selectItemBkColor)
{
	m_selectItemBkColor = selectItemBkColor;
}


/**
 * 设置选中行文字颜色
 *
 * @param selectItemTextColor 选中行文字颜色
 */
void CListCtrlEx::SetSelectItemTextColor(COLORREF selectItemTextColor)
{
	m_selectItemTextColor = selectItemTextColor;
}