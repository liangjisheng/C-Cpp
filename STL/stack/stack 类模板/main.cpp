#include"iostream"
using namespace std;
#include"string"
#include"cstdlib"
#include"stack.cpp"

int main(int argc,char *argv[])
{
	try{
		Stack<int> intStack;
		Stack<string> stringStack;

		intStack.push(7);
		cout<<intStack.top()<<endl;

		stringStack.push("hello");
		cout<<stringStack.top()<<endl;
		stringStack.pop();
		stringStack.pop();
	}
	catch(exception const& ex){
		cout<<"Exception:"<<ex.what()<<endl;
		return EXIT_FAILURE;
	}
	return 0;
}