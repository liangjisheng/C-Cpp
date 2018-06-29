#include"stdio.h"
#include"stdlib.h"
struct node
{
	int data;
	struct node *next;
};
typedef struct node qnode;
typedef qnode *qlink;
qlink front=NULL;
qlink rear=NULL;
/*入队*/
void addqueue(int value)
{
	qlink p;
	p=(qlink)malloc(sizeof(qnode));
	p->data=value;
	p->next=NULL;
	if(rear==NULL)
	{rear=p;front=p;}
	else
	{rear->next=p;rear=p;}
}
/*出队*/
int delqueue()
{
	qlink p;
	int value;
	if(front!=NULL)
	{
		p=front;
		value=p->data;
	    if(front==NULL)
			rear=NULL;
		front=front->next;
		free(p);
		return value;
	}
	else
		return 0;
}
/*输出队列*/
void dispqueue()
{
	printf("output the queue:\n");
	qlink p=front;
	if(p==NULL)
		printf("队列空,不能输出!\n");
	else
	{
		while(p!=NULL)
		{printf("%4d",p->data);p=p->next;}
		printf("\n");
	}
}
/*主程序*/
void main()
{
	int data,select;
	qlink p;
	printf("(1)入队\n");
	printf("(2)出队\n");
	printf("(3)exit\n");
	printf("Please select:");
	scanf("%d",&select);
	if(select!=3)
	{
		do
		{
			switch(select)
			{
			case 1:
				printf("input a data:");
				scanf("%d",&data);
				addqueue(data);
				dispqueue();
				break;
			case 2:
				if(data=delqueue()==0)
					printf("The queue is empty!!\n");
				else
				{printf("the output data is:%d\n",data);
					dispqueue();}
				break;
			}
			printf("\n(1)入队\n");
        	printf("(2)出队\n");
         	printf("(3)exit\n");
	        printf("Please select:");
         	scanf("%d",&select);
		}while(select!=3);
	}
}

