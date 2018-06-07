// str1.cpp -- introducing the string class
#include"iostream"
#include"string"
// using string constructors

int main() 
{
	using namespace std;
	string one("lishuyu");
	cout<<one<<endl;
	string two(20,'$');
	cout<<two<<endl;
	string three(one);
	cout<<three<<endl;
	one+=" Oops";
	cout<<one<<endl;
	two="Sorry! That was ";
	three[0]='P';
	string four;
	four=two+three;
	cout<<four<<endl;
	char alls[]="All's well that ends well";
	string five(alls,20);
	cout<<five<<endl;
	string six(alls+6,alls+10);
	cout<<six<<endl;
	string seven(&five[6],&five[10]);
	cout<<seven<<endl;

	string eight;
	cout<<"\ninput a string :";
	getline(cin,eight); // 输入结束时需要按两次回车
	cout<<eight<<endl;
	while(cin.get()!='\n')
		continue;

	char s[80];
	cout<<"\nInput a string: ";
	cin.getline(s,80); // 输入结束时只需按一次回车
	cout<<s<<endl;
	cout<<string::npos<<endl;
	return 0;
}