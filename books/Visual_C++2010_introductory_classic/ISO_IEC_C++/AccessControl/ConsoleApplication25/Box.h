#pragma once
#include <iostream>
using std::cout;
using std::endl;

class CBox
{
public:
	// Base class constructor
	CBox(double length = 1.0, double width = 1.0, double heigth = 1.0)
		: m_Length(length), m_Width(width), m_Height(heigth) 
	{
		cout << "\nCBox constructor called.\n";
	}
	CBox(const CBox& box)
	{
		cout << "\nCBox copy constructor called.\n";
		m_Length = box.m_Length;
		m_Width = box.m_Width;
		m_Height = box.m_Height;
	}
	~CBox()
	{
		cout << "\nCBox destructor called.\n";
	}
protected:
	double m_Length;
	double m_Width;
	double m_Height;
};