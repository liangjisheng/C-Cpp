// A simple word collocation
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <iterator>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	std::map<string, int> words; // Map to store words and word count
	cout << "Enter some text and press followed by Ctrl+Z then Enter to end: "
		<< endl << endl;

	// 可以直接访问缓冲流中的数据
	std::istream_iterator<string> begin(cin);	// Stream iterator
	std::istream_iterator<string> end;			// End stream iterator

	while (begin != end)	// Iterator over words in the stream
		words[*begin++]++;	// Increment and store a word count

	// Output the words and their counts
	cout << "\nHere are the word counts for the text you entered: " << endl;
	for (auto iter = words.begin(); iter != words.end(); iter++)
		cout << std::setw(5) << iter->second << " " << iter->first << endl;

	system("pause");
	return 0;
}