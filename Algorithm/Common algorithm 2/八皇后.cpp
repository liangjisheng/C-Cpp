// 八皇后问题 8*8的棋盘
// 数组a,b,c分别用来标记冲突，a数组代表列冲突，从a[0]到a[7]
// 代表第0列到第7列，如果某列上有皇后，则为1，否则为0
// 数组b代表主对角线冲突，为b[i-j+7],即从b[0]-b[14],如果
// 某条主对角线上已经有皇后，则为1，否则为0
// 数组c代表从对角线冲突，为c[i+j],即从c[0]-c[14],如果
// 某条从对角线已经有皇后，则为1，否则为0
#include"stdio.h"
#include"iostream"
static char Queen[8][8];
static int a[8];
static int b[15];
static int c[15];
static int iQueenNum=0;		// 记录中的棋盘状态数

void qu(int i);

int main()
{
	int iLine,iColumn;
	// 初始化棋盘，空格为*，放置皇后的地方为@
	for(iLine=0;iLine<8;iLine++) {
		a[iLine]=0; // 列标记初始化，表示无列冲突
		for(iColumn=0;iColumn<8;iColumn++)
			Queen[iLine][iColumn]='*';
	}
	// 主从对角线元素初始化，表示没有冲突
	//for(iLine=0;iLine<15;iLine++)
	//		b[iLine]=c[iLine]=0;

	qu(0);

	system("pause");
	return 0;
}

void qu(int i)
{
	int iColumn;
	for(iColumn=0;iColumn<8;iColumn++) {
		if(a[iColumn]==0 && b[i-iColumn+7]==0 && c[i+iColumn]==0) {
			// 如果无冲突
			Queen[i][iColumn]='@';		// 放皇后
			a[iColumn]=1;				// 标记，下一次该列上不能放皇后
			b[i-iColumn+7]=1;			// 标记，下一次该主对角线上不能放皇后
			c[i+iColumn]=1;				// 标记，下一次该从对角线上不能放皇后
			if(i<7) qu(i+1);			// 如果行还没有遍历完，进入下一行
			else {		// 否则，输出
				int iLine,iColumn;
				printf("第%d种状态为:\n",++iQueenNum);
				for(iLine=0;iLine<8;iLine++) {
					for(iColumn=0;iColumn<8;iColumn++)
						printf("%c ",Queen[iLine][iColumn]);
					printf("\n");
				}
				printf("\n\n");
			}
			// 如果前次的皇后放置导致后面的放置无论如何都不能满足要求，则回溯，重置
			Queen[i][iColumn]='*';
			a[iColumn]=0;
			b[i-iColumn+7]=0;
			c[i+iColumn]=0;
		}
	}
}