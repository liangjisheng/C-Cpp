//¶¨Òåº¯Êý   char * asctime(const struct tm * timeptr);

#include"time.h"
#include"stdio.h"
int main() {
	time_t timep; // Define time struct
	time(&timep); // Get real time
	printf("%s\n",asctime(gmtime(&timep)));
	return 0;
}