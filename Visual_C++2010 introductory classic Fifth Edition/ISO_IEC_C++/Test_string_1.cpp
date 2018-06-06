// Searching a string
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
using std::strlen;
using std::strstr;

int main()
{
	char* str("Smith,where Jones had had \" had had\" had had \"had\"."
		"\n\"Had had\" had had the examiners' approval.");
	char* word("had");
	cout << "The string to be searched is: "
		<< endl << str << endl;

	int count(0);
	char* pstr(str);
	char* found(nullptr);

	while (true)
	{
		found = strstr(pstr, word);
		if (!found) break;
		++count;
		// Set next search start as 1 past the word found.
		pstr = found + strlen(word);
	}

	cout << "\"" << word << "\" was found "
		<< count << " times in the string." << endl;

	system("pause");
	return 0;
}