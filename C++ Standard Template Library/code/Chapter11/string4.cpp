
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
	string s("The zip code of Hondelage in Germany is 38108");
	cout << "original: " << s << endl;

	// lowercase all characters
	transform(s.begin(), s.end(),
			s.begin(),
			tolower);
	cout << "lowered: " << s << endl;

	// uppercase all characters
	transform(s.begin(), s.end(),
			s.begin(),
			toupper);
	cout << "uppered: " << s << endl;

	system("pause");
	return 0;
}