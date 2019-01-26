// class1.h -- base and derived class
#ifndef CLASS1_H_
#define CLASS1_H_
#include"iostream"

// base class
class base{
private:
	int n;
	double x;
public:
	base();
	base(int);
	base(int,double);
	base(const base &);
	base & operator =(const base &);
	virtual ~base();
	virtual void Show() const;
	int getn() const { return n; }
	double getx() const { return x; }
	void setn(int nn) { n=nn; }
	void setx(int xx) { x=xx; }
	friend std::ostream & operator<<(std::ostream & os,const base &);
};

// derived class
class derived : public base {
private:
	int n1;
	double x1;
public:
	derived();
	derived(int);
	derived(int,double);
	derived(int,int,double);
	derived(int,int,double,double);
	derived(const derived &);
	derived & operator =(const derived &);
	virtual ~derived();
	virtual void Show() const;
	int getn1() const { return n1; }
	double getx1() const { return x1; }
	friend std::ostream & operator<<(std::ostream & os,const derived &);
};

#endif