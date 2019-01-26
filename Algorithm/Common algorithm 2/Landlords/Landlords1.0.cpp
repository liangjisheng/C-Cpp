#include"stdio.h"
#include"time.h"
#include"stdlib.h"
struct card{
	int  huase;//花色
	char point_num;//点数
};
card onecard[54];//牌
card Bigking,Smallking;//大王，小王
//生成一副新的扑克牌
void create_card()
{
	Bigking.point_num='D';//定义大王小王
	Smallking.point_num='S';
	onecard[52].point_num='S';
	onecard[52].huase=52;
	onecard[53].point_num='D';
	onecard[53].huase=53;
	int i,huase=0,control;
	for(i=0;i<52;i++){
		if(i%13==0)huase++;
		onecard[i].huase=huase;//花色
		control=i%13;
		switch(control){//点数
		case 0:
			onecard[i].point_num='A';break;
		case 9:
			onecard[i].point_num='O';break;
		case 10:
			onecard[i].point_num='J';break;
		case 11:
			onecard[i].point_num='Q';break;
		case 12:
			onecard[i].point_num='K';break;
		default:
			onecard[i].point_num=control+'1';
		}
	}
}
//显示一副新的扑克牌
void showcard()
{
	//printf("   %c   %c",onecard[52].point_num,onecard[53].point_num);
	int huase,i;
	for(i=0;i<54;i++){
		if(i%13==0)printf("\n");
		if(onecard[i].huase==52||onecard[i].huase==53)
			printf("   %c",onecard[i].point_num);
		else{
		switch(onecard[i].huase){//控制花色
		case 1:huase=3;break;
		case 2:huase=4;break;
		case 3:huase=5;break;
		case 4:huase=6;break;
		}
		printf("  %c%c",huase,onecard[i].point_num);//输出
		}
	}
	printf("\n");
}
//洗牌
void xipai()
{
	srand(time(0));
	int control;
	card temp;
	for(int i=0;i<100;i++){
		control=rand()%54;
		temp=onecard[0],onecard[0]=onecard[control],onecard[control]=temp;//洗牌交换
	}
}
//定义三个人
card people1_card[20],people2_card[20],people3_card[20];
//斗地主三个人发牌
void sent_card()
{
	int i=0;
	for(int p1=0;p1<17;p1++,i++)
		people1_card[p1]=onecard[i];
	for(int p2=0;p2<17;p2++,i++)
		people2_card[p2]=onecard[i];
	for(int p3=0;p3<17;p3++,i++)
		people3_card[p3]=onecard[i];
}
//输出发好的牌
void output_card(card *p)
{
	for(int i=0;i<17;i++){
		if(p[i].huase==52||p[i].huase==53)
			printf("   %c",p[i].point_num);
		else{
			int huase;
			switch(p[i].huase){
			case 1:huase=3;break;
			case 2:huase=4;break;
			case 3:huase=5;break;
			case 4:huase=6;break;
			}
			printf("  %c%c",huase,p[i].point_num);
		}
	}
	printf("\n");
}
//main
int main(int argc,char *argv[])
{
	create_card();
	printf("一副新的扑克牌如下:\n");
	showcard();
	xipai();
	printf("洗牌如下:\n");
	showcard();
	printf("发牌:\n");
	sent_card();
	printf("第一个人的牌:\n");
	output_card(people1_card);
	printf("第二个人的牌:\n");
	output_card(people2_card);
	printf("第三个人的牌:\n");
	output_card(people3_card);
	return 0;
}