// bondini.cpp using escape sequences
// \n ����	\t ˮƽ�Ʊ�		\v ��ֱ�Ʊ�		\b �˸�
// \r �س�	\a ����	
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