
#include <stdio.h>
#include <algorithm>

int main()
{
	size_t indexs = -1;
	size_t ps = 100;
	int index = -1;
	int p = 100;

	printf("%d\n", std::min(p, index));				// -1
	printf("%d\n", std::min(ps, indexs));			// 100

	getchar();
	return 0;
}