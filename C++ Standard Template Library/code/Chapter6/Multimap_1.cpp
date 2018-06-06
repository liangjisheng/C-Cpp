
// 将multimap当做一个字典来使用
#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using std::cout;
using std::endl;
using std::multimap;
using std::string;
using std::make_pair;
using std::ios;
using std::setw;
using std::setfill;

int main()
{
	typedef multimap<string, string> StrStrMap;
	StrStrMap dict;		// create empty dictionary

	// insert some elements in random order
	dict.insert(make_pair("day", "Tag"));
	dict.insert(make_pair("strange", "friend"));
	dict.insert(make_pair("car", "Auto"));
	dict.insert(make_pair("smart", "elegant"));
	dict.insert(make_pair("trait", "Merkmal"));
	dict.insert(make_pair("strange", "seltsam"));
	dict.insert(make_pair("smart", "raffiniert"));
	dict.insert(make_pair("smart", "klug"));
	dict.insert(make_pair("clever", "raffiniert"));

	// print all elements
	StrStrMap::iterator pos;
	cout.setf(ios::left, ios::adjustfield);
	cout << ' ' << setw(10) << "english " << "german " << endl;
	cout << setfill('-') << setw(20) << " " << setfill(' ')  << endl;
	for (pos = dict.begin(); pos != dict.end(); ++pos)
		cout << ' ' << setw(10) << pos->first << pos->second << endl;
	cout << endl;

	// print all values for key "smart"
	string word("smart");
	cout << word << ": " << endl;
	for (pos = dict.lower_bound(word);
			pos != dict.upper_bound(word);
			++pos)
			cout << "	" << pos->second << endl;
	cout << endl;

	// print all keys for value "raffiniert"
	word = "raffiniert";
	cout << word << ": " << endl;
	for (pos = dict.begin(); pos != dict.end(); ++pos)
		if (pos->second == word)
			cout << "	" << pos->first << endl;
	cout << endl;

	system("pause");
	return 0;
}