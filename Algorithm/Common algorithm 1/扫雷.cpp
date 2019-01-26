//扫雷游戏代码源码

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main ()
{
	int delta[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
	int row =0,col = 0,num = 0;
	char map[10][10] = {0};
	char show[10][10] = {0};
	srand(time(0));
	for(row = 0;row <= 9;row++)
	{
		for(col = 0;col <= 9;col++)
			map[row][col] = '0';
	}

	do
	{
		row = rand() % 10;
		col = rand() % 10;
		if(map[row][col] == '0')
		{
			map[row][col] = 'x';
			num++;
		}
	}while(num < 10);

	for (row = 0;row <= 9;row++)
	{
		for (col = 0;col <= 9;col++)
		{
			if(map[row][col] != 'x')
			{
				int cnt = 0;
				for (num = 0;num <= 7;num++)
				{
					if(row + delta[num][0] < 0) continue;
					if(row + delta[num][0] > 9) continue;
					if(col + delta[num][1] < 0) continue;
					if(col + delta[num][1] > 9) continue;
					if(map[row + delta[num][0]][col + delta[num][1]]== 'x'){
						cnt++;
					}
				}
				map[row][col] = '0' + cnt;
			}
		}
	}

	for (row = 0;row < 10;row++)
	{
		for(col = 0;col < 10;col ++)
			printf("* ");
		printf("\n");
	}
	num = 0;
	int x,y;
	do
	{
		printf("please enter the coordinate of array:");
		scanf("%d%d",&x,&y);
		show[x-1][y-1] = 1;
		if(map[x-1][y-1] == '0'){
			for (num = 0;num <= 7;num++){
				if(x-1 + delta[num][0] < 0){
					continue;
				}
				if(x-1 + delta[num][0] > 9){
					continue;
				}
				if(y -1+ delta[num][1] < 0){
					continue;
				}
				if(y-1 + delta[num][1] > 9){
					continue;
				}
				show[x-1+delta[num][0]][y-1+delta[num][1]] = 1;
			}
		}
		if (map[x-1][y-1]!= 'x'&&map[x-1][y-1] != '0'){
			for (num = 0;num <= 7;num++){
				int cnt = 0;
				if(x-1 + delta[num][0] < 0){
					continue;
				}
				if(x-1 + delta[num][0] > 9){
					continue;
				}
				if(y-1 + delta[num][1] < 0){
					continue;
				}
				if(y-1 + delta[num][1] > 9){
					continue;
				}
				if( map[x -1 + delta[num][0]][y -1+ delta[num][1]] != 'x'){
					show[x-1 + delta[num][0]][y -1+ delta[num][1]]= 1 ;
				}
			}
		}
		if(map[x-1][y-1] == 'x') {
			printf("game over!\n");
			for (row = 0;row < 10;row++){
				for(col = 0;col < 10;col ++){
					printf("%c ",map[row][col]);
				}
				printf("\n");
			}
			return 0;
		}
		system("cls");
		printf("mine sweeping:\n");
		for (row = 0;row < 10;row++){
			for(col = 0;col < 10;col ++){
				if (show[row][col] == 1){printf("%c ", map[row][col]);}
				else
				{
					printf("* ");
				}
			}
			printf("\n");
		}
		num = 0;
		for (row = 0;row < 10;row++){
			for(col = 0;col < 10;col ++){
				if (show[row][col] == 1 ){num++;}
			}
		}
		printf("num:%d\n",num);
	}while(num < 90);
	printf("you win!");
	return 0;
}
