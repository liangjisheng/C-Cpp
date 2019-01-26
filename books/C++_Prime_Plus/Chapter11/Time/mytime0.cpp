// mytime0.cpp -- implement Time methods
#include"mytime0.h"
#include"iostream"

//Time::Time() { hours=minutes=0; }

Time::Time(int h,int m) { hours=h;minutes=m; }

void Time::show() const {
	std::cout<<"hours: "<<hours<<", minutes: "<<minutes<<std::endl;
}

void Time::AddHr(int h) { hours+=h; }

void Time::AddMin(int m) {
	minutes+=m;
	hours+= minutes/60;
	minutes%=60;
}

void Time::Reset(int h,int m) { hours=h,minutes=m; }

Time Time::sum(const Time & t) const {
	Time s;
	s.minutes=minutes+t.minutes;
	s.hours=hours+t.hours+s.minutes/60;
	s.minutes %= 60;
	return s;
}

Time Time::operator +(const Time & t) const {
	Time s;
	s.minutes=minutes+t.minutes;
	s.hours=hours+t.hours+s.minutes/60;
	s.minutes %= 60;
	return s;
}

Time Time::operator -(const Time & t) const {
	Time diff;
	int t1=hours * 60 + minutes;
	int t2=t.hours*60 + t.minutes;
	diff.hours=(t1-t2) / 60;
	diff.minutes=(t1-t2) % 60;
	return diff;
}

Time Time::operator *(double n) const {
	Time result;
	long m=hours * 60 * n + minutes * n;
	result.minutes = m % 60 ;
	result.hours = m / 60 ;
	return result;
}

std::ostream & operator<<(std::ostream & os,const Time & t) {
	os<<"hours: "<<t.hours<<", minutes: "<<t.minutes<<std::endl;
	return os;
}