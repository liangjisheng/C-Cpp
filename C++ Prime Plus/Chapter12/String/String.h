// String.h
#ifndef STRING_H_
#define STRING_H_
#include"iostream"

class String {
	char * str;
	int len;
	static int num_strings;
	static const int CINLIM;
public:
	static int HowMany();
	String();
	String(const char * s);
	String(const String & s);
	String & operator =(const String & s);
	String & operator =(const char * s);
	~String();
	friend std::ostream & operator <<(std::ostream & os,
		const String & s);
	friend std::istream & operator >>(std::istream & is,
		String & s);
	int length() const { return len; }
	char & operator [](int index);
	const char & operator [](int index) const;
	String & operator ()(const String & s);
	String & operator ()(const char * s);
	friend bool operator <(const String & s1,const String & s2);
	friend bool operator >(const String & s1,const String & s2);
	friend bool operator ==(const String & s1,const String & s2);
	char * c_str() const { return str; }
};

#endif









