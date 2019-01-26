// checking for valid input 
#include"iostream"
#include"exception"

int main()
{
	using namespace std;
	cout<<"Enter numbers(a char quit): \n";
	int sum=0;
	int temp;
	while(cin>>temp)
		sum+=temp;
	cout<<"Last value entered is : "<<temp<<endl;
	cout<<"sum="<<sum<<endl;
	if(cin.fail() && !cin.eof()) {	// failed because of mismatched input
		cin.clear();
		while(!isspace(cin.get()))
			continue;
	}
	else {
		cout<<"I cannot go on!\n";
		exit(1);
	}
	cout<<"Now enter a new value:";
	cin>>temp;
	cout<<"value="<<temp<<endl;

	system("pause");
	return 0;
}