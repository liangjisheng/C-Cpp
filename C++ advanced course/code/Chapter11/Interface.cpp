
#include <iostream>
#include <math.h>

using namespace std;

double f1(double x) { return x; }

double f2(double x) { return x * sin(x); }


// 将区间分成n段,求和
// 此时onepass()对函数f1()的依赖是不合理的,如果被积函数发生变化
// 只能手动修改onepass()的源代码,解决的方法就是让onepass()依赖于
// 一个接口,而不是依赖于一个具体的函数
double onepass(double x1, double x2, int n)
{
	double x, deltax, result = 0.0;
	deltax = (x2 - x1) / n;
	x = x1 + 0.5 * deltax;
	for(int i = 0; i < n; i++)
	{
		result += f1(x) * deltax;
		x += deltax;
	}
	return result;
}

double onepass_plus(double x1, double x2, int n, double (*pFun)(double))
{
	double x, deltax, result = 0.0;
	deltax = (x2 - x1) / n;
	x = x1 + 0.5 * deltax;
	for(int i = 0; i < n; i++)
	{
		result += pFun(x) * deltax;
		x += deltax;
	}
	return result;
}

double onepass_plus1(double x1, double x2, int n, double (pFun)(double))
{
	double x, deltax, result = 0.0;
	deltax = (x2 - x1) / n;
	x = x1 + 0.5 * deltax;
	for(int i = 0; i < n; i++)
	{
		result += pFun(x) * deltax;
		x += deltax;
	}
	return result;
}

// 积分,达到规定的精度
double integration(double x1, double x2)
{
	double result, newresult;
	int n = 2;
	result = onepass(x1, x2, n);
	n *= 2;
	newresult = onepass(x1, x2, n);

	// 当积分的精度计算不够时,将区间分成2n等份，获得更高的精度
	while(fabs(newresult - result) > 1e-5)
	{
		result = newresult;
		n *= 2;
		newresult = onepass(x1, x2, n);
	}
	return newresult;
}

// 对于任意的一元可积函数,都可以调用函数integration_plue进行有限区间
// 上的数值积分.函数integration_plue成了真正的可重用代码
double integration_plue(double x1, double x2, double (*pFun)(double))
{
	double result, newresult;
	int n = 2;
	result = onepass_plus(x1, x2, n, pFun);
	n *= 2;
	newresult = onepass_plus(x1, x2, n, pFun);

	// 当积分的精度计算不够时,将区间分成2n等份，获得更高的精度
	while(fabs(newresult - result) > 1e-5)
	{
		result = newresult;
		n *= 2;
		newresult = onepass_plus(x1, x2, n, pFun);
	}
	return newresult;
}

double integration_plue1(double x1, double x2, double (pFun)(double))
{
	double result, newresult;
	int n = 2;
	result = onepass_plus(x1, x2, n, pFun);
	n *= 2;
	newresult = onepass_plus(x1, x2, n, pFun);

	// 当积分的精度计算不够时,将区间分成2n等份，获得更高的精度
	while(fabs(newresult - result) > 1e-5)
	{
		result = newresult;
		n *= 2;
		newresult = onepass_plus(x1, x2, n, pFun);
	}
	return newresult;
}


int main()
{
	double res = integration(0, 1.0);
	cout << res << endl;

	cout << integration_plue(0, 1, f1) << endl;
	cout << integration_plue(0, 1, f2) << endl;

	cout << integration_plue1(0, 1, f1) << endl;
	cout << integration_plue1(0, 1, f2) << endl;

	system("pause");
	return 0;
}