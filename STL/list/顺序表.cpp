#include"stdio.h"
#include"string.h"
#define maxlen 100
typedef struct 
{
	char key[10];
	char name[20];
	int age;
}DATA;
typedef struct 
{
	DATA listdata[maxlen+1];
	int listlen;
}SLtype;
//SL-init
void SLinit(SLtype *SL)
{SL->listlen=0;}
//SLlength
int SLlength(SLtype *SL)
{return SL->listlen;}
//SLinsert
int SLinsert(SLtype *SL,int n,DATA data)
{
	int i;
	if(SL->listlen>=maxlen)
	{printf("顺序表已满，不能插入节点!\n");return 0;}
	if(n<1||n>SL->listlen-1)
	{printf("插入元素序号错误，不能插入元素!\n");return 0;}
	for(i=SL->listlen;i>=n;i--)
	{SL->listdata[i+1]=SL->listdata[i];}
	SL->listdata[n]=data;
	SL->listlen++;
	return 1;
}
//SLadd
int SLadd(SLtype *SL,DATA data)
{
	if(SL->listlen>=maxlen)
	{printf("顺序表已满，不能添加节点!\n");return 0;}
	SL->listdata[++SL->listlen]=data;
	return 1;
}
//SLdelete
int SLdelete(SLtype *SL,int n)
{
	int i;
	if(n<1||n>SL->listlen+1)
	{printf("删除节点序号错误，不能删除节点!\n");return 0;}
	for(i=n;i<SL->listlen;i++)
		SL->listdata[i]=SL->listdata[i+1];
	SL->listlen--;
	return 1;
}
//SLfind-by-num
DATA *SLfindbynum(SLtype *SL,int n)
{
	if(n<1||n>SL->listlen+1)
	{printf("节点序号错误，不能返回节点!\n");return NULL;}
	return &(SL->listdata[n]);
}
//SLfindbycont
int SLfindbycont(SLtype *SL,char *key)
{
	int i;
	for(i=1;i<=SL->listlen;i++)
	{if(strcmp(SL->listdata[i].key,key)==0)return i;}
	return 0;
}
//SLall
int SLall(SLtype *SL)
{
	int i;
	for(i=1;i<=SL->listlen;i++)
		printf("(%s,%s,%d)\n",SL->listdata[i].key,SL->listdata[i].name,SL->listdata[i].age);
	return 0;
}
//main
int main()
{
	int i;
	SLtype SL;
	DATA data,*pdata;
	char key[10];
	printf("顺序表表示操作演示!\n");
	SLinit(&SL);
	printf("初始化顺序表完成!\n");

	do{
		printf("输入添加的节点(学号 姓名 年龄):");
		fflush(stdin);
		scanf("%s%s%d",&data.key,&data.name,&data.age);
		if(data.age)
		{if(!SLadd(&SL,data))break;}
		else break;
	}while(1);
	printf("\n顺序表中的节点顺序为:\n");
	SLall(&SL);

	fflush(stdin);
	printf("\n要取出节点的序号:");
	scanf("%d",&i);
	pdata=SLfindbynum(&SL,i);
	if(pdata)printf("第%d个节点为:(%s,%s,%d)\n",i,pdata->key,pdata->name,pdata->age);

	fflush(stdin);
	printf("\n要查找的关键字:");
	scanf("%s",key);
	i=SLfindbycont(&SL,key);
	pdata=SLfindbynum(&SL,i);
	if(pdata)printf("第%d个节点为:(%s,%s,%d)\n",i,pdata->key,pdata->name,pdata->age);
	//getch();
	return 0;
}