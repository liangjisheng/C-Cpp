// chech_cin.cpp -- checking for valid input 
#include"iostream"

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout<<"Enter numbers(a char quit): \n";
	int sum=0;
	int temp;
	while(cin>>temp)
		sum+=temp;
	cout<<"Last value entered is : "<<temp<<endl;
	cout<<"sum="<<sum<<endl;

	system("pause");
	return 0;
}