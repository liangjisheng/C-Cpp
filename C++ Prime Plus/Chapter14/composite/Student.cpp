// student.cpp -- Student class using containment
#include"student.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

// public methods
double Student::Average() const {
	if(scores.size()>0)
		return scores.sum() / scores.size();
	else 
		return 0;
}

const string & Student::Name() const 
{ return name; }

double & Student::operator [](int n)
{ return scores[n]; }

//double Student::operator [](int n) const
//{ return scores[n]; }

// private methods
ostream & Student::arr_out(ostream & os) const 
{
	int i;
	if(scores.size()>0) {
		for(i=0;i<scores.size();i++) {
			os<<scores[i]<<' ';
			if(i%5==4)
				os<<endl;
		}
		if(i%5!=0)
			os<<endl;
	}
	else os<<"empty array";
	return os;
}

// friend methods
istream & operator >>(istream & is,Student & stu) {
	is>>stu.name;
	return is;
}

istream & gl(istream & is,Student & stu) {
	//is>>stu.name;
	std::getline(is,stu.name);
	return is;
}

ostream & operator <<(ostream & os,const Student & stu) {
	os<<"Scores for "<<stu.Name()<<":\n";
	stu.arr_out(os);
	return os;
}
