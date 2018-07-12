#include"iostream"
//#include"Stack.h"
using namespace std;
//init_stack
void init_stack(int *stack)
{
	for(int i=0;i<32;i++)
		stack[i]=0;
}
//push_stack
void push_stack(int *stack,int *top,int mod)
{
	stack[*top]=mod;(*top)++;
}
//popstack
void pop_stack(int *stack,int *top)
{
	stack[*top]=0;(*top)--;
}
//main
int main(int argc,char *argv[])
{
	int number,remainder,stack[32],top=0;
	char response;
	init_stack(stack);//初始化栈
	do{
		cout<<"Enter positive integer to convert:";
		cin>>number;
		while(number!=0){
			remainder=number%2;
			push_stack(stack,&top,remainder);
			number/=2;
		}
		top--;
		cout<<"Base_two representation: ";
		while(top>=0){
			remainder=stack[top];
			pop_stack(stack,&top);
			cout<<remainder;
		}
		cout<<endl;
		cout<<endl<<"More(Y or N)? ";
		cin>>response;
	}while(response=='y'||response=='Y');
	return 0;
}