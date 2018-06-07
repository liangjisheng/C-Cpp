// get(),getline().cpp 
// istream & get(char*,int,char); get()不丢弃换行符
// istream & get(char*,int);
// istream & getline(char*,int,char); getline()丢弃换行符
// istream & getline(char*,int);
// istream & ignore(int,char);	读取接下来的int个字符，或到达char字符

#include"iostream"
const int Limit=255;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	char input[Limit];
	cout<<"Enter a string for getline() processing:\n";
	cin.getline(input,Limit,'#');	// getline()丢弃'#'
	cout<<"Here is your input:\n";
	cout<<input<<"\nDone with phase 1\n";

	char ch;
	cin.get(ch);
	cout<<"The next input character is "<<ch<<endl;
	if(ch!='\n')
		cin.ignore(Limit,'\n'); // 忽略接下来的255个字符，或遇到'\n'为止

	cout<<"Enter a string for get() processing: \n";
	cin.get(input,Limit,'#'); // get() 不丢弃'#'
	cout<<"Here is your input: \n";
	cout<<input<<"\nDone with phase 2\n";
	cin.get(ch);
	cout<<"The next input character is "<<ch<<endl;

	return 0;
}