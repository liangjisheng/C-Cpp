// A push-down stack to store Box objects
#pragma once
#include"Box.h"

class CStack
{
private:
	// Defines items to store in the stack
	struct CItem
	{
		CBox* pBox;
		CItem* pNext;
		CItem(CBox* pB, CItem* pN) : pBox(pB), pNext(pN) {}
	};

	CItem* pTop;	// Pointer to item that is at the top
public:
	CStack() : pTop(nullptr) {}
	void Push(CBox* pBox)
	{
		pTop = new CItem(pBox, pTop);
	}
	CBox* Pop()
	{
		if (!pTop)
			return nullptr;

		CBox* pBox = pTop->pBox;	// Get box from item
		CItem* pTemp = pTop;		
		pTop = pTop->pNext;
		delete pTemp;
		return pBox;
	}
	~CStack()
	{
		CItem* pTemp(nullptr);
		while (pTop)
		{
			pTemp = pTop;
			pTop = pTop->pNext;
			delete pTemp;
		}
	}
};