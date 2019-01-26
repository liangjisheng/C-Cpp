#include"time.h"
#include"stdio.h"
#include"dos.h"

int main() {
	time_t timer;
	struct tm *tblock;
	timer=time(NULL);
	tblock=localtime(&timer);
	printf("Local time is:%s\n",asctime(tblock));

	return 0;
}