//: SSTRING.H -- Stack-based string
#ifndef SSTRING_H_
#define SSTRING_H_
#include"string.h"
#include"iostream.h"

template<int bsz=0>
class SString {
	char buf[bsz+1];
	char* s;
public:
	SString(const char* S=" ") : s(buf) {
		if(!bsz) { //Make on heap
			s=new char[strlen(S)+1];
			strcpy(s,S);	}
		else { //Make on stack
			buf[bsz]=0; //Ensure 0 termination
			strncpy(s,S,bsz);
		}
	}
	SString(const SString& rv) : s(buf) {
		if(!bsz) { //Make on heap
			s=new char[strlen(rv.s)+1];
			strcpy(s,rv.s);	}
		else { //Make on stack
			buf[bsz]=0;
			strncpy(s,rv.s,bsz);
		}
	}
	SString& operator=(const SString& rv) {
		//Check for self-assignment:
		if(&rv==this) return *this;
		if(!bsz) { //Manage heap:
			delete s;
			s=new char[strlen(rv.s)+1];
		}
		//Constructor guarantees length<bsz:
		strcpy(s,rv.s);
		return *this;
	}
	~SString() { if(!bsz) delete []s; }
	int operator==(const SString& rv) const {
		return !stricmp(s,rv.s);
	}
	int operator!=(const SString& rv) const {
		return stricmp(s,rv.s);
	}
	int operator>(const SString& rv) const {
		return stricmp(s,rv.s)>0;
	}
	int operator<(const SString& rv) const {
		return stricmp(s,rv.s)<0;
	}
	char* str() const { return s; }
	friend ostream& operator<<(ostream& os,const SString<bsz>& S) {
		return os<<S.s;
	}
};
typedef SString<> Hstring; //Heap string
#endif //SSTRING_H_