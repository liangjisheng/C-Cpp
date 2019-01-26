// getline.cpp -- use of cin.get , cin.getline , cin.read , cin.gcount
#include"iostream"
using namespace std;
int main() 
{
	cout<<"input some letter(# to exit): ";
	char c[10]={'\0'};
	cin.getline(c,10,'#');
	cout<<c<<endl;
	char ch=cin.get();
	cout<<"ch="<<ch<<endl;
	if(ch=='\n')
		cout<<"ch equals a new line operator"<<endl;
	
	cout<<"input a letter:";
	char ch2=cin.get();
	cout<<"ch2="<<endl;
	cout<<"input some letters:";
	cin.get(c,10);
	cout<<c<<endl;
	cout<<"input some letters:";
	cout<<cin.read(c,4)<<endl;
	cout<<c<<endl;
	cout<<cin.gcount()<<endl;

	return 0;
}