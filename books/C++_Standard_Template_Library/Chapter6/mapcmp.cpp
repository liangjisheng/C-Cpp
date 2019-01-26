
// 运用map,string，并与执行期指定排序准则，这个例子展示一下技巧
// 如何使用map
// 如何编写和使用仿函数(functor or function object)
// 如何在执行期定义排序准则
// 如何在不在乎大小写的情况下比较字符串

#include <iostream>
#include <map>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

/* function object to compare strings
 * allows you to set the comparison criterion at runtime
 * allows you to compare case insensitive
*/
class RuntimeStringCmp
{
public:
	// constants for the comparison criterion
	enum cmp_mode { normal, nocase };

private:
	// actual comparison mode
	const cmp_mode mode;

	// auxiliary function to compare case insensitive
	static bool nocase_compare(char c1, char c2)
	{
		return toupper(c1) < toupper(c2);
	}
public:
	// constructor: initializes the comparison criterion
	RuntimeStringCmp(cmp_mode m = normal) : mode(m) {}

	// the comparison
	bool operator() (const string& s1, const string& s2) const 
	{
		if (mode == normal)
			return s1 < s2;
		else
			return lexicographical_compare(s1.begin(), s1.end(),
											s2.begin(), s2.end(),
											nocase_compare);
	}
};

/* container type:
 * map with 
 * string keys
 * string values
 * the special comparison object type
*/
typedef map<string, string, RuntimeStringCmp> StringStringMap;

// function that fills and prints such containers
void fillAndPrint(StringStringMap& coll);

int main()
{
	// create a container with the default comparison criterion
	StringStringMap coll1;
	fillAndPrint(coll1);

	// create an object for case-insensitive comparisons
	RuntimeStringCmp ignorecase(RuntimeStringCmp::nocase);

	// create a container with the case-insensitive comparison criterion
	StringStringMap coll2(ignorecase);
	fillAndPrint(coll2);

	system("pause");
	return 0;
}

void fillAndPrint(StringStringMap& coll)
{
	// fill insert elements in random order
	coll["Deutschland"] = "Germany";
	coll["deutsch"] = "German";
	coll["Haken"] = "snag";
	coll["arbeiten"] = "work";
	coll["Hund"] = "dog";
	coll["gehen"] = "go";
	coll["Unternehmen"] = "enterprise";
	coll["unternehmen"] = "undertake";
	coll["gehen"] = "walk";
	coll["Bestatter"] = "undertaker";

	// print elements
	StringStringMap::iterator pos;
	cout.setf(ios::left, ios::adjustfield);
	for (pos = coll.begin(); pos != coll.end(); ++pos)
		cout << setw(15) << pos->first << " " << pos->second << endl;
	cout << endl;
}
