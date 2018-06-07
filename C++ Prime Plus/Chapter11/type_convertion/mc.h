// stonewt.h -- definition for Stonewt class 
#ifndef STONEWT_H_
#define STONEWT_H_
#include"iostream"

class mc {
private:
	double x;
public:
	mc();
	// 加上explicit 禁止编译器隐式转换 from double to mc 只能显示转换
	//explicit mc(double);	
	mc(double);
	~mc();
	void set(double a) { x = a ;}
	double get() { return x; }
	friend std::ostream & operator <<(std::ostream & os,const mc & a);
//	friend mc operator *(double n,const mc & a) const { return (a * n); }
	// operator function
	operator int() const;
	operator double() const;
	mc operator +(const mc & a) const;
	mc operator +(double n) const;
	mc operator *(const mc & a) const;
	mc operator *(double n) const;
};
#endif