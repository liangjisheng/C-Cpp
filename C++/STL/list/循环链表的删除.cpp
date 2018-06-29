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
	link po=head->next,po1;
	while(po!=head)
	{po1=po;po=po->next;free(po1);}
	free(head);
}
//删除循环链表节点
link delete_clist(link head,int key)
{
	link po=head,back,last;
	while(1)
	{
		if(po->number!=key&&po->next==head)
		{printf("No found!\n");break;}
		if(head->number==key)
		{
			last=head;
			while(last->next!=head)last=last->next;
			head=po->next;
			last->next=head;
			free(po);break;
		}
		back=po;
		po=po->next;
		if(po->number==key)
		{back->next=po->next;free(po);break;}
	}
	return head;
}
//输出循环链表
void print_clist(link head)
{
	link po=head->next;
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
	head->number=data[0];head->next=NULL;
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
	link head=NULL;
	int key;
	head=create_clist(head,data,max1);
	printf("Output the data:\n");
	print_clist(head);
	while(1)
	{
		printf("\nInput 0 to exit.\n");
		printf("Please input the data number for delete:");
		scanf("%d",&key);
		if(key==0)break;
		head=delete_clist(head,key);
		print_clist(head);
	}
	free_clist(head);
}