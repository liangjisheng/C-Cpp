// A recursive version of x to the power n
#include <iostream>
using std::endl;
using std::cout;

double power(double x, int n);

int main()
{
	double x(2.0);
	double result(0.0);

	// Calculate x raised to powers -3 to +3 inclusive
	for (int index = -3; index <= 3; index++)
		cout << x << " to the power " << index << " is " << power(x, index) << endl;

	system("pause");
	return 0;
}

// Recursive function to compute integral powers of a double value
// First argument is value,second argument is power index
double power(double x, int n)
{
	if (n < 0)
	{
		x = 1.0 / x;
		n = -n;
	}
	if (n > 0)
		return x*power(x, n - 1);
	else
		return 1.0;
}