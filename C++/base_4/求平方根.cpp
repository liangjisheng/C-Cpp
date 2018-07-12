#include"stdio.h"
#include"math.h"
void main()
{
	double x0,x1,a;
	while(1)
	{printf("input a(exit is -1):");
		scanf("%lf",&a);
	    if(a==-1)
		   break;
	    else
		{x0=a/2;
		x1=(x0+a/x0)/2;
		do
		{
			x0=x1;
			x1=(x0+a/x0)/2;
		}while(fabs(x0-x1)>=1e-6);}
	    printf("%.4f的平方根是:%f\n",a,x1);}	
}
