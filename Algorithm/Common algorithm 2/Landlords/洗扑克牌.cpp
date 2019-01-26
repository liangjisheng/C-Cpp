#include"stdio.h"
#include"stdlib.h"
#include"time.h"
typedef struct Card{
	int suit;
	char number;
}card;
card onecard[52];
//showcard
void showcard()
{
	int i,j,sign;
	for(i=0,j=0;i<52;i++,j++){
		if(i%13==0)printf("\n");
		switch(onecard[i].suit){
		case 0:sign=3;break;
		case 1:sign=4;break;
		case 2:sign=5;break;
		case 3:sign=6;break;
		}
		printf("  %c%c",sign,onecard[i].number);
	}
	printf("\n");
}
//shuffle
void shuffle()
{
	int i,j,temp,suit=0;
	card tempcard;
	for(i=0;i<52;i++){
		if(i%13==0)suit++;
		onecard[i].suit=suit;
		temp=i%13;
		switch(temp){
		case 0:onecard[i].number='A';break;
		case 9:onecard[i].number='0';break;
		case 10:onecard[i].number='J';break;
		case 11:onecard[i].number='Q';break;
		case 12:onecard[i].number='K';break;
		default :onecard[i].number=temp+'1';
		}
	}
	printf("一副新牌初始排列如下:\n");
	showcard();
	srand(time(NULL));
	for(i=0;i<52;i++){
		j=rand()%52;
		tempcard=onecard[j],onecard[j]=onecard[i],onecard[i]=tempcard;//随机换牌
	}
}
//main
void main()
{
	shuffle();
	printf("\n洗牌后排列如下:\n");
	showcard();
}