//有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
#include"stdio.h"
int main(int argc,char *argv[])
{
	int i,j,k,count=0;
	for(i=1;i<5;i++)
		for(j=1;j<5;j++)
			for(k=1;k<5;k++){
				if(i!=j&&i!=k&&j!=k){
					count++;
					printf("%d%d%d ",i,j,k);
					if(count%5==0)
						printf("\n");
				}
			}
	printf("\n");
	return 0;
}