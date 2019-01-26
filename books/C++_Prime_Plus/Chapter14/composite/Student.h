// student.h -- defining a Student class using containment
#ifndef STUDENT_H_
#define STUDENT_H_

#include"iostream"
#include"string"
#include"valarray"
class Student 
{
private:
	typedef std::valarray<double> ArrayDb;
	std::string name;
	ArrayDb scores;
	std::ostream & arr_out(std::ostream & os) const;
public:
	Student() : name("Null Students"),scores() {}
	Student(const std::string & s) : name(s),scores() {}
	explicit Student(int n) : name("Nully"),scores(n) {}
	Student(const std::string & s,int n) : name(s),scores(n) {}
	Student(const std::string & s,const ArrayDb & a)
		: name(s),scores(a) {}
	Student(const char * s,const double *pd,int n)
		: name(s),scores(pd,n) {}
	virtual ~Student() {}
	
	double Average() const;
	const std::string & Name() const;
	double & operator[] (int);
	//double & operator[] (int) const;
	// friend function
	friend std::istream & operator >>(std::istream & is,
		Student & stu);		// 1 word
	friend std::istream & gl(std::istream & is,
		Student & stu);		// 1 line
	friend std::ostream & operator <<(std::ostream & os,
		const Student & stu);
};

#endif