// Counting string characters using a pointer
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	const int MAX(80);
	char buffer[MAX];
	char* pbuffer(buffer);

	cout<<endl
		<<"Enter a styring of less than "
		<<MAX<<" characters:"
		<<endl;

	cin.getline(buffer,MAX,'\n');

	while(*pbuffer)
		pbuffer++;
	cout<<endl
		<<"The string \""<<buffer
		<<"\" has "<<pbuffer-buffer<<" characters.";
	cout<<endl;

	system("pause");
	return 0;
}