// use_algo.cpp -- using several STL elements
#include"iostream"
#include"string"
#include"vector"
#include"set"
#include"map"
#include"iterator"
#include"algorithm"
#include"cctype"
using namespace std;

char toLower(char ch) { return tolower(ch); }
string & ToLower(string &);
void display(const string &);

int main()
{
	vector<string> words;
	cout<<"Enter words(enter quit to quit):\n";
	string input;
	while(cin>>input && input!="quit")
		words.push_back(input);

	cout<<"You entered the following words:\n";
	for_each(words.begin(),words.end(),display);
	cout<<endl;
	// place word in set,converting to lowercase
	set<string> wordset;
	transform(words.begin(),words.end(),
		insert_iterator<set<string> >(wordset,wordset.begin()),ToLower);
	cout<<"\nAlphabetic list of words:\n";
	for_each(wordset.begin(),wordset.end(),display);
	cout<<endl;

	// place word and frequency in map
	map<string,int> wordmap;
	set<string>::iterator si;
	for(si=wordset.begin();si!=wordset.end();si++)
		wordmap[*si]=count(words.begin(),words.end(),*si);

	// display map counts;
	cout<<"\nWord frequency:\n";
	for(si=wordset.begin();si!=wordset.end(),si++)
		cout<<*si<<": "<<wordmap[*si]<<endl;

	return 0;
}

void display(const string & s)
{ cout<<s<<' '; }

string & ToLower(string & s) 
{
	transform(s.begin(),s.end(),s.begin(),toLower);
	return s;
}