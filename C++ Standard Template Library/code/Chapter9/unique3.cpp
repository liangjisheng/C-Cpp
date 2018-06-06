
// Ñ¹Ëõ¿Õ°×ÐòÁÐ

#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

bool bothSpaces(char elem1, char elem2)
{
	return elem1 == ' ' && elem2 == ' ';
}


int main()
{
	// don't skip leading whiteSpaces by default
	cin.unsetf(ios::skipws);

	// copy standard input to standard output 
	// while compressing spaces
	unique_copy(istream_iterator<char>(cin),	// beginning of source : cin
				istream_iterator<char>(),		// end of source: end-of-file
				ostream_iterator<char>(cout),	// destination: cout
				bothSpaces);					// duplicate criterion

	system("pause");
	return 0;
}