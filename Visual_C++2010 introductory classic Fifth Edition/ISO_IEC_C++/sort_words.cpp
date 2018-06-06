// Extracting words from text
#include <iostream>
#include <iomanip>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::ios;
using std::setiosflags;
using std::resetiosflags;
using std::setw;
using std::string;

// Sort an array of string objects
string* sort(string* strings,size_t count)
{
	bool swapped(false);
	while(true)
	{
		for(size_t i=0;i<count-1;i++)
		{
			if(strings[i]>strings[i+1])
			{
				swapped=true;
				strings[i].swap(strings[i+1]);
			}
		}
		if(!swapped)
			break;
		swapped=false;
	}
	return strings;
}

int main()
{
	const size_t maxwords(100);
	string words[maxwords];
	string text;
	string separators(" \".,:;!?()\n");
	size_t nwords(0);
	size_t maxwidth(0);

	cout<<"Enter some text on as many lines as you wish.\n"
		<<"Terminate the input with an asterisk:"<<endl;

	getline(cin,text,'*');
	// Record start & end of word & offset
	size_t start(0),end(0),offset(0);
	while(true)
	{
		// Find first character of a word
		start = text.find_first_not_of(separators,offset);
		if(string::npos == start)
			break;
		offset = start + 1;	// Move past character found

		// Find first separator past end of current word
		end = text.find_first_of(separators,offset);
		if(string::npos == end)		// If it's the end of the string
		{
			// current word is last in string
			offset = end;	// use offset to end loop later
			end = text.length();
		}
		else
			offset = end + 1;

		// Extract the word
		words[nwords]=text.substr(start,end-start);

		// Keep track of longest word
		if(maxwidth < words[nwords].length())
			maxwidth = words[nwords].length();

		if(string::npos == offset)	// reached the end of the string
			break;

		if(++nwords == maxwords)	// Check for array full
		{
			cout<<"\nMaximum number of words reached.\n"
				<<"Processing what we have.\n";
			break;
		}
	}

	sort(words,nwords);

	cout<<"\nIn ascending sequence,the words in the text are: \n";
	size_t count(0);	// Count of duplicate words
	// Output words and number of occurrences
	for(size_t i=0;i<nwords;i++)
	{
		if(0 == count)
			count = 1;
		if(i < nwords -2 && words[i] == words[i+1])
		{
			++count;
			continue;
		}
		cout<<setiosflags(ios::left)	// Output word left_justified
			<<setw(maxwidth+2)<<words[i];
		cout<<resetiosflags(ios::right) // and word count right-justified
			<<setw(5)<<count<<endl;
		count = 0;
	}
	cout<<endl;

	system("pause");
	return 0;
}