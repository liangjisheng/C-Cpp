
// 通过排序准则将字符串按照字符数量排序

#include "..\..\algostuff.hpp"
using namespace std;

bool lessLength(const string& s1, const string& s2)
{
	return s1.length() < s2.length();
}


int main()
{
	vector<string> coll1;
	vector<string> coll2;

	// fill both collections with the same elements
	coll1.push_back("1xxx");
	coll1.push_back("2x");
	coll1.push_back("3x");
	coll1.push_back("4x");
	coll1.push_back("5xx");
	coll1.push_back("6xxxx");
	coll1.push_back("7xx");
	coll1.push_back("8xxx");
	coll1.push_back("9xx");
	coll1.push_back("10xxx");
	coll1.push_back("11");
	coll1.push_back("12");
	coll1.push_back("13");
	coll1.push_back("14xx");
	coll1.push_back("15");
	coll1.push_back("16");
	coll1.push_back("17");
	coll2 = coll1;

	PRINT_ELEMENTS(coll1, "on entry: \n");

	// sort (according to the length of the strings)
	sort(coll1.begin(), coll1.end(), lessLength);

	stable_sort(coll2.begin(), coll2.end(), lessLength);

	PRINT_ELEMENTS(coll1, "\nwith sort(): \n");
	PRINT_ELEMENTS(coll2, "'nwith stable_sort(): \n");

	system("pause");
	return 0;
}