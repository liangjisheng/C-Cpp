#include"time.h"
#include"stdio.h"
#include"dos.h"
#include"conio.h"

int main() {
	time_t first,second;
	//clrscr();
	first=time(NULL);
	delay(2000);
	second=time(NULL);
	printf("The difference is:%f seconds",
		difftime(second,first));
	getchar();
	return 0;
}