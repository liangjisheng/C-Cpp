// dma.cpp -- implement of base,lackDMA and hasDMA classes
#include"dma.h"
#include"iostream"
#include"cstring"

// base methods
base::base(const char * l,int r) {
	label=new char[strlen(l)+1];
	strcpy(label,l);
	rating=r;
}

base::base(const base & b) {
	label=new char[strlen(b.label)+1];
	strcpy(label,b.label);
	rating=b.rating;
}

base::~base() { delete [] label; }

base & base::operator =(const base & b) {
	if(this==&b)
		return *this;
	delete []label;
	label=new char[strlen(b.label)+1];
	strcpy(label,b.label);
	rating = b.rating;
	return *this;
}

std::ostream & operator <<(std::ostream & os,const base & b){
	os<<"Label: "<<b.label<<",Rating: "<<b.rating;
	return os;
}

// lackDMA methods
lackDMA::lackDMA(const char * l,int r,const char * c)
: base(l,r) {
	strncpy(color,c,COL_LEN-1);
	color[COL_LEN-1]='\0';
}

lackDMA::lackDMA(const base & b,const char * c) : base(b)
{
	strncpy(color,c,COL_LEN-1);
	color[COL_LEN-1]='\0';
}

std::ostream & operator <<(std::ostream & os,const lackDMA & ls) {
	os<<(const base &)ls;
	os<<"color: "<<ls.color;
	return os;
}

// hasDMA methods
hasDMA::hasDMA(const char * l,int r,const char * s)
: base(l,r) {
	style=new char[strlen(s)+1];
	strcpy(style,s);
}

hasDMA::hasDMA(const base & b,const char * s) : base(b)
{
	style=new char[strlen(s)+1];
	strcpy(style,s);
}

hasDMA::hasDMA(const hasDMA & hs) : base(hs)
{
	style=new char[strlen(hs.style)+1];
	strcpy(style,hs.style);
}

hasDMA::~hasDMA() { delete [] style; }

hasDMA & hasDMA::operator =(const hasDMA & hs)
{
	if(this==&hs)
		return *this;
	delete [] style;
	base::operator =(hs);
	style=new char[strlen(hs.style)+1];
	strcpy(style,hs.style);
	return *this;
}

std::ostream & operator<<(std::ostream & os,const hasDMA & hs)
{
	os<<(const base &)hs;
	os<<"Style: "<<hs.style;
	return os;
}