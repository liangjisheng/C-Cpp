
#include <iostream>
#include <math.h>

using namespace std;

double f1(double x) { return x; }

double f2(double x) { return x * sin(x); }


// ������ֳ�n��,���
// ��ʱonepass()�Ժ���f1()�������ǲ������,����������������仯
// ֻ���ֶ��޸�onepass()��Դ����,����ķ���������onepass()������
// һ���ӿ�,������������һ������ĺ���
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

// ����,�ﵽ�涨�ľ���
double integration(double x1, double x2)
{
	double result, newresult;
	int n = 2;
	result = onepass(x1, x2, n);
	n *= 2;
	newresult = onepass(x1, x2, n);

	// �����ֵľ��ȼ��㲻��ʱ,������ֳ�2n�ȷݣ���ø��ߵľ���
	while(fabs(newresult - result) > 1e-5)
	{
		result = newresult;
		n *= 2;
		newresult = onepass(x1, x2, n);
	}
	return newresult;
}

// ���������һԪ�ɻ�����,�����Ե��ú���integration_plue������������
// �ϵ���ֵ����.����integration_plue���������Ŀ����ô���
double integration_plue(double x1, double x2, double (*pFun)(double))
{
	double result, newresult;
	int n = 2;
	result = onepass_plus(x1, x2, n, pFun);
	n *= 2;
	newresult = onepass_plus(x1, x2, n, pFun);

	// �����ֵľ��ȼ��㲻��ʱ,������ֳ�2n�ȷݣ���ø��ߵľ���
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

	// �����ֵľ��ȼ��㲻��ʱ,������ֳ�2n�ȷݣ���ø��ߵľ���
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