#include"stdio.h"
#include"stdlib.h"
#define max1 10
struct list
{
	int number;
	struct list *next;
};
typedef struct list node;
typedef node *link;
int data[max1]={1,2,3,4,5,6,7,8,9,0};
//释放循环链表
void free_clist(link head)
{
	link po=head->next,po1;
	while(po!=head)
	{po1=po;po=po->next;free(po1);}
	free(head);
}
//插入节点
link insert_clist(link head,link newnode,int key)
{
	link po=head->next;
	while(1)
	{
		if(po->number==key)
		{newnode->next=po->next;po->next=newnode;break;}
		if(po->number!=key&&po->next==head)
		{newnode->next=head;po->next=newnode;head=newnode;break;}
		po=po->next;
	}
	return head;
}
//输出循环链表
void print_clist(link head)
{
	link po=head->next;
	printf("Output the data:\n");
	printf("[%d]",head->number);
	while(po!=head)
	{printf("[%d]",po->number);po=po->next;}
	printf("\n");
}
//建立循环链表
link create_clist(link head,int *data,int max)
{
	link newnode,po;
	int i;
	head=(link)malloc(sizeof(node));
	head->number=data[0];
	head->next=NULL;
	po=head;
	for(i=1;i<max;i++)
	{
		newnode=(link)malloc(sizeof(node));
		newnode->number=data[i];
		newnode->next=NULL;
		po->next=newnode;
		po=newnode;
	}
	po->next=head;
	return head;
}
//主程序
void main()
{
	link head=NULL,newnode;
	int key;
	head=create_clist(head,data,max1);
	print_clist(head);
	while(1)
	{
		printf("\nInput 0 to exit.\n");
		newnode=(link)malloc(sizeof(node));
		printf("Please input the data(exit for 0):");
		scanf("%d",&newnode->number);
		if(newnode->number==0)break;
		printf("Please input the data number for insert:");
		scanf("%d",&key);
		head=insert_clist(head,newnode,key);
		print_clist(head);
	}
	free_clist(head);
}