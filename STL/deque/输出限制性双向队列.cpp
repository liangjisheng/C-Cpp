只能在队头出队，但可以在队头和队尾入队的队列叫输出限制性双向队列。
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
/*从后端入队*/
void rear_enqueue(int data)
{
	qlink p;
	p=(qlink)malloc(sizeof(qnode));
	p->data=data;
	p->next=NULL;
	if(rear==NULL)
	{
		rear=p;
		front=p;
	}
	else
	{
		rear->next=p;
		rear=p;
	}
}
/*从前端入队*/
void front_enqueue(int data)
{
	qlink p;
	p=(qlink)malloc(sizeof(qnode));
	p->data=data;
	p->next=NULL;
	if(front==NULL)
	{
		front=p;
		rear=p;
	}
	else
	{
		p->next=front;
		front=p;
	}
}
/*从前端出队*/
int front_delqueue()
{
	int data;
	if(front==NULL)
		return -1;
	else
	{
		qlink p=front;
		data=front->data;
		front=front->next;
		if(front==NULL)
			rear=NULL;
		free(p);
		return data;
	}
}
/*输出队列*/
void print(qlink front)
{
	qlink p=front;
	while(p!=NULL)
	{
		printf("%3d",p->data);
		p=p->next;
	}
	printf("\n");
}
/*主程序*/
void main()
{
	int select,data;
	printf("(1)from front input a data\n");
	printf("(2)from rear input a data\n");
	printf("(3)from front output a data\n");
	printf("(0)exit\n");
	printf("Please select:");
	scanf("%d",&select);
	if(select!=0)
	{
		do
		{
			switch(select)
			{
			case 1:
				printf("input a data:");
				scanf("%d",&data);
				front_enqueue(data);
				printf("The queue is:\n");
				print(front);
				break;
			case 2:
				printf("input a data:");
				scanf("%d",&data);
				rear_enqueue(data);
				printf("The queue is:\n");
				print(front);
				break;
			case 3:
				data=front_delqueue();
				if(data==-1)
					printf("The queue is empty!!\n");
				else
				{
					printf("The delete data is:%d",data);
					printf("The queue is:\n");
					print(front);
				}
				break;
			}
			printf("\n(1)from front input a data\n");
			printf("(2)from rear input a data\n");
			printf("(3)from front output a data\n");
			printf("(0)exit\n");
			printf("Please select:");
	        scanf("%d",&select);
		}while(select!=0);
	}
}