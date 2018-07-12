#include"stdio.h"
#include"string.h"
#include"malloc.h"
typedef struct list{
	int number;
	int psw;
	struct list *next;
}node,*link;
//insert
void insertlist(link *list,link q,int number,int psw)
{
	link p;
	p=(link)malloc(sizeof(node));
	p->number=number;
	p->psw=psw;
	if(*list==NULL){*list=p;p->next=NULL;}
	else {p->next=q->next;q->next=p;}
}
//circlefun
void circlefun(link *list,int m)
{
	link p,q;
	int i;
	p=q=*list;
	while(q->next!=p)q=q->next;
	printf("游戏者按照如下顺序出列.\n");
	while(p->next!=p){
		for(i=0;i<m-1;i++)
		{q=p;p=p->next;}
		q->next=p->next;
		printf("第%d个人出列,其手中数字为:%d\n",p->number,p->psw);
		m=p->psw;
		free(p);
		p=q->next;
	}
	printf("\n最后一个人是%d,其手中的出列数字是:%d\n",p->number,p->psw);
}
//main
void main()
{
	link list=NULL,list1=NULL,q=NULL;
	int num,baoshu,i,e;
	printf("复杂约瑟夫环求解.\n");
	printf("input the josephus number:\n");
	scanf("%d",&num);
	printf("input the everyone number:\n");
	for(i=0;i<num;i++){
		scanf("%d",&e);
		insertlist(&list1,q,i+1,e);
		if(i==0)q=list1;
		else q=q->next;
	}
	q->next=list1;
	list=list1;
	printf("input the first number:\n");
	scanf("%d",&baoshu);
	circlefun(&list,baoshu);
}
