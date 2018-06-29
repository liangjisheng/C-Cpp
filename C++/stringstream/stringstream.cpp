#include"iostream"
#include"sstream"	// for istringstream
#include"string"
// istringstream类是从istream和stringstreambase派生而来，
// ostringstream是从ostream和 stringstreambase派生而来， 
// stringstream则是从iostream类和stringstreambase派生而来。

int main() {
	using std::cout;
	using std::endl;
	using std::istringstream;
	using std::ostringstream;
	using std::stringstream;
	using std::string;

	istringstream istr("1 56.7");
	// istr.str("1 56.7"); // 与上一行等效
	cout<<istr.str()<<endl;
	int a;
	float b;
	istr>>a;
	cout<<a<<endl;
	istr>>b;
	cout<<b<<endl;

	ostringstream ostr;
	ostr.put('d');
	ostr.put('e');
	ostr<<"fg";
	string s=ostr.str();
	cout<<s<<endl;

	stringstream str("ccc");
	cout<<str.str()<<endl;
	str.put('d');
	str.put('e');
	str<<"fg";
	string s1=str.str();
	cout<<s1<<endl;

	char ch;
	str>>ch;
	cout<<ch<<endl;

	system("pause");
	return 0;
}