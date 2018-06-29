#include"stdio.h"
#include"stdlib.h"
#define max1 10
struct dlist
{
	int number;
	struct dlist *back;
	struct dlist *next;
};
typedef struct dlist dnode;
typedef dnode *dlink;
int data[max1]={1,2,3,4,5,6,7,8,9,0};
//free_dlist
void free_dlist(dlink head)
{
	dlink po;
	while(head!=NULL)
	{po=head;head=head->next;free(po);}
}
//print_dlist
void print_dlist(dlink head)
{
	dlink po=head;
	printf("Output the data:\n");
	while(po!=NULL)
	{printf("[%d]",po->number);po=po->next;}
	printf("\n");
}
//create_dlist
dlink create_dlist(dlink head,int *data,int max)
{
	dlink po,newnode;
	int i;
	head=(dlink)malloc(sizeof(dnode));
	head->number=data[0];
	head->next=NULL;head->back=NULL;
	po=head;
	for(i=1;i<max;i++)
	{
		newnode=(dlink)malloc(sizeof(dnode));
		newnode->number=data[i];
		newnode->next=NULL;newnode->back=NULL;
		po->next=newnode;
		newnode->back=po;
		po=newnode;
	}
	return head;
}
//insert_dlist
dlink insert_dlist(dlink head,dlink newnode,int key)
{
	dlink po=head;
	int counter=1;
	while(1)
	{
		if(po->number==key)
		{
			newnode->next=po->next;
			newnode->back=po;
			po->next=newnode;
			if(newnode->next!=NULL)
				newnode->next->back=newnode;
			break;
		}
		if(po->number!=key&&counter>=max1)
		{
			//newnode->next=po;
			//po->back=newnode;
			//head=newnode;
			printf("No found the insert number.\n");
			break;
		}
		counter++;
		po=po->next;
	}
	return head;
}
//主程序
void main()
{
	dlink head=NULL,newnode;
	int key;
	head=create_dlist(head,data,max1);
	print_dlist(head);
	while(1)
	{
		printf("Input 0 to exit.\n");
		newnode=(dlink)malloc(sizeof(dnode));
		printf("Please input the data:");
		scanf("%d",&newnode->number);
		if(newnode->number==0)break;
		printf("Please input the data number for insert:");
		scanf("%d",&key);
		head=insert_dlist(head,newnode,key);
		print_dlist(head);
	}
	free_dlist(head);
}