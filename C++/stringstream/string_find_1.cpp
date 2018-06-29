
#include <iostream>       // std::cout  
#include <string>         // std::string  

using std::string;
using std::cout;
using std::endl;


int main ()  
{  
	string str ("There are two needles in this haystack with needles.");  
	string str2 ("needle");  
	cout << str << endl;

	// different member versions of find in the same order as above:  
	size_t found = str.find(str2);  
	if (found != string::npos)  
		cout << "first 'needle' found at: " << found << '\n';  

	// ��str�ĵ�found + 1��������ʼ���ҵ�һ��������ǰ6���ַ���str�е�λ��
	found = str.find("needles are small",found + 1, 6);  
	if (found != string::npos)  
		cout << "second 'needle' found at: " << found << '\n';  

	found = str.find("haystack");  
	if (found != string::npos)  
		cout << "'haystack' also found at: " << found << '\n';  

	found = str.find('.');  
	if (found != string::npos)  
		cout << "Period found at: " << found << '\n';  

	// let's replace the first needle:  
	str.replace(str.find(str2), str2.length(), "preposition");  //replace �÷�  
	cout << str << '\n';  

	system("pause");
	return 0;  
}  