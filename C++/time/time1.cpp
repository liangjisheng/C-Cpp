//���������������ʱ��
#include"stdio.h"
#include"time.h"
#include"conio.h"

int main() {
	time_t stime,etime;
	time(&stime);
	printf("hello,wordl\n");
	for(int i=0;i<10;i++)
		printf("%d ",i);
	printf("\n");
	time(&etime);
	printf("������������ʱ��:%ld\n",etime-stime);
	getch();

	return 0;
}