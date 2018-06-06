
// C语言实现约瑟夫环问题

#include <stdio.h>
#include <assert.h>

int* JosephWithArray(int n)
{
	int *p = NULL;
	p = new int[n];
	for(int i = 0; i < n; i++)
		p[i] = i + 1;
	return p;
}

int NextPeople(int prev, int *WorkingArrya, int number_of_people, int step)
{
	int count = 0;
	int travel = prev;
	int emptyplace = 0;
	while(count < step)
	{
		travel = (travel + 1) % number_of_people;
		if(WorkingArrya[travel])
		{
			count++;
			emptyplace = 0;
		}
		else
		{
			emptyplace++;
			if(emptyplace == number_of_people)
				return -1;
		}
	}
	return travel;
}


void CreateOutput(int* WorkingArray, int number_of_people, int step)
{
	int outnum = -1;
	for(int i = 0; i < number_of_people; i++)
	{
		// 返回下一个出列的人在数组中的索引
		outnum = NextPeople(outnum, WorkingArray, number_of_people, step);
		assert(outnum > -1 && outnum < number_of_people);
		printf("%d ", WorkingArray[outnum]);
		WorkingArray[outnum] = 0;
	}
}


void Dispose(int* WorkingArray)
{
	delete [] WorkingArray;
}


int main()
{
	int n, m;
	int *WorkingArray = NULL;
	printf("please input number of people:");
	scanf("%d", &n);
	printf("please input step:");
	scanf("%d", &m);
	WorkingArray = JosephWithArray(n);
	CreateOutput(WorkingArray, n, m);
	printf("\n");
	Dispose(WorkingArray);

	getchar();
	getchar();
	return 0;
}