窃贼问题求解，程序代码
#include"stdio.h"
#include"stdlib.h"
typedef struct goods
{
	double *value,*weight;
	char *isselect;
}gtype;
double maxvalue;     //方案最大价值
double totalvalue;   //物品总价值
double maxwt;        //窃贼能拿的最大数量
int num;             //物品数量
char *seltemp;       //临时数组
//窃贼问题
void backpack(gtype *goods,int i,double wt,double vt)
{
	int k;
	if(wt+goods->weight[i]<=maxwt)            //将物品i包含在当前方案中，判断重量小于等于限制重量
	{
		seltemp[i]=1;                         //选中第i个物品
		if(i<num-1)backpack(goods,i+1,wt+goods->weight[i],vt);//如果物品i不是最后一个物品，递归调用，继续添加物品
		else{
			for(k=0;k<num;k++)goods->isselect[k]=seltemp[k];
			maxvalue=vt;                      //保存当前方案最大价值
		}
	}
	seltemp[i]=0;                             //取消物品i的选择状态
	if(vt-goods->value[i]>maxvalue)           //还可以继续添加物品
	{
		if(i<num-1)backpack(goods,i+1,wt,vt-goods->value[i]);//递归调用
		else{
			for(k=0;k<num;k++)goods->isselect[k]=seltemp[k];
			maxvalue=vt-goods->value[i];
		}
	}
}
//main
void main()
{
	double sumweight;
	gtype goods;
	int i,lend,lenc;
	printf("窃贼问题求解.\n");
	printf("输入窃贼背包所能容纳的最大重量:");
	scanf("%lf",&maxwt);
	printf("输入可选物品数量:");
	scanf("%d",&num);
	lend=sizeof(double)*num;
	lenc=sizeof(char)*num;
	if(!(goods.value=(double*)malloc(lend)))  //分配内存
	{printf("内存分配失败\n");exit(0);}
	if(!(goods.weight=(double*)malloc(lend))) //分配内存
	{printf("内存分配失败\n");exit(0);}
	if(!(goods.isselect=(char*)malloc(lenc))) //分配内存
	{printf("内存分配失败\n");exit(0);}
	if(!(seltemp=(char*)malloc(lenc)))        //分配内存
	{printf("内存分配失败\n");exit(0);}
	totalvalue=0;
	for(i=0;i<num;i++){
		printf("输入第%d号物品的重量和价值:",i+1);
		scanf("%lf%lf",&goods.weight[i],&goods.value[i]);
		totalvalue+=goods.value[i];//统计所用物品的总价值
	}
	printf("\n背包最大能装的重量为:%.2f\n\n",maxwt);
	for(i=0;i<num;i++)
	{printf("第%d号物品重:%.2f,价值%.2f\n",i+1,goods.weight[i],goods.value[i]);
	seltemp[i]=0;}
	maxvalue=0;
	backpack(&goods,0,0.0,totalvalue);   //求解
	sumweight=0;
	printf("\n可将一下物品装入背包，是背包装的物品总价值最大:\n");
	for(i=0;i<num;i++){
		if(goods.isselect[i]){
			printf("第%d号物品,重量:%.2f\n",i+1,goods.weight[i],goods.value[i]);
			sumweight+=goods.weight[i];
		}
	}
	printf("\n总重量为:%.2f,总价值为:%.2f\n",sumweight,maxvalue);
}


运行结果如下：
窃贼问题求解.
输入窃贼背包所能容纳的最大重量:8
输入可选物品数量:5
输入第1号物品的重量和价值:6 48
输入第2号物品的重量和价值:5 40
输入第3号物品的重量和价值:2 12
输入第4号物品的重量和价值:1 8
输入第5号物品的重量和价值:1 7

背包最大能装的重量为:8.00

第1号物品重:6.00,价值48.00
第2号物品重:5.00,价值40.00
第3号物品重:2.00,价值12.00
第4号物品重:1.00,价值8.00
第5号物品重:1.00,价值7.00

可将一下物品装入背包，是背包装的物品总价值最大:
第1号物品,重量:6.00
第4号物品,重量:1.00
第5号物品,重量:1.00

总重量为:8.00,总价值为:63.00
Press any key to continue