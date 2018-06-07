// student.cpp -- Student class using private inheritance
#include"student.h"
using std::string;

// public methods
double Student::Average() const {
	if(ArrayDb::size()>0)
		return ArrayDb::sum() / ArrayDb::size();
	else 
		return 0;
}

const string & Student::Name() const
{ return (const string & ) *this; }

double Student::operator [](int n) const 
{ return ArrayDb::operator[](n); }

// private method
ostream & Student::arr_out(ostream & os) const {
	int i;
	if(ArrayDb::size()>0) {
		for(i=0;i<ArrayDb::size();i++) {
			os<<ArrayDb::operator[] (i) <<' ';
			if(i%5==4) os<<endl;
		}
		if(i%5==0) os<<endl;
	}
	else os<<"empty array"<<endl;
	return os;
}

// friends
istream & operator >>(istream & is,Student & stu) {
	is>>(string &)stu;
	return is;
}

istream & gl(istream & is,Student & stu) {
	std::getline(is,(string &)stu);
	return is;
}

ostream & operator <<(ostream & os,const Student & stu) {
	os<<"Scores for "<<(string & )stu<<":\n";
	stu.arr_out(os);
	return os;
}