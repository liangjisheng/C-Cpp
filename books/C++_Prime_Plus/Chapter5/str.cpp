#include"iostream"
#include"cstring"
#include"string"
using namespace std;

/*int main()
{
	int x;
	cout<<(x=100)<<endl;
	cout<<x<<endl;

	cout<<(x<3)<<endl;
	cout.setf(ios_base::boolalpha);
	cout<<(x<3)<<endl;
	cout<<(x>3)<<endl;
	return 0;
}*/

/*int main()
{
	cout<<"Enter a word:";
	string word;
	cin>>word;

	// diaplay letters in reverse order
	cout<<"word size is:"<<word.size()<<endl;
	for(int i=word.size()-1;i>=0;i--)
		cout<<word[i];
	cout<<endl;

	return 0;
}*/

/*int main()
{
	string str;
	cout<<"input a string:";
	cin>>str;
	cout<<str<<endl;

	char temp;
	int i,j;
	for(i=0,j=str.size()-1;i<j;i++,j--)
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
	}
	cout<<str<<endl;
	return 0;
}*/

/*int main()
{
	//char word[]="?ate";
	string word="?ate";
	for(char ch='a'; word!="mate"; ch++)
	{
		cout<<word<<endl;
		word[0]=ch;
	}
	cout<<"After loop ends.word is:"<<word<<endl;
	return 0;
}*/

int main()
{
	string str;
	cout<<"Enter your name:";
	cin>>str;
	cout<<"×ÖÄ¸ ¶ÔÓ¦µÄASCIIÂë"<<endl;
	int i=0;
	//for(int i=0;i<str.size();i++)
	//	cout<<str[i]<<"    "<<int(str[i])<<endl;
	while(str[i]!='\0')
		cout<<str[i]<<"    "<<int(str[i])<<endl,i++;

	return 0;
}