#include"String.h"
#include"cstring"
using std::cout;

int String::num_strings=0;
const int String::CINLIM=100;

String::String() {
	len=0;
	str=new char[4];
	strcpy(str,"C++");
	num_strings++;
}

String::String(const char * s) {
	len=strlen(s);
	str=new char[len+1];
	strcpy(str,s);
	num_strings++;
	cout<<num_strings<<":\""<<str<<"\" objects created\n";
}

String::String(const String & s) {
	len=s.len;
	str=new char[len+1];
	strcpy(str,s.str);
	num_strings++;
	cout<<num_strings<<": \""<<str<<"\" object created\n";
}

String & String::operator =(const String & s) {
	if(this == &s)
		return *this;
	delete []str;
	len=s.len;
	str=new char[len+1];
	strcpy(str,s.str);
	return *this;
}

String & String::operator =(const char * s) {
	delete []str;
	len=strlen(s);
	str=new char[len+1];
	strcpy(str,s);
	return *this;
}

String::~String() {
	cout<<"\""<<str<<"\" object deleted, ";
	--num_strings;
	cout<<num_strings<<" left \n";
	delete [] str;
}

std::ostream & operator <<(std::ostream & os,const String & s)
{
	os<<s.str;
	return os;
}

std::istream & operator >>(std::istream & is, String & s) 
{
	char temp[String::CINLIM];
	is.get(temp,String::CINLIM);
	if(is) s=temp;
	while(is && is.get() !='\n')
		continue;
	return is;
}

int String::HowMany() { return num_strings; }

char & String::operator [](int index){
	if(index>=len) 
		return str[len-1];
	return str[index];
}

const char & String::operator [](int index) const {
	if(index>=len) 
		return str[len-1];
	return str[index];
}

String & String::operator ()(const String & s) {
	if(this == &s)
		return *this;
	delete []str;
	len=s.len;
	str=new char[len+1];
	strcpy(str,s.str);
	return *this;
}

String & String::operator ()(const char * s) {
	delete []str;
	len=strlen(s);
	str=new char[len+1];
	strcpy(str,s);
	return *this;
}

bool operator <(const String & s1,const String & s2) {
	return strcmp(s1.str,s2.str)<0;
}

bool operator >(const String & s1,const String & s2) {
	return strcmp(s1.str,s2.str)>0;
}

bool operator ==(const String & s1,const String & s2) {
	return strcmp(s1.str,s2.str)==0;
}
