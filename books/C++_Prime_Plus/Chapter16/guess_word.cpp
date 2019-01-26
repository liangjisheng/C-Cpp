// guess_word.cpp -- some string methods
#include"iostream"
#include"string"
#include"cstdlib"
#include"ctime"
#include"cctype"
using std::string;
const int NUM=26;
const string wordlist[NUM]={"appear","bible","delete",
	"danger","design","forbid","guess","health","insult",
	"jack","keeper","loaner","manage","nonce","script",
	"harden","treaty","remote","stupid","train","useful",
	"valid","carrot","comedy","copper","motion" };

int main() 
{
	using std::cout;
	using std::cin;
	using std::endl;
	srand(time(0));

	char play;
	cout<<"Will you play a word game?<y/n> ";
	cin>>play;
	while(play=='y' || play=='Y') {
		string target=wordlist[rand()%NUM];
		int length=target.length();
		string attempt(length,'*');
		string badchars;
		int guesses=6;	// 有6次输入字符的机会
		cout<<"Guess my secret word. It has "<<length
			<<" letters and you guess\n"
			<<"one letter at a time. You get "<<guesses
			<<" wrong guesses.\n";
		cout<<"Your word: "<<attempt<<endl;
		while(guesses>0 && attempt != target) {
			char letter;
			cout<<"\nGuess a letter: ";
			cin>>letter;
			if(badchars.find(letter) != string::npos
				|| attempt.find(letter) != string::npos) {
				cout<<"You have already guessed that. Try another letter.\n";
					continue;
			}
			int loc=target.find(letter);
			if(loc==string::npos) {
				cout<<"Oh,bad guess!\n";
				--guesses;
				badchars+=letter;	// add to string
			}
			else {
				cout<<"Good guess!\n";
				attempt[loc]=letter;
				// check if letter appears again
				loc=target.find(letter,loc+1);
				while(loc!=string::npos) {
					attempt[loc]=letter;
					loc=target.find(letter,loc+1);
				}
			}
			cout<<"Your word: "<<attempt<<endl;
			if(attempt!=target) {
				if(badchars.length() > 0)
					cout<<"Bad choices: "<<badchars<<endl;
				cout<<guesses<<" bad guesses left\n";
			}
		}
		if(guesses > 0)
			cout<<"That's right!\n";
		else 
			cout<<"Sorry,the word is: "<<target<<endl;

		cout<<"\nWill you play another?<y/n>";
		cin>>play;
	}

	cout<<"Bye.\n";
	return 0;
}
