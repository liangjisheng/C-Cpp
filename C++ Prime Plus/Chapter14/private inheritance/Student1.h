// student.h -- defining a Student class using private inheritance
#ifndef STUDENT_H_
#define STUDENT_H_

#include"iostream"
#include"valarray"
#include"string"
using namespace std;

class Student : private string,private std::valarray<double>
{
	typedef std::valarray<double> ArrayDb;
	std::ostream & arr_out(std::ostream &) const;
public:
	Student() : string("Null Student"), ArrayDb() {}
	Student(const string & s) : string(s), ArrayDb() {}
	Student(int n) : string("Nully"),ArrayDb(n) {}
	Student(const string & s,int n)
		: string(s),ArrayDb(n) {}
	Student(const string & s,const ArrayDb & a)
		: string(s),ArrayDb(a) {}
	Student(const char * str,const double * pd,int n)
		: string(str),ArrayDb(pd,n) {}
	virtual ~Student() {}

	double Average() const;
	double operator [](int) const;
	//double operator[] (int) const;
	const std::string & Name() const ;
	// friend methods
	friend std::istream & operator >>(std::istream & is,
		Student & stu);		// 1 word
	friend std::istream & gl(std::istream & is,Student & stu);
	friend std::ostream & operator <<(std::ostream & os,
		const Student & stu);
};

#endif