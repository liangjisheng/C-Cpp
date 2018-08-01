#include"iostream"
#include"cstring"
#include"string"
using namespace std;

template<typename T>
inline T const& max(T const& a,T const& b)
{ return a > b ? a : b; }

template<typename T>
inline T const& max(T* const& a,T* const& b)
{ return *a > *b ? *a : *b ; }

inline char const* const& max(char const* const& a,
							  char const* const& b)
{ return strcmp(a,b) > 0 ? a : b; }

int main()
{
	int a=7,b=42;
	cout<<::max(a,b)<<endl;

	string s="hey";
	string t="you";
	cout<<::max(s,t)<<endl;

	int *p1=&b;
	int *p2=&a;
	cout<<::max<int>(p1,p1)<<endl;
	
	char const* s1="David";
	char const* s2="Nico";
	cout<<::max(s1,s2)<<endl;

	system("pause");
	return 0;
}
