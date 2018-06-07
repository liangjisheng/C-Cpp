// StringBadbad.h -- flawed sting class definition
#ifndef STRINGBAD_H_
#define STRINGBAD_H_
#include"iostream"

class StringBad {
	char *str;
	int len;
	static int num_StringBads;
public:
	StringBad();
	StringBad(const char * s);
	~StringBad();
	friend std::ostream & operator <<(std::ostream & os,
		const StringBad & s);
};

#endif