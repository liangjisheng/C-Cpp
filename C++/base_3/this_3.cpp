#include"cstdio"
#include"iostream";

void swapxy(char& a,char& b) {
	int x=a,y=b;
	x=x+y;
	y=x-y;
	x=x-y;
	a=x,b=y;
	return ;
}

int main() 
{
	char a='a',b='B';
	char &x=a,&y=b;
	printf("a='%c', and b='%c' before swaping.\n",a,b);
	swapxy(x,y);
	printf("a='%c', and b='%c' after swaping.\n",a,b);

	system("pause");
	return 0;
}