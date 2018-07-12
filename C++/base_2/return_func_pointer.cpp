
// 函数指针作为函数返回值的用法
// 当一个函数名出现在表达式中时，编译器会将其转换为一个指针，即类似于
// 数组变量名的行为，隐式的取出了它的地址
// 在C语言中，通常用函数指针来实现DIP(倒置依赖关系)，断开不想要的直接
// 依赖.既可以通过函数指针调用服务(被调用代码),服务也可以通过函数指针
// 回调用户函数

// 当函数的返回值是指针时，则这个函数就是指针函数

#include <stdio.h>
#include <assert.h>

double getMin(double *dbData, int iSize)
{
	double dbMin = 0.0;
	assert((dbData != NULL) && (iSize > 0));
	dbMin = dbData[0];
	for(int i = 1; i < iSize; i++)
		if(dbMin > dbData[i])
			dbMin = dbData[i];

	return dbMin;
}

double getMax(double *dbData, int iSize)
{
	double dbMax = 0.0;
	assert((dbData != NULL) && (iSize > 0));
	dbMax = dbData[0];
	for(int i = 1; i < iSize; i++)
		if(dbMax < dbData[i])
			dbMax = dbData[i];
	return dbMax;
}

double getAverage(double *dbData, int iSize)
{
	double dbSum = 0;
	assert((dbData != NULL) && (iSize > 0));
	for(int i = 0; i < iSize; i++)
		dbSum += dbData[i];

	return dbSum / iSize;
}

double unKnown(double *dbData, int iSize)
{
	return 0;
}

typedef double (*PF)(double* dbData, int iSize);

PF getOperator(char c)
{
	switch(c)
	{
	case 'd': return getMax;
	case 'x': return getMin;
	case 'p': return getAverage;
	default: return unKnown;
	}
}


int main()
{
	double dbData[] = {3.1415926, 1.4142, -0.5, 999, -313, 365};
	int iSize = sizeof(dbData) / sizeof(dbData[0]);
	char c;
	printf("Please input the operator:\n");
	c = getchar();
	PF pf = getOperator(c);
	printf("result is %lf\n", pf(dbData, iSize));

	getchar();
	getchar();
	return 0;
}
