// Some string functions
#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	const size_t LENGTH(22);
	const char source[LENGTH]="The more the merrier!";
	char destination[LENGTH];

	errno_t error = strcpy_s(destination,LENGTH,source);

	if(error == EINVAL)
		cout<<"Error. The source or the destination is NULLPTR."<<endl;
	else if (error == ERANGE)
		cout<<"Error. The destination is too small."<<endl;
	else
		cout<<"The destination is: "<<destination<<endl;

	char* str="I agree with everything.";
	char* vowels= "aeiouAEIOU "; // 里面包含一个空格
	// 宽字符版本wcsspn();
	size_t index=strspn(str,vowels);
	cout<<"The first character that is not a vowel is '"
		<<str[index]<<"' at position "<<index<<endl;

	char* SubStr="ever";
	char* psubstr=strstr(str,SubStr);
	if (!psubstr)
		cout<<"\""<<SubStr<<"\" not found in \""<<str<<"\""<<endl;
	else
		cout<<"The first occurrence of \""<<SubStr
		<<"\" in \""<<str<<"\" is at position "
		<<psubstr-str<<endl;

	system("pause");
	return 0;
}