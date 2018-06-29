//¶¨Òåº¯Êý   char *ctime(const time_t *timep);

#include"stdio.h"
#include"time.h"

int main() {
	time_t timep;
	time(&timep);
	printf("%s",ctime(&timep));
	return 0;
}