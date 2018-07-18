#include"iostream"
#include"sstream"
#include"string"
using namespace std;

int main() {
	string source("These are the vayages...");
	char dest[81]="";
	stringbuf buffer(source);
	istream InputStream(&buffer);
	if(InputStream==NULL)
		cerr<<"Error Setting up stream"<<endl;
	InputStream.get(dest,81,'e');
	cout<<dest<<endl;
	InputStream.seekg(0,ios_base::beg);
	InputStream.get(dest,InputStream.rdbuf()->in_avail(),'\n');
	cout<<dest<<endl;
	InputStream.seekg(0,ios_base::beg);
	InputStream.get(dest,5,'\n');
	cout<<dest<<endl;
	return 0;
}