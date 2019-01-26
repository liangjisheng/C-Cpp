// mytime0.h -- Time class 
#ifndef MYTIME_H_
#define MYTIME_H_
#include"iostream"

class Time {
	int hours;
	int minutes;
public:
	Time(int h=0,int m=0);
	void show() const ;
	void AddMin(int n);
	void AddHr(int h);
	void Reset(int h=0,int m=0);
	Time sum(const Time & t) const;
	Time operator+ (const Time & t) const;
	Time operator- (const Time & t) const;
	Time operator* (double n) const;
	friend Time operator* (double n,const Time & t)
	{ return t*n; }
	friend std::ostream & operator<<(std::ostream & os,const Time & t);
};

#endif