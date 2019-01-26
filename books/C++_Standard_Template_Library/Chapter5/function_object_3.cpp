
// C++��׼����������һЩԤ����ķº���

#include <iostream>
#include <vector>
#include <algorithm>
#include "..\..\print.hpp"

using namespace std;

// Ԥ����º���negate,��Ԫ��ȡ��
void test_negate()
{
	vector<int> coll;

	for (int i = -5; i <= 5; ++i)
		coll.push_back(i);

	PRINT_ELEMENTS(coll, "Before: ");

	transform(coll.begin(), coll.end(),		// source
				coll.begin(),				// destination
				negate<int>());				// operation

	PRINT_ELEMENTS(coll, "After: ");
}

// Ԥ����º���multiplies,��Ԫ�����
// process the square of all elements
void test_multiplies()
{
	vector<int> coll;

	for (int i = 1; i <= 9; ++i)
		coll.push_back(i);

	PRINT_ELEMENTS(coll, "Before: ");

	transform(coll.begin(), coll.end(),		// first source
				coll.begin(),				// second source
				coll.begin(),				// destination
				multiplies<int>());			// operation

	PRINT_ELEMENTS(coll, "After: ");
}


int main()
{
	// test_negate();
	test_multiplies();

	system("pause");
	return 0;
}