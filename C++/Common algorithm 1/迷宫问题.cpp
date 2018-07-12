#include"stdio.h"
/*---声明6*5的迷宫，外围不可走---*/
int maze[8][7]={1,1,1,1,1,1,1,
                1,0,1,0,0,0,1,
                1,1,0,1,1,0,1,
                1,1,0,1,1,0,1,
                1,1,1,0,1,1,1,
                1,0,0,1,0,1,1,
                1,1,1,1,0,0,1,
                1,1,1,1,1,1,1,};
/*---递归求解迷宫问题---*/
int way(int locx,int locy)
{
	if(maze[6][5]==2)
		return 1;
	else
		if(maze[locy][locx]==0)
		{
			maze[locy][locx]=2;
			if(way(locx,locy-1))
				return 1;
			else if(way(locx+1,locy-1))
				return 1;
			else if(way(locx+1,locy))
				return 1;
			else if(way(locx+1,locy+1))
				return 1;
			else if(way(locx,locy+1))
				return 1;
			else if(way(locx-1,locy+1))
				return 1;
			else if(way(locx-1,locy))
				return 1;
			else if (way(locx-1,locy-1))
				return 1;
			else
			{maze[locy][locx]=3;return 0;}
		}
		else
			return 0;
}
/*---主程序---*/
void main()
{
	int i,j;
	printf("--problem of maze--\n");
	printf("The maze source is (1,1).\n");
	printf("The maze destination is (6,5).\n");
	way(1,1);
	printf("The graph of maze.\n");
	printf("    0   1   2   3   4   5   6  \n");
	printf("   +---+---+---+---+---+---+---+\n");
	for(i=0;i<8;i++)
	{
		printf("  %d |",i);
		for(j=0;j<7;j++)
			printf("-%d-|",maze[i][j]);
		printf("\n   +---+---+---+---+---+---+---+\n");
	}
}