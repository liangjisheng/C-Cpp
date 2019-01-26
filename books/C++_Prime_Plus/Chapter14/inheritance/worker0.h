// worker0.h -- working classes
#ifndef WORKER0_H_
#define WORKER0_H_
#include"string"
using std::string;

class Worker {
private:
	string fullname;
	long id;
public:
	Worker() : fullname("no one"),id(0L) {}
	Worker(const string & s,long n) : fullname(s),id(n) {}
	virtual ~Worker()=0;	// pure virtual destructor
	virtual void Set();
	virtual void Show() const;
};

class Waiter : public Worker
{
private:
	int panache;
public:
	Waiter() : Worker(),panache(0) {}
	Waiter(const string & s,long n,int p)
		: Worker(s,n),panache(p) {}
	Waiter(const Worker & w,int p)
		: Worker(w),panache(p) {}
	void Set();
	void Show() const;
};

class Singer : public Worker
{
protected:
	enum {other,alto,contralto,soprano,bass,baritone,tenor};
	enum { Vtypes=7 };
private:
	static char *pv[Vtypes];
	int voice;
public:
	Singer() : Worker(),voice(other) {}
	Singer(const string & s,long n,int v=other)
		: Worker(s,n),voice(v) {}
	Singer(const Worker & w,int v=other)
		: Worker(w),voice(v) {}
	void Set();
	void Show() const;
};

#endif