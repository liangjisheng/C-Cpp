// ptrstr.cpp -- using pointers to strings

#include"iostream"
#include"cstring"

int main() 
{
	using namespace std;
	char animal[20]="bear";
	char *ps;
	cout<<"animal is :"<<animal<<endl;
	cout<<"strlen(animal) is "<<strlen(animal)<<endl;
	ps=new char[strlen(animal)+1];
	strcpy(ps,animal);
	cout<<ps<<" at "<<(int*)ps<<endl;
	delete []ps;

	return 0;
}