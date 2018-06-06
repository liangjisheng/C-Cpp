#pragma once
#include"Box.h"
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

class CCandyBox : public CBox
{
public:
	char* m_Contents;
	double Volume() const
	{
		return m_Length*m_Height*m_Width;
	}
	CCandyBox(double length, double width, double height, char* str = "Candy")
		:CBox(length, width, height)
	{
		cout << "\nCCandyBox explicit constructor called.\n";
		m_Contents = new char[strlen(str) + 1];
		strcpy_s(m_Contents, strlen(str) + 1, str);
	}
	CCandyBox(char* str = "Candy")
	{
		cout << "\nCCandBox default constructor called.\n";
		m_Contents = new char[strlen(str) + 1];
		strcpy_s(m_Contents, strlen(str) + 1, str);
	}
	CCandyBox(const CCandyBox& CandyBox) : CBox(CandyBox)
	{
		// 先调用基类的复制构造函数
		cout << "\nCCandyBox copy constructor called.\n";
		m_Contents = new char[strlen(CandyBox.m_Contents) + 1];
		strcpy_s(m_Contents, strlen(CandyBox.m_Contents) + 1, CandyBox.m_Contents);
	}
	CCandyBox(CCandyBox&& CandyBox) : CBox(CandyBox)
	{
		cout << "\nCCandyBox move constructor called.\n";
		m_Contents = CandyBox.m_Contents;
		CandyBox.m_Contents = nullptr;
	}
	~CCandyBox()
	{
		cout << "\nCCandyBox destructor called.\n";
		delete[]m_Contents;
	}
};