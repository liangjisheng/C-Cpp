//: VECTOR.H -- "Infinite" vector
#ifndef VECTOR_H_
#define VECTOR_H_
#include"stdlib.h"
#include"allege.h"

template<class T>
class vector {
	T** pos;
	int pos_sz;
	T** neg;
	int neg_sz;
	int owns;
	enum {
		chunk=20, //Min allocation increase
		esz=sizeof(T*),//Element size
	};
	void expand(T**& array,int& size,int index);
public:
	vector(int Owns=1);
	~vector();
	T*& operator[](int index);
	int Owns() const { return owns; }
	void Owns(int newOwns) { owns=newOwns; }
};

template<class T>
vector<T>::vector(int Owns)
: pos(0),pos_sz(0),neg(0),neg_sz(0),
owns(Owns) {}

template<class T>
vector<T>::~vector() {
	if(owns)
		for(int i=0;i<pos_sz;i++)
			delete pos[i];
	free(pos);
	if(owns)
		for(int j=0;j<neg_sz;j++)
			delete neg[j];
	free(neg);
}

template<class T>
T*& vector<T>::operator [] (int index) {
	if(index<0) {
		index*=-1;
		if(index>=neg_sz)
			expand(neg,neg_sz,index);
		return neg[index];
	}
	else { //Index>=0
		if(index>=pos_sz)
			expand(pos,pos_sz,index);
		return pos[index];
	}
}

template<class T> void
vector<T>::expand(T**& array,int& size,int index) {
	const newsize=index+chunk;
	const increment=newsize-size;
	void* v=realloc(array,newsize*esz);
	allegemem(v);
	array=(T**)v;
	memset(&array[size],0,increment*esz);
	size=index+chunk;
}
#endif //VECTOR_H_