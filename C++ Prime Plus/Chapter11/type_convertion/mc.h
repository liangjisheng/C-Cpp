// stonewt.h -- definition for Stonewt class 
#ifndef STONEWT_H_
#define STONEWT_H_
#include"iostream"

class mc {
private:
	double x;
public:
	mc();
	// ����explicit ��ֹ��������ʽת�� from double to mc ֻ����ʾת��
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