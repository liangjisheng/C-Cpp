#include"stdio.h"
#include"stdlib.h"
#define max 10
int queue[max];
int front=-1,rear=-1;
/*入队*/
void enqueue(int value)
{
	rear=(rear+1)%max;
	if(rear==front)
		printf("The queue is full!!\n");
	else
		queue[rear]=value;
}
/*出队*/
int delqueue()
{
	int value;
	if(front==rear)
		return -1;
	else
	{
		front=(front+1)%max;
		value=queue[front];
		queue[front]=0;
		return value;
	}
}
/*主程序*/
void main()
{
	int select,i,data;
	printf("(1)Input a data\n");
	printf("(2)Output a data\n");
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
				printf("input the data:");
				scanf("%d",&data);
				enqueue(data);
				printf("The queue is:\n");
				for(i=0;i<max;i++)
				{if(queue[i]!=0)
				    printf("%3d",queue[i]);}
				printf("\n");
				break;
			case 2:
				data=delqueue();
				if(data==-1)
					printf("The queue is empty!!\n");
				else
				{	printf("The queue is:\n");
					for(i=0;i<max;i++)
					{if(queue[i]!=0)
					printf("%3d",queue[i]);}
					printf("\n");}
				break;
			}
			printf("\n(1)Input a data\n");
			printf("(2)Output a data\n");
			printf("(3)exit\n");
			printf("Please select:");
			scanf("%d",&select);
		}while(select!=3);
	}
}