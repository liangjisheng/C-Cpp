#include"stdio.h"
#include"stdlib.h"
void main()
{
	char s1[3]="50",s2[6]="54321",s3="987.32";
	int a;
	long int b;
	double c;
	a=atoi(s1);
	b=atol(s2);
	c=atof(s3);
	printf("String '%s' is value [%d]\n",s1,a);
	printf("String '%s' is value [%ld]\n",s2,b);
	printf("String '%s' is value [%f]\n",s3,c);
}