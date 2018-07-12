//三色旗对调，有若干乱序红旗，蓝旗和绿旗，现编写函数使其有序。
#include"stdio.h"
#include"string.h"
int count;   //记录对调次数
char color[]="rwbwwbrbwrbrwwrrbbbrwb";
int blue,red,white;
//swap
void swap(char *a,char *b)
{
	int i;
	char c;
	c=*a,*a=*b,*b=c;
	count++;
	printf("第%d次对调后:",count);
	for(i=0;i<(int)strlen(color);i++)
		printf(" %c",color[i]);
	printf("\n");
}
//threeflags
void threeflags()
{
	while(color[white]=='b')blue++,white++;
	while(color[red]=='r')red--;
	while(white<=red){
		if(color[white]=='r'){
			swap(&color[white],&color[red]);
			red--;
			while(color[red]=='r')red--;
		}
		while(color[white]=='w')white++;
		if(color[white]=='b')
		{swap(&color[white],&color[blue]);blue++;white++;}
	}
}
//main
void main()
{
	int i;
	blue=0,white=0;
	red=strlen(color)-1;
	count=0;
	printf("三色旗问题求解.\n");
	printf("三色旗最初排列效果:\n");
	printf("            ");
	for(i=0;i<=red;i++)
		printf(" %c",color[i]);
	printf("\n");
	threeflags();              //求解
	printf("通过%d次完成对调，最终结果如下:\n",count);
	for(i=0;i<(int)strlen(color);i++)
		printf(" %c",color[i]);
	printf("\n");
}


程序运行结果：
三色旗问题求解.
三色旗最初排列效果:
             r w b w w b r b w r
第1次对调后: w w b w w b r b r r
第2次对调后: b w w w w b r b r r
第3次对调后: b b w w w w r b r r
第4次对调后: b b w w w w b r r r
第5次对调后: b b b w w w w r r r
通过5次完成对调，最终结果如下:
 b b b w w w w r r r
Press any key to continue

三色旗问题求解.
三色旗最初排列效果:
              r w b w w b r b w r b r r b b w w w b b r
第 1次对调后: b w b w w b r b w r b r r b b w w w b r r
第 2次对调后: b w b w w b r b w r b r r b b w w w b r r
第 3次对调后: b b w w w b r b w r b r r b b w w w b r r
第 4次对调后: b b b w w w r b w r b r r b b w w w b r r
第 5次对调后: b b b w w w b b w r b r r b b w w w r r r
第 6次对调后: b b b b w w w b w r b r r b b w w w r r r
第 7次对调后: b b b b b w w w w r b r r b b w w w r r r
第 8次对调后: b b b b b w w w w w b r r b b w w r r r r
第 9次对调后: b b b b b b w w w w w r r b b w w r r r r
第10次对调后: b b b b b b w w w w w w r b b w r r r r r
第11次对调后: b b b b b b w w w w w w w b b r r r r r r
第12次对调后: b b b b b b b w w w w w w w b r r r r r r
第13次对调后: b b b b b b b b w w w w w w w r r r r r r
通过13次完成对调，最终结果如下:
 b b b b b b b b w w w w w w w r r r r r r
Press any key to continue