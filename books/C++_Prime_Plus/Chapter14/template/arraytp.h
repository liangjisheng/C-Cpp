// arraytp.h -- Array Template
#ifndef ARRAY_H_
#define ARRAY_H_
#include"iostream"
#include"cstdlib"

template<class T,int n>
class ArrayTP
{
private:
	T ar[n];
public:
	ArrayTP() {}
	explicit ArrayTP(const T &);
	virtual T & operator [](int);
};

template<class T,int n>
ArrayTP<T,n>::ArrayTP(const T & v) {
	for(int i=0;i<n;i++)
		ar[i]=v;
}

template<class T,int n>
T & ArrayTP<T,n>::operator [](int i) {
	if(i<0 || i>n) {
		std::cerr<<"Error in array limits: "<<i
			<<" is out of range\n";
		exit(EXIT_FAILURE);
	}
	return ar[i];
}

#endif