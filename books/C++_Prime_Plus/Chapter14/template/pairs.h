// pairs.h -- defining a Pairs template
#ifndef PAIRS_H_
#define PAIRS_H_

template<class T1,class T2>
class Pairs {
private:
	T1 a;
	T2 b;
public:
	T1 & first();
	T2 & second();
	T1 first() const { return a; }
	T2 second() const { return b; }
	Pairs(const T1 & aval,const T2 & bval) : a(aval),b(bval) {}
	Pairs() {}
};

template<class T1,class T2>
T1 & Pairs<T1,T2>::first() { return a; }

template<class T1,class T2>
T2 & Pairs<T1,T2>::second() { return b; }

#endif