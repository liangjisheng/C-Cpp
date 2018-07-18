/*#include"stdio.h"
#include"signal.h"

void Print1();
void Print2();

int main() {
	signal(SIGINT,Print1);
	printf("Please enter Ctrl+c for interupt\n");
	getchar();
	signal(SIGSEGV,Print2);
	printf("Please enter any key for a interupt\n");
	getchar();
	raise(SIGSEGV);
	return 0;
}

void Print1() {
	printf("This is a SIGINT interupt!\n");
}
void Print2() {
	printf("This is a SIGSEGV interupt!\n");
}*/