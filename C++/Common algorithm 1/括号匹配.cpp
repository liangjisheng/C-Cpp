#include"stdio.h"
#include"stdlib.h"
#include"conio.h"
#include"malloc.h"
#define len 20
#define increment 10
typedef struct node{
	char *base,*top;
	int size;
}stacktype;
//initstak
void initstack(stacktype *stack)
{
	stack->base=(char*)malloc(len*sizeof(char));
	stack->top=stack->base;
	stack->size=len;
}
//push
void pushstack(stacktype *stack,char ch)
{
	int st=stack->top-stack->base;
	if(st>=stack->size)
	{
		stack->base=(char*)realloc(stack->base,(stack->size+increment)*sizeof(char));
		if(!stack->base)exit(0);
		stack->top=stack->base+stack->size;
		stack->size=stack->size+increment;
	}
	*(stack->top)=ch;
	stack->top++;
}
//pop
void popstack(stacktype *stack,char *ch)
{
	if(stack->base==stack->top){}
	*ch=*--(stack->top);
}
//stacklen
int stacklen(stacktype stack)
{return stack.top-stack.base;}
//pipei
void pipei()
{
	stacktype stack;
	char ch,temp;
	int match;
	initstack(&stack);
	fflush(stdin);
	scanf("%c",&ch);
	while(ch!='0'){
		if(!stacklen(stack))pushstack(&stack,ch);
		else{
			popstack(&stack,&temp);
			match=0;
			if(temp=='('&&ch==')')match=1;
			if(temp=='['&&ch==']')match=1;
			if(temp=='<'&&ch=='>')match=1;
			if(temp=='{'&&ch=='}')match=1;
			if(match==0)
			{pushstack(&stack,temp);pushstack(&stack,ch);}
		}
		scanf("%c",&ch);
	}
	if(!stacklen(stack))printf("输入的括号完全匹配.\n");
	else printf("输入的括号不匹配.\n");
}
//main
void main()
{
	char again;
	printf("括号匹配问题!\n");
s1:printf("输入一组括号(exit for 0)支持的括号有:{},(),[],<>.\n");
   pipei();
s2:printf("\n继续玩(y/n)?");
   fflush(stdin);
   scanf("%c",&again);
   if(again=='y'||again=='Y')goto s1;
   else if(again=='n'||again=='N')goto s3;
   else {printf("输入错误，重新输入.\n");goto s2;}
s3:printf("game over!!\n");
}
