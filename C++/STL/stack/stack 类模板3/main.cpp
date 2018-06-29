#include"iostream"
using namespace std;
#include"string"
#include"cstdlib"
#include"stack.cpp"

int main(int argc,char *argv[])
{
	try{
		Stack<int,20> int20Stack;//20个元素的int栈
		Stack<int,40> int40Stack;//40个元素的int栈
		Stack<string,40> stringStack;//40个元素的string栈

		int20Stack.push(7);
		cout<<int20Stack.top()<<endl;
		int20Stack.pop();

		stringStack.push("hello");
		cout<<stringStack.top()<<endl;
		stringStack.pop();
		stringStack.pop();
	}
	catch(exception const& ex){
		cerr<<"Exception:"<<ex.what()<<endl;
		return EXIT_FAILURE;
	}
	return 0;
}