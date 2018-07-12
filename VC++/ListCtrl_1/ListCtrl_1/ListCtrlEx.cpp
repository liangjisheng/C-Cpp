// ListCtrlEx.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ListCtrlEx.h"


// CListCtrlEx
IMPLEMENT_DYNAMIC(CListCtrlEx, CListCtrl)

/**
 * ���캯��
 */
CListCtrlEx::CListCtrlEx()
{
	m_hoverIndex			=	-1;									// ��ǰ�ȵ���Ŀ����
	m_mouseTrack			=	true;								// ׷������ƶ��¼�
	m_if_hotLine			=	false;								// Ĭ�ϲ������ȵ��и�����ɫ
	m_oddItemBkColor		=	0xFFFFFF;							// �����б�����ɫ��Ĭ�ϰ�ɫ��
	m_evenItemBkColor		=	0xFFFFFF;							// ż���б�����ɫ��Ĭ�ϰ�ɫ��
	m_hoverItemBkColor		=	0xFFFFFF;							// �ȵ��б�����ɫ��Ĭ�ϰ�ɫ��
	m_selectItemBkColor		=	GetSysColor(COLOR_HIGHLIGHT);		// ѡ���б�����ɫ��Ĭ����ɫ��
	m_oddItemTextColor		=	GetSysColor(COLOR_BTNTEXT);			// �������ı���ɫ��Ĭ�Ϻ�ɫ��
	m_evenItemTextColor		=	GetSysColor(COLOR_BTNTEXT);			// ż�����ı���ɫ��Ĭ�Ϻ�ɫ��
	m_hoverItemTextColor	=	GetSysColor(COLOR_BTNTEXT);			// �ȵ����ı���ɫ��Ĭ�Ϻ�ɫ��
	m_selectItemTextColor	=	GetSysColor(COLOR_BTNTEXT);			// ѡ�����ı���ɫ��Ĭ�Ϻ�ɫ��
}


/**
 * ��������
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
 * ����ص�����
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
 * ����ڿؼ��������ƶ�ʱ
 */
void CListCtrlEx::OnMouseMove(UINT nFlags, CPoint point)
{
	if(m_if_hotLine == true) {
		// ��ȡ��굱ǰ����һ����
		int	newIndex;										// ��ǰ����һ��
		int	oldIndex;										// ��¼ԭ����һ��(Ҳ�����뿪ǰ����һ��)

		newIndex = HitTest(point);
		if(newIndex != m_hoverIndex) {
			CRect rc;
			oldIndex = m_hoverIndex;
			m_hoverIndex = newIndex;

			// ˢ���뿪�����һ������
			if(oldIndex != -1) {
				GetItemRect(oldIndex, &rc, LVIR_BOUNDS);
				InvalidateRect(&rc);
			}
			// ˢ�������µ�һ�������
			if(m_hoverIndex != -1) {
				GetItemRect(m_hoverIndex, &rc, LVIR_BOUNDS);
				InvalidateRect(&rc);
			}
		}

		// ���Ҫ׷��WM_MOUSELEAVE�¼�
		if (m_mouseTrack) {
			TRACKMOUSEEVENT csTME;
			csTME.cbSize = sizeof(csTME);
			csTME.dwFlags = TME_LEAVE;					// ָ��Ҫ׷�ٵ��¼�
			csTME.hwndTrack = m_hWnd;					// ָ��Ҫ׷�ٵĴ��� 
			::_TrackMouseEvent(&csTME);					// ����Windows��WM_MOUSELEAVE�¼�֧��
			m_mouseTrack = false;						// ���Ѿ�׷�٣���ֹͣ׷�� 
		}
	}

	CListCtrl::OnMouseMove(nFlags, point);
}


/**
 * ����뿪�ؼ�����ʱ
 */
void CListCtrlEx::OnMouseLeave()
{
	if(m_if_hotLine == true) {
		// ��ʼ׷��
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
 * ��������
 */
BOOL CListCtrlEx::OnEraseBkgnd(CDC* pDC)
{
	return FALSE;
}


/**
 * �滭
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
  
	// ����Ĭ�ϵ�OnPaint(),��ͼ�λ����ڴ�DC����
	DefWindowProc(WM_PAINT, (WPARAM)memDC.m_hDC, (LPARAM)0);
	// �������ʾ�豸
	dc.BitBlt(0, headerRect.Height(), rect.Width(), rect.Height(), &memDC, 0, headerRect.Height(), SRCCOPY);
	memDC.DeleteDC();
	bitmap.DeleteObject();
}


/**
 * �Ի�
 */
void CListCtrlEx::OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLVCUSTOMDRAW pNMCD = reinterpret_cast<LPNMLVCUSTOMDRAW>(pNMHDR);
	int	itemIndex = pNMCD->nmcd.dwItemSpec;

	if (pNMCD->nmcd.dwDrawStage == CDDS_PREPAINT) {
		*pResult = CDRF_NOTIFYITEMDRAW;
	}
	else if (pNMCD->nmcd.dwDrawStage == CDDS_ITEMPREPAINT) {
		// ѡ����(���ѡ�е���)
		if(GetItemState(itemIndex,LVIS_SELECTED) == LVIS_SELECTED) {
			pNMCD->nmcd.uItemState = ~CDIS_SELECTED;
			pNMCD->clrTextBk = m_selectItemBkColor;
			pNMCD->clrText = pNMCD->clrFace = m_selectItemTextColor;
		}
		// CheckBox����
		else if(GetCheck(itemIndex) && (GetExtendedStyle() & LVS_EX_CHECKBOXES)) {
			pNMCD->clrTextBk = m_selectItemBkColor;
			pNMCD->clrText = m_selectItemTextColor;
		}
		// �ȵ���(���ͣ���Ϸ�)
		else if(itemIndex==m_hoverIndex) {
			m_hoverItemBkColor = RGB(255, 0, 0);
			m_hoverItemTextColor = RGB(0, 0, 0);
			pNMCD->clrTextBk = m_hoverItemBkColor;
			pNMCD->clrText = m_hoverItemTextColor;
		}
		// ż����(���� 0��2��4��6)
		else if(itemIndex % 2==0){
			m_evenItemTextColor = RGB(0, 255, 0);
			pNMCD->clrTextBk=m_evenItemBkColor;
			pNMCD->clrText=m_evenItemTextColor;
		}
		// ������(���� 1��3��5��7)
		else{
			m_oddItemTextColor = RGB(0, 0, 255);
			pNMCD->clrTextBk = m_oddItemBkColor;
			pNMCD->clrText = m_oddItemTextColor;
		}
		*pResult = CDRF_NEWFONT;
	}
}


/**
 * �����ͷ(������Ҫ���б��е����ݽ�������)
 */
void CListCtrlEx::OnLvnColumnclick(NMHDR *pNMHDR, LRESULT *pResult)
{
	int count = 0;
	static int sort = 0;
	static int subItem = 0;
	CArray<CString,CString> itemData;
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	// ��ȡ�ܹ��ж�����
	count = GetItemCount();
	itemData.SetSize(count);

	// ���ô����������
	for (int i = 0; i < count; i++) {
		itemData[i] = GetItemText(i, pNMLV->iSubItem);
		SetItemData(i, (DWORD_PTR)&itemData[i]);		// ���ô����������
	}

	// ���������һ�еı�ͷ��
	if (subItem != pNMLV->iSubItem) {
		sort = 0;
		subItem = pNMLV->iSubItem;
	}
	// �������ͬһ�еı�ͷ��(��������ʱ����ĳɽ���;��������ʱ����ĳ�����)
	else {
		sort = (sort == 0 ? 1 : 0);
	}

	SortItems(SortFunction,(DWORD_PTR)&sort);			// ���ûص���������������
	*pResult = 0;
}


/**
 * ���������б�����ɫ
 *
 * @param oddItemBkColor �����б�����ɫ
 */
void CListCtrlEx::SetOddItemBkColor(COLORREF oddItemBkColor)
{
	m_oddItemBkColor = oddItemBkColor;
}


/**
 * ����������������ɫ
 *
 * @param oddItemBkColor ������������ɫ
 */
void CListCtrlEx::SetOddItemTextColor(COLORREF oddItemTextColor)
{
	m_oddItemTextColor = oddItemTextColor;
}


/**
 * ����ż���б�����ɫ
 *
 * @param evenItemBkColor ż���б�����ɫ
 */
void CListCtrlEx::SetEvenItemBkColor(COLORREF evenItemBkColor)
{
	m_evenItemBkColor = evenItemBkColor;
}


/**
 * ����ż����������ɫ
 *
 * @param evenItemTextColor ż��������ɫ
 */
void CListCtrlEx::SetEvenItemTextColor(COLORREF evenItemTextColor)
{
	m_evenItemTextColor = evenItemTextColor;
}


/**
 * �����ȵ��б�����ɫ
 *
 * @param hoverItemBkColor �ȵ��б�����ɫ
 */
void CListCtrlEx::SetHoverItemBkColor(COLORREF hoverItemBkColor)
{
	m_hoverItemBkColor = hoverItemBkColor;
	m_if_hotLine = true;
}


/**
 * �����ȵ���������ɫ
 *
 * @param hoverItemTextColor �ȵ���������ɫ
 */
void CListCtrlEx::SetHoverItemTextColor(COLORREF hoverItemTextColor)
{
	m_hoverItemTextColor = hoverItemTextColor;
	m_if_hotLine = true;
}


/**
 * ����ѡ���б�����ɫ
 *
 * @param selectItemBkColor ѡ���б�����ɫ
 */
void CListCtrlEx::SetSelectItemBkColor(COLORREF selectItemBkColor)
{
	m_selectItemBkColor = selectItemBkColor;
}


/**
 * ����ѡ����������ɫ
 *
 * @param selectItemTextColor ѡ����������ɫ
 */
void CListCtrlEx::SetSelectItemTextColor(COLORREF selectItemTextColor)
{
	m_selectItemTextColor = selectItemTextColor;
}