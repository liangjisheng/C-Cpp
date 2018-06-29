顺序栈的操作
#include"stdio.h"
#include"stdlib.h"
#define maxsize 100
typedef struct
{
	int data[maxsize];
	int top;
}seqstack;
int i=0;
/*---初始化顺序栈---*/
seqstack *initseqstack()
{
	seqstack *s;
	s=(seqstack*)malloc(sizeof(seqstack));
	s->top=0;
	return s;
}
/*---判栈空---*/
int emptyseqstack(seqstack *s)
{
	if(s->top==0)
		return 1;
	else
		return 0;
}
/*---入栈---*/
void pushseqstack(seqstack *s,int x)
{
	if(s->top==maxsize)
		printf("不能入栈\n");
	else
	{
		s->data[s->top]=x;
		s->top++;
		printf("入栈成功\n");
	}
}
/*--出栈---*/
int popseqstack(seqstack *s)
{
	if(s->top==0)
		return 0;
	else
	{
		s->top--;
		return 1;
	}
}
/*---取栈顶元素---*/
int topseqstack(seqstack *s)
{
	int n=s->top;
	if(n==0)
		return 0;
	else
		return s->data[n-1];
}
/*---输入栈中元素--*/
seqstack *inputseqstack()
{
	seqstack *s;
	int key;
	s=initseqstack();
	while(1)
	{
		printf("输入栈中第%d元素:",i+1);
		scanf("%d",&key);
		if(key==100)
			break;
		else
		{
		s->data[s->top]=key;
		s->top++;
		i++;
		}
	}
	return s;
}
/*---输出栈中元素---*/
void printseqstack(seqstack *s)
{
	int j=s->top;
	if(s->top==0)
		printf("栈空!\n");
	else
	{
		while(j)
		{
			printf("%5d",s->data[j-1]);
			j--;
		}
	}
	printf("\n");
}
/*---主程序---*/
void main()
{
	seqstack *s1;
	int t,x;
	printf("输入栈中元素(输入100退出):\n");
	s1=inputseqstack();
	/*--判栈空?*/
	t=emptyseqstack(s1);
	if(t==1)
		printf("此时栈空\n");
	else
		printf("此时栈不空\n");
	printf("输出栈中元素:\n");
	printseqstack(s1);
	/*--入栈--*/
	printf("input the insert number:");
	scanf("%d",&x);
	pushseqstack(s1,x);
	printf("输出栈中元素:\n");
	printseqstack(s1);
	/*--取栈顶元素--*/
	printf("取栈顶元素:");
	x=topseqstack(s1);
	printf("%d\n",x);
	/*--出栈--*/
	t=popseqstack(s1);
	if(t==0)
		printf("出栈失败\n");
	else
		printf("出栈成功\n");
	printf("取栈顶元素:");
	x=topseqstack(s1);
	printf("%d\n",x);
	printf("输出栈中元素:\n");
	printseqstack(s1);
}

顺序栈的另一种操作
#include"stdio.h"
#define maxsize 10
int stack[maxsize];
int top=-1;
/*---入栈---*/
void push(int value)
{
	int i;
	if(top>=maxsize)
		printf("栈满，不能入栈!\n");
	else
	{
		printf("output the stack before:\n");
		for(i=top;i>=0;i--)
			printf("[%d]",stack[i]);
		printf("\n");
		top++;
		stack[top]=value;
		printf("output the stack later:\n");
		for(i=top;i>=0;i--)
			printf("[%d]",stack[i]);
		printf("\n");
	}
}
/*---出栈---*/
int pop()
{
	int i,value;
	if(top<0)
		return 0;
	else
	{
		printf("output the stack before:\n");
		for(i=top;i>=0;i--)
			printf("[%d]",stack[i]);
		printf("\n");
		value=stack[top];
		top--;
		printf("output the stack lster:\n");
		for(i=top;i>=0;i--)
			printf("[%d]",stack[i]);
		printf("\n");
		return value;
	}
}
/*---主程序---*/
void main()
{
	int select,value;
	printf("(1)Input a stack data.\n");
	printf("(2)Output s stack data.\n");
	printf("(3)Exit.\n");
	printf("Please select:");
	scanf("%d",&select);
	do
	{
		switch(select)
		{
		case 1:printf("input the data:");
			scanf("%d",&value);
			push(value);
			break;
		case 2:value=pop();
			printf("the top data is %d\n",value);
			break;
		}
		printf("\n(1)Input a stack data.\n");
		printf("(2)Output a stack data.\n");
		printf("(3)Exit.\n");
		printf("Please select:");
		scanf("%d",&select);
		printf("\n");
	}while(select!=3);
}
运行结果
(1)Input a stack data.
(2)Output s stack data.
(3)Exit.
Please select:1
input the data:12
output the stack before:

output the stack later:
[12]

(1)Input a stack data.
(2)Output a stack data.
(3)Exit.
Please select:1

input the data:23
output the stack before:
[12]
output the stack later:
[23][12]

(1)Input a stack data.
(2)Output a stack data.
(3)Exit.
Please select:1

input the data:34
output the stack before:
[23][12]
output the stack later:
[34][23][12]

(1)Input a stack data.
(2)Output a stack data.
(3)Exit.
Please select:2

output the stack before:
[34][23][12]
output the stack lster:
[23][12]
the top data is 34

(1)Input a stack data.
(2)Output a stack data.
(3)Exit.
Please select:2

output the stack before:
[23][12]
output the stack lster:
[12]
the top data is 23

(1)Input a stack data.
(2)Output a stack data.
(3)Exit.
Please select:3

Press any key to continue
