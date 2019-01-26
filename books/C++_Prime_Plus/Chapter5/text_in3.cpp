// text_in3.cpp -- reading chars to end of file
#include"iostream"
using namespace std;

/*int main()
{
	char ch;
	int count=0;
	cout<<"Enter a string:";
	cin.get(ch);
	while(cin.fail()==false) // test for EOF ctrl+z is end of file
	{
		cout<<ch;
		count++;
		cin.get(ch);
	}
	cout<<endl;
	cout<<count<<" characters read\n";

	return 0;
}*/

// 以下代码实现与上面同样的功能
/*int main()
{
	char ch;
	int count=0;
	cout<<"Enter a string:";
	cin.get(ch);
	// test for EOF ctrl+z is end of file
	while(!cin.eof()) // while(!cin.fail()) 效果相同
	{
		cout<<ch;
		count++;
		cin.get(ch);
	}
	cout<<endl;
	cout<<count<<" characters read\n";

	return 0;
}*/

// 以下代码实现与上面同样的功能
/*int main()
{
	char ch;
	int count=0;
	cout<<"Enter a string:";
	cin.get(ch);
	// test for EOF ctrl+z is end of file
	while(cin)
	{
		cout<<ch;
		count++;
		cin.get(ch);
	}
	cout<<endl;
	cout<<count<<" characters read\n";

	return 0;
}*/

// 以下代码实现与上面同样的功能
/*int main()
{
	char ch;
	int count=0;
	cout<<"Enter a string:";
	ch=cin.get();
	// test for EOF ctrl+z is end of file
	while(ch!=EOF)
	{
		cout.put(ch); //cout<<ch; 效果相同
		count++;
		ch=cin.get();
	}
	cout<<endl;
	cout<<count<<" characters read\n";

	return 0;
}*/

// 以下代码实现与上面同样的功能
int main()
{
	char ch;
	int count=0;
	cout<<"Enter a string:";
	// test for EOF ctrl+z is end of file
	while((ch=cin.get())!=EOF)
	{
		cout<<ch;
		count++;
	}
	cout<<endl;
	cout<<count<<" characters read\n";

	return 0;
}