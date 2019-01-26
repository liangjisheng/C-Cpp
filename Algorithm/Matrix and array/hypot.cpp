// 已知两个直角边长，求其斜边的长度
#include"stdio.h"
#include"math.h"


int main() {
	printf("3^2+4^2=%.2f^2\n",hypot(3,4));
	printf("3.2^2+4.2^2=%.2f^2\n",hypot(3.2,4.2));

	getchar();
	return 0;
}