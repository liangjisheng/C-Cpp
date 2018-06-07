// mc.cpp implecment of class mc
#include"stonewt.h"

mc::mc() { x = 0.0; }

mc::mc(double a) { x = a ;}

mc::~mc() {}

std::ostream & operator <<(std::ostream & os,const mc & a) {
	os<<a.x;
	return os;
}

mc::operator double() const {
	return x;
}

mc::operator int() const {
	return (int)x;
}

mc mc::operator +(const mc & a) const {
	mc temp;
	temp.x = x + a.x;
	return temp;
}

mc mc::operator +(double n) const {
	mc temp;
	temp.x = x + n;
	return temp;
}

mc mc::operator *(const mc & a) const {
	mc temp;
	temp.x = x * a.x;
	return temp;
}

mc mc::operator *(double n) const {
	mc temp;
	temp.x = x * n;
	return temp;
}
