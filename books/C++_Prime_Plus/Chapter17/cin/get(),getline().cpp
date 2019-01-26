// get(),getline().cpp 
// istream & get(char*,int,char); get()���������з�
// istream & get(char*,int);
// istream & getline(char*,int,char); getline()�������з�
// istream & getline(char*,int);
// istream & ignore(int,char);	��ȡ��������int���ַ����򵽴�char�ַ�

#include"iostream"
const int Limit=255;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	char input[Limit];
	cout<<"Enter a string for getline() processing:\n";
	cin.getline(input,Limit,'#');	// getline()����'#'
	cout<<"Here is your input:\n";
	cout<<input<<"\nDone with phase 1\n";

	char ch;
	cin.get(ch);
	cout<<"The next input character is "<<ch<<endl;
	if(ch!='\n')
		cin.ignore(Limit,'\n'); // ���Խ�������255���ַ���������'\n'Ϊֹ

	cout<<"Enter a string for get() processing: \n";
	cin.get(input,Limit,'#'); // get() ������'#'
	cout<<"Here is your input: \n";
	cout<<input<<"\nDone with phase 2\n";
	cin.get(ch);
	cout<<"The next input character is "<<ch<<endl;

	return 0;
}