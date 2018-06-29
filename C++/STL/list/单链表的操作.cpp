#include"stdio.h"
#include"stdlib.h"
struct node 
{
	int number;
	int total;
	struct node *next;
};
typedef struct node Node;
typedef Node *link;
int data[2][10]={{3,9,25,5,7,26,65,80,2,6},
{1050,3850,1000,5670,2250,9650,2380,1700,3000,2000}};
/*-----释放链表---*/
void freelist(link h)
{
	link p;
	while(h!=NULL)
	{
		p=h;
		h=h->next;
		free(p);
	}
}
/*---输出链表---*/
void displist(link h)
{
	link p=h;
	int i=0;
	while(p!=NULL)
	{
		i++;
		if(i==6)
			printf("\n");
		printf("[%d,%d]",p->number,p->total);
		p=p->next;
	}
	printf("\n");
}
/*----创建链表---*/
link creatlist()
{
	link h,p;
	int i;
	h=(link)malloc(sizeof(Node));
	h->number=data[0][0];
	h->total=data[1][0];
	h->next=NULL;
	for(i=1;i<10;i++)
	{
		p=(link)malloc(sizeof(Node));
		p->number=data[0][i];
		p->total=data[1][i];
		p->next=h;
		h=p;
	}
	return h;
}
/*---插入操作----*/
link insertlist(link h,link insert,int key)
{
	link p=h;
	int i;
	if(p->number==key)
	{
		insert->next=h;
		h=insert;
	}
	else
	{
		p=p->next;
		while(p!=NULL&&p->number!=key)
			p=p->next;
		if(p==NULL)
			printf("no find the key!!\n");
		else
		{
			insert->next=p->next;
			p->next=insert;
		}
	}
	return h;
}
/*---查找操作----*/
void findlist(link h,int key1)
{
	link p=h;
	int i;
	for(i=0;i<10&&p->number!=key1;i++)
		p=p->next;
	if(p==NULL)
		printf("no find the key1!!\n");
	else
		printf("the key1 is:[%d,%d]\n",p->number,p->total);
}
/*---删除操作----*/
link deletelist(link h,int key)
{
	link p=h,pre;
	if(p->number==key)
	{
		h=h->next;
		free(p);
		return h;
	}
	else
	{
		pre=h;
		p=p->next;
		while(p!=NULL&&p->number!=key)
		{
			pre=p;
			p=p->next;
		}
		if(p==NULL)
			printf("no find the key2!!\n");
		else
		{
			pre->next=p->next;
			free(p);
			return h;
		}
	}
}
/*----主程序----*/
void main()
{
	link h,insert;
	int key,key1,key2;
	h=creatlist();
	printf("创建链表:\n");
	displist(h);
	printf("输入要查找的值:");
	scanf("%d",&key1);
	findlist(h,key1);
	insert=(link)malloc(sizeof(Node));
	printf("创建一个新的节点:\n");
	printf("please input the newNode number:");
	scanf("%d",&insert->number);
	printf("please input the newNode total:");
	scanf("%d",&insert->total);
	printf("你想在某个数后面插入，输入这个数的值:");
	scanf("%d",&key);
	h=insertlist(h,insert,key);
	printf("输出插入后的链表:\n");
	displist(h);
	printf("输入你要删除的元素的number值:");
	scanf("%d",&key2);
	h=deletelist(h,key2);
	printf("输出删除后的链表:\n");
	displist(h);
	freelist(h);
}