// vect.cpp -- method for Vector class 
#include"cmath"
#include"vector.h"		// inlcudes "iostream"
//using std::sin;
//using std::cos;
//using std::atan2;
using std::cout;

namespace VECTOR 
{
	const double Rad_to_deg =57.2957795130823;
	// private methods
	void Vector::set_mag() { mag - sqrt(x * x + y * y) ; }

	void Vector::set_ang() {
		if(x == 0.0 && y == 0.0) ang=0.0;
		else ang = atan2(y,x);
	}

	//set x from polar coordinate
	void Vector::set_x() { x = mag * sin(ang) ;}
	void Vector::set_y() { y = mag * sin(ang) ;}

	// public methods
	Vector::Vector() {
		x=y=mag=ang=0.0;
		mode='r';
	}

	Vector::Vector(double n1,double n2,char form) {
		mode=form;
		if(form=='r') {
			x=n1,y=n2;
			set_mag();set_ang();
		}
		else if (form = 'p') {
			mag=n1,ang=n2 / Rad_to_deg;
			set_x();set_y();
		}
		else {
			cout<<"Incorrect 3rd argument to Vector()--\n"
				"vector set to 0\n";
			x=y=mag=ang=0.0;
			mode='r';
		}
	}

	void Vector::set(double n1,double n2,char form) {
		mode=form;
		if(form=='r') {
			x=n1,y=n2;
			set_mag();set_ang();
		}
		else if (form = 'p') {
			mag=n1,ang=n2 / Rad_to_deg;
			set_x();set_y();
		}
		else {
			cout<<"Incorrect 3rd argument to Vector()--\n"
				"vector set to 0\n";
			x=y=mag=ang=0.0;
			mode='r';
		}
	}

	Vector::~Vector() {}

	void Vector::polar_mode() { mode = 'p'; }
	void Vector::rect_mode() { mode = 'r'; }

	Vector Vector::operator +(const Vector & b) const 
	{ return Vector(x + b.x, y + b.y); }

	Vector Vector::operator -(const Vector & b) const
	{ return Vector(x - b.x, y - b.y); }

	Vector Vector::operator -() const
	{ return Vector(-x,-y); }

	Vector Vector::operator *(double n) const
	{ return Vector(n * x, n * y); }

	// friend methods
	Vector operator *(double n,const Vector & a) 
	{ return a * n; }

	std::ostream & operator <<(std::ostream & os,const Vector & a) {
		if(a.mode == 'r')
			os<<"(x,y) = ("<<a.x<<","<<a.y<<")";
		else if(a.mode == 'p')
			os<<"(m,a)=("<<a.mag<<","<<a.ang * Rad_to_deg<<")";
		else
			os<<"Vector object mode is invalid";

		return os;
	}
}