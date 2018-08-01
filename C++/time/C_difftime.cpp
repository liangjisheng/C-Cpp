
#include <stdio.h>
#include <time.h>
#include <stdlib.h>		// for system("pause")

int main()
{
	time_t c_start, t_start, c_end, t_end;

	c_start = clock();
	t_start = time(NULL);
	system("pause");
	c_end = clock();
	t_end = time(NULL);

	// difftime()返回两个时间的时间间隔
	printf("The pause used %f ms by clock()\n", difftime(c_end, c_start));
	printf("The pause used %f s by time()\n", difftime(t_end, t_start));

	system("pause");
	// getchar();
	return 0;
}