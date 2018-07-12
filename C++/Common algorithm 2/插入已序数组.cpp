#include"stdio.h"
void main()
{
	int i,a[20];
	printf("input the 10 numbers:\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	int num,j=0;
	printf("input the num:\n");
	scanf("%d",&num);
	for(i=0;i<10;i++)
	{
		if(num<=a[i])
		{	for(j=0;j<9-i;j++)
				a[10-j]=a[9-j];
		a[i]=num;
		break;
		}
	}
	printf("output the later a:\n");
	for(i=0;i<11;i++)
		printf("%3d",a[i]);
	printf("\n");
}