只能在对尾入队，可以在队头和队尾出队的队列叫输入限制性双向队列。

#include"stdio.h"
#include"stdlib.h"
#define max 20
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
/*前端出队*/
int front_delqueue()
{
	int data;
	if(front==rear)
		return -1;
	else
	{
		front=(front+1)%max;
		data=queue[front];
		queue[front]=0;
		return data;
	}
}
/*后端出队*/
int rear_delqueue()
{
	int data;
	if(front==rear)
		return -1;
	else
	{
		data=queue[rear];
		queue[rear]=0;
		rear--;
		if(rear<0&&front!=-1)
			rear=max-1;
		return data;
	}
}
/*输出队列*/
void print(int queue[])
{
	printf("The queue is:\n");
	int i;
	for(i=0;i<max;i++)
	{
		if(queue[i]!=0)
			printf("%3d",queue[i]);
	}
	printf("\n");
}
/*主程序*/
void main()
{
	int select,i,data;
	printf("(1)Input a data\n");
	printf("(2)front out a data\n");
	printf("(2)rear out a data\n");
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
				enqueue(data);
				print(queue);
				break;
			case 2:
				data=front_delqueue();
				if(data==-1)
					printf("The queue is empty!!\n");
				else
				{printf("the front delete data is:%d\n",data);
				print(queue);}
				break;
			case 3:
				data=rear_delqueue();
				if(data==-1)
					printf("The queue is empty!!\n");
				else
				{printf("the rear delete data is:%d\n",data);
				print(queue);}
				break;
			}
			printf("\n(1)Input a data\n");
			printf("(2)front output a data\n");
			printf("(3)rear output a data\n");
			printf("(0)exit\n");
			printf("Please select:");
			scanf("%d",&select);
		}while(select!=0);
	}
}