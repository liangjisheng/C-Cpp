
/*
 name: string_toupper.cpp
 func: 利用STL的transform实现大小写转换
*/

/*
template <class InputIterator, class OutputIterator, class UnaryOperator>
OutputIterator transform(InputIterator first1, InputIterator last1,
						OutputIterator result, UnaryOperator op );

template <class InputIterator1, class InputIterator2, 
		class OutputIterator, class BinaryOperator>
OutputIterator transform(InputIterator1 first1, InputIterator1 last1,
						InputIterator2 first2, OutputIterator result,
						BinaryOperator binary_op );
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main()
{
	string str1 = "asdfghjkl@123.com";
	string str2 = "ASDFGHJKL@123.com";
	cout << "before transform: " << endl;
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;

	string::iterator strIter;
	strIter = transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
	transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
	cout << "After transform to upper" << endl;
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;

	return 0;
}
