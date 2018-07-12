
#include <stdio.h>

int bitOp1(int x)
{
	// -x = ~x + 1
	return ~x + 1;
}

int bitOp2(int x)
{
	// -x = ~(x-1)
	return ~(x - 1);
}

int bitOp3(int x)
{
	// ~x = -x-1
	return -x-1;
}

int bitOp4(int x)
{
	// -~x = x + 1
	return -~x;
}

int main()
{
	for (int i = 0; i < 10; ++i)
		printf("%d ", i);
	printf("\n");

	for (int i = 0; i < 10; ++i)
		printf("%d ", ~i);
	printf("\n");

	for (int i = 0; i < 10; ++i)
		printf("%d ", bitOp1(i));
	printf("\n");

	for (int i = 0; i < 10; ++i)
		printf("%d ", bitOp2(i));
	printf("\n");

	for (int i = 0; i < 10; ++i)
		printf("%d ", bitOp3(i));
	printf("\n");

	for (int i = 0; i < 10; ++i)
		printf("%d ", bitOp4(i));
	printf("\n");

	getchar();
	return 0;
}
