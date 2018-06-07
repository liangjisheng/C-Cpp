// cinexcp.cpp -- having cin throw an execption
#include"iostream"
#include"exception"

int main()
{
	using namespace std;
	// have failbit cause an exception to be throw
	//cin.exceptions(ios_base::failbit);
	cout<<"Enter numbers: ";
	int sum=0;
	int input;

	/*try{
		while(cin>>input)
			sum+=input;
	}
	catch(ios_base::failure & bf) {
		cout<<bf.what();
	}*/

	/*while(cin>>input)
		sum+=input;
	if(cin.eof())1 2
		cout<<"Loop terminate because EOF encountered\n";*/

	while(cin>>input)
		sum+=input;

	cout<<endl;
	cout<<"Last value entered = "<<input<<endl;
	cout<<"Sum = "<<sum<<endl;
	cin.clear();
	//while(cin.get()!=EOF)	// ctrl+z is EOF
	//	continue;
	while(!isspace(cin.get()))
		continue;
	cout<<"input new value:";
	int a;
	cin>>a;
	cout<<"the input is:"<<a<<endl;
	return 0;
}