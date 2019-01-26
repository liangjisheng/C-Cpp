#include"stdio.h"
#include"stdlib.h"
#define max1 10
int data[max1]={1,2,3,4,5,6,7,8,9,0};
struct list
{
	int number;
	struct list *next;
};
typedef struct list node;
typedef node *link;
//释放循环链表
void free_clist(link head)
{
	link po,p1=head->next;
	while(po!=head)
	{po=p1;p1=p1->next;free(po);}
	free(head);
}
//输出循环链表
void print_clist(link head)
{
	link po=head;
	printf("output the clist:\n");
	do{printf("[%d]",po->number);po=po->next;
	}while(po!=head);
	printf("\n");
}
//建立循环链表
link create_clist(link head,int *data,int max)
{
	link po,newnode;
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
	link head;
	head=create_clist(head,data,max1);
	print_clist(head);
	free_clist(head);
}