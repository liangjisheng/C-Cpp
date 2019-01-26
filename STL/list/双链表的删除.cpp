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
//delete_dlist
dlink delete_dlist(dlink head,int key)
{
	dlink po=head,back;
	while(1)
	{
		if(po->next==NULL)
		{printf("No found!\n");break;}
		if(head->number==key)
		{
			head=head->next;
			head->back=NULL;
			free(po);
			break;
		}
		po=po->next;
		if(po->number=key)
		{
			back=po->back;
			back->next=po->next;
			if(po->next!=NULL)
				po->next->back=back;
			free(po);
			break;
		}
	}
	return head;
}
//main
int main()
{
	dlink head=NULL;
	int key;
	head=create_dlist(head,data,max1);
	print_dlist(head);
	while(1)
	{
		printf("-1 to exit.\n");
		printf("Please input the data number for delete:");
		scanf("%d",&key);
		if(key==-1)break;
		head=delete_dlist(head,key);
		print_dlist(head);
	}
	free_dlist(head);
	return 0;
}