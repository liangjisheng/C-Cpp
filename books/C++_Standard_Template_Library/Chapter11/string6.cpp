
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	const string hello("Hello, how are you?");
	string s(hello.begin(), hello.end());

	string::iterator pos;
	for (pos = s.begin(); pos != s.end(); ++pos)
		cout << *pos;
	cout << endl;

	// reverse the order of all characters inside the string
	reverse(s.begin(), s.end());
	cout << "reverse: " << s << endl;

	// sort all characters inside the string
	sort(s.begin(), s.end());
	cout << "ordered: " << s << endl;

	// remove adjacent duplicate
	// unique() reorders and returns new end
	// erase() shrinks accordingly
	s.erase(unique(s.begin(), s.end()), s.end());
	cout << "no duplicates: " << s << endl;

	system("pause");
	return 0;
}