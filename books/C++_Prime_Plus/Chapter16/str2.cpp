// str2.cpp -- capacity() and reserve()
// string 的自动内存分配
#include"iostream"
#include"string"

int main() 
{
	using namespace std;
	string empty;
	string small="bit";
	string larger="Elephants are a girl's best firend";
	cout<<"Sizes:\n";
	cout<<"\t empty: "<<empty.size()<<endl;
	cout<<"\t samll: "<<small.size()<<endl;
	cout<<"\t larger: "<<larger.size()<<endl;
	cout<<"Capacities:\n";
	cout<<"\t empty: "<<empty.capacity()<<endl;
	cout<<"\t samll: "<<small.capacity()<<endl;
	cout<<"\t larger: "<<larger.capacity()<<endl;
	empty.reserve(50);
	cout<<"Capacity after empty.reserve(50): "
		<<empty.capacity()<<endl;

	return 0;
}