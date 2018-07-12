#include"iostream"
using namespace std;

int main() {
	try{
		throw "a execption";
		cout<<"normal execute 1"<<endl;
	}
	catch(const char* s) {
		cout<<s<<endl;
		cout<<"execption type:const char*"<<endl;
	}
	catch(int i) {
		cout<<i<<endl;
		cout<<"execption type:int"<<endl;
	}
	return 0;
}