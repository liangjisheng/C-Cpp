#include"stdio.h"
#include"stdlib.h"
#define maxsize 10
int queue[maxsize];
int front=-1;
int rear=-1;
/*入队*/
void addqueue(int value)
{
	if(rear>=maxsize)
		printf("The queue is full!!\n");
	else
	{
		rear++;
		queue[rear]=value;
	}
}
/*出队*/
int delqueue()
{
	int data;
	if(front==rear)
		return -1;
	else
	{
		front++;
		data=queue[front];
		queue[front]=0;
		return data;
	}
}
/*输出队列*/
void dispqueue(int a[])
{
	int i;
	for(i=0;i<maxsize;i++)
	{
		if(a[i]!=0)
			printf("%4d",a[i]);
	}
	printf("\n");
}
/*主程序*/
void main()
{
	int select,data;
	printf("(1)input a data\n");
	printf("(2)output a data\n");
	printf("(3)exit\n");
	printf("Please select\n");
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
				printf("output the queue:\n");
				dispqueue(queue);
				break;
			case 2:
				data=delqueue();
				if(data==-1)
					printf("The queue is empty!\n");
				else
				{
					printf("the output data is:%d\n",data);
					dispqueue(queue);
				}
				break;
			}
			printf("\n(1)input a data\n");
			printf("(2)output a data\n");
			printf("(3)exit\n");
			printf("Please select\n");
	        scanf("%d",&select);
		}while(select!=3);
	}
}