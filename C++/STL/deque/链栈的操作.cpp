链栈的操作
#include"stdio.h"
#include"stdlib.h"
typedef struct node 
{
	int data;
	struct node *next;
}stacknode;
typedef stacknode *link;
/*---初始化栈表---*/
link initstack()
{
	link h;
	h=(link)malloc(sizeof(stacknode));
	h->data=0;
	h->next=NULL;
	return h;
}
/*---判栈空---*/
void emptystack(link h)
{
	if(h->next==NULL)
		printf("此时栈空\n");
	else
		printf("此时栈不空\n");
}
/*---取栈顶元素---*/
int topstack(link h)
{
	link p=h->next;
	if(h->next==NULL)
		return 0;
	else
		return p->data;
}
/*---入栈---*/
link pushstack(link h,int x)
{
	link p;
	p=(link)malloc(sizeof(stacknode));
	p->data=x;
	p->next=h->next;
	h->next=p;
	return h;
}
/*---出栈---*/
link popstack(link h)
{
	if(h->next==NULL)
		return h->next;
	else
	{
		link p=h;
		h=h->next;
		free(p);
		return h;
	}
}
/*---清空栈表---*/
void freestack(link h)
{
	if(h->next==NULL)
		printf("此时栈空，不用清空\n");
	else
	{
		link p;
		while(h!=NULL)
		{
			p=h;
			h=h->next;
			free(p);
		}
		printf("栈表已清空\n");
	}
}
/*---创建栈表---*/
link creatstack()
{
	link h,p;
	h=initstack();
	int data;
	while(1)
	{
		printf("input the data:");
		scanf("%d",&data);
		if(data==0)
			break;
		else
		{
			p=(link)malloc(sizeof(stacknode));
			p->data=data;
			p->next=h->next;
			h->next=p;
		}
	}
	return h;
}
/*---输出栈表---*/
void dispstack(link h)
{
	link p=h->next;
	while(p!=NULL)
	{
		printf("%4d",p->data);
		p=p->next;
	}
	printf("\n");
}
/*---主程序---*/
void main()
{
	link head;
	int data;
	printf("创建栈表(0 结束):\n");
	head=creatstack();
	emptystack(head);
	printf("输出栈表:\n");
	dispstack(head);
	printf("取栈顶元素:");
	data=topstack(head);
	if(data==0)
		printf("栈空，不能取\n");
	else
		printf("%4d\n",data);
	printf("入栈\n");
	printf("input the insert number:");
	scanf("%d",&data);
	head=pushstack(head,data);
	printf("输出栈表:\n");
	dispstack(head);
	printf("出栈\n");
	head=popstack(head);
	if(head==NULL)
		printf("栈空，不能出栈\n");
	else
		dispstack(head);
	freestack(head);
}


链栈的另一种操作
#include"stdio.h"
#include"stdlib.h"
struct snode
{
	int data;
	struct snode *next;
};
typedef struct snode snode;
typedef struct snode *link;
link stack=NULL;
/*---输出栈表---*/
void printstack()
{
	link p=stack;
	if(p==NULL)
		printf("栈空,不能输出!\n");
	else
	{
		while(p!=NULL)
		{
			printf("[%d]",p->data);
			p=p->next;
		}
		printf("\n");
	}
}
/*---入栈---*/
void pushstack(int data)
{
	printf("output the stack before:\n");
	printstack();
	link p;
	p=(link)malloc(sizeof(snode));
	p->data=data;
	p->next=stack;
	stack=p;
	printf("output the stack later:\n");
	printstack();
}
/*---出栈---*/
int popstack()
{
	link p=stack;
	int data;
	if(p==NULL)
		return 0;
	else
	{
		printf("output the stack before:\n");
		printstack();
		data=p->data;
		stack=stack->next;
		free(p);
		printf("output the stack later:\n");
		printstack();
		return data;
	}
}
/*---主程序---*/
void main()
{
	link p;
	int select,data;
	printf("(1)Input a stack data.\n");
	printf("(2)Output a stack data.\n");
	printf("(3)Exit.\n");
	printf("Please select:");
	scanf("%d",&select);
	do
	{
		switch(select)
		{
		case 1:printf("input the data:");
			scanf("%d",&data);
			pushstack(data);
			break;
		case 2:data=popstack();
			printf("the top data of stack is [%d]\n",data);
			break;
		}
		printf("\n(1)Input a stack data.\n");
		printf("(2)Output a stack data.\n");
		printf("(3)Exit.\n");
		printf("Please select:");
	    scanf("%d",&select);
	}while(select!=3);
}