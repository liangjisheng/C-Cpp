// bondini.cpp using escape sequences
// \n 换行	\t 水平制表		\v 垂直制表		\b 退格
// \r 回车	\a 振铃	
#include"iostream"
using namespace std;

int main() {
	cout<<"\aOperation \"HyperHype\" is now actived!\n";
	cout<<"Enter your agent code:______\b\b\b\b\b\b";
	long code;
	cin>>code;
	cout<<"\aYou entered "<<code<<"...\n";
	cout<<"\aCode veridied! Proceed with Plan Z3!\n";

	return 0;
}