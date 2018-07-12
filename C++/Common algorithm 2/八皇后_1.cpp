#include <stdio.h>
#include <stdlib.h>
 
#define max 8
 
 
int queen[max], sum=0; /* max为棋盘最大坐标 */
 
void show() /* 输出所有皇后的坐标 */
{
    int i;
    for(i = 0; i < max; i++)
    {
         printf("(%d,%d) ", i, queen[i]);
    }
    printf("\n");
    sum++;
}
 
int check(int n) /* 检查当前列能否放置皇后 */
{
    int i;
    for(i = 0; i < n; i++) /* 检查横排和对角线上是否可以放置皇后 */
    {
        if(queen[i] == queen[n] || abs(queen[i] - queen[n]) == (n - i))
        {return 1;}
    }
    return 0;
}
 
void put(int n) /* 回溯尝试皇后位置,n为横坐标 */
{
    int i;
    for(i = 0; i < max; i++)
    {       
        queen[n] = i; /* 将皇后摆到当前循环到的位置 */
        if(!check(n))
        {           
            if(n == max - 1)
            {show(); /* 如果全部摆好，则输出所有皇后的坐标 */}         
            else
            {put(n + 1); /* 否则继续摆放下一个皇后 */}
        }
    }
}
 
int main()
{
    put(0); /* 从横坐标为0开始依次尝试 */
    printf("%d", sum);
    system("pause");
    return 0;
}


//输出八皇后解法共有多少种以及放置的位置
#include"iostream"
#include"cmath"
#include"iomanip"
using namespace std;
int place(int k,int x[])//检测放置位置的可行性
{
	int i;
	for(i=1;i<k;i++)
		if(abs(k-i)==abs(x[i]-x[k])||x[i]==x[k])return 0;
	return 1;
}
void backtrack(int t,int n,int x[],int *sum)
{ //用回溯法球n皇后问题，x为排列方法，sum为解总数
	int i;
	if(t>n){
		(*sum)++;
		cout<<"第"<<setw(2)<<*sum<<"种解法:";
		for(i=1;i<=n;i++)
			cout<<x[i]<<" ";
		cout<<endl;
	}
	else
		for(i=1;i<=n;i++)
		{x[t]=i;
		if(place(t,x))backtrack(t+1,n,x,sum);}
}
int main()
{
	int i,sum=0,x[100],n=8;
	for(i=0;i<=n;i++)x[i]=0;
	backtrack(1,n,x,&sum);
	cout<<"sum="<<sum<<endl;
	return 0;
}