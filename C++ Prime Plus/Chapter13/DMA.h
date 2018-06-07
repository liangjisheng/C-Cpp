// dma.h -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include"iostream"

// Base Class Using DMA
class base{
private:
	char * label;
	int rating;
public:
	base(const char * l="null",int r=0);
	base(const base &);
	~base();
	base & operator=(const base &);
	friend std::ostream & operator <<(std::ostream & os,
		const base &);
};

// derived without using DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lackDMA : public base {
private:
	enum { COL_LEN=40 };
	char color[COL_LEN];
public:
	lackDMA(const char * l="null",int r=0,const char * c="blank");
	lackDMA(const base &,const char *);
	friend std::ostream & operator <<(std::ostream & os,
		const lackDMA &);
};

// derived class with DMA
class hasDMA : public base {
private:
	char * style;
public:
	hasDMA(const char * l="null",int r=0,const char * s="none");
	hasDMA(const base &,const char *);
	hasDMA(const hasDMA &);
	~hasDMA();
	hasDMA & operator =(const hasDMA &);
	friend std::ostream & operator <<(std::ostream & os,
		const hasDMA &);
};

#endif