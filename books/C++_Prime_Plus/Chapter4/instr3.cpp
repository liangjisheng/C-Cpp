// instr3.cpp -- reading more than one word with get() & get()

#include"iostream"
using namespace std;

int main() 
{
	const int size=20;
	char name[size],ch;
	char dessert[size];

	cout<<"Enter your name: \n";
	// cin.getline() 将返回cin对象引用，帮助cin跳过空白符
	cin.getline(name,size).get(ch);
	cout<<"Enter your favorite dessert: \n";
	cin.getline(dessert,size);
	cin.get(ch);
	cout<<"I have some delicious "<<dessert
		<<" for you. "<<name<<".\n";

	getchar();
	return 0;
}