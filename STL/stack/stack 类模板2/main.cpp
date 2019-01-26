#include"iostream"
using namespace std;
#include"deque"
#include"cstdlib"
#include"stack.cpp"

int main(int argc,char *argv[])
{
	cout<<"类模板的实现如下，入栈，出栈，以及抛出异常"<<endl;
	try{
	//现在只传递了一个类型参数给Stack模板，所有使用vector来管理Stack的元素
	Stack<int> intStack;

    //double栈传递了两个参数给Stack模板，所以使用deque来管理Stack的元素
	Stack<double,deque<double> > dblStack;

	intStack.push(7);
	cout<<intStack.top()<<endl;
	intStack.pop();

    dblStack.push(42.42);
	cout<<dblStack.top()<<endl;
	dblStack.pop();
	dblStack.pop();
	}
	catch(exception const& ex){
		cerr<<"Exception:"<<ex.what()<<endl;
		return EXIT_FAILURE;
	}
	return 0;
}