#include"iostream"
#include"string"
#include"cassert"
#include"stack.h"
using namespace std;
string RPN(string exp);
int main(int argc,char *argv[])
{
	Stack s;
	cout<<boolalpha<<"s empty? "<<s.empty()<<endl;
	for(int i=1;i<=16;i++)s.push(i);
	cout<<"Stack should now be full."<<endl;
	s.push(17);
	s.display(cout);
	cout<<boolalpha<<"s empty? "<<s.empty()<<endl;
	cout<<"Top value: "<<s.top()<<endl;
	while(!s.empty()){
		cout<<"Poppint "<<s.top()<<endl;
		s.pop();
	}
	cout<<boolalpha<<"s empty? "<<s.empty()<<endl;

	string exp;
	cout<<"NOTE: Enter # for infix expression to stop."<<endl;
	for(;;){
		cout<<"\nIndix Expression?";
		//fflush(stdin);
		//getline(cin,exp);
		cin>>exp;
		if(exp=="#")break;
		cout<<"RPNexp Expression is:"<<RPN(exp)<<endl;
	}
	return 0;
}

string RPN(string exp)
{
	char token,//exp中的字符
		topToken;//opStack顶部的标记
	Stack opStack;//运算符栈
	string RPNexp;//逆波兰表达式
	const string BLANK=" ";//在逆波兰表达式中插入空格
	for(int i=0;i<exp.length();i++){
		token=exp[i];
		switch(token){
		case ' ':break;//跳过空白符，不做任何事
		case '(':opStack.push(token);break;
		case ')':
			for(;;){
				assert(!opStack.empty());
				topToken=opStack.top();
				opStack.pop();
				if(topToken=='(')break;
				RPNexp.append(BLANK+topToken);
			}
			break;
		case '+':case '-':
		case '*':case '/':
			for(;;){
				if(opStack.empty()||
					opStack.top()=='('||
					(token=='*'||token=='/')&&
					(opStack.top()=='+'||opStack.top()=='-')
					)
				{opStack.push(token);break;}
				else {
					topToken=opStack.top();
					opStack.pop();
					RPNexp.append(BLANK+topToken);
				}
			}
			break;
		default:RPNexp.append(BLANK+token);
		}
	}
	//弹出栈中剩余的运算符
	for(;;){
		if(opStack.empty())break;
		topToken=opStack.top();
		opStack.pop();
		if(topToken!='(')
			RPNexp.append(BLANK+topToken);
		else 
		{cout<<" ***Error in infix expression ***"<<endl;break;}
	}
	return RPNexp;
}