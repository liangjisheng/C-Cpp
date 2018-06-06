// A pointer to a function  as an argument
#include <iostream>
using std::cout;
using std::endl;

// Function prototypes
double squared(double);
double cubed(double);
double sumarray(double arr[], int len, double(*pfun)(double));

int main()
{
	double arr[] = { 1.5,2.5,3.5,4.5,5.5,6.5,7.5 };
	int len(sizeof(arr) / sizeof(arr[0]));
	cout << endl << "Sum of squsres = " << sumarray(arr, len, squared);
	cout << endl << "Sum of cubes = " << sumarray(arr, len, cubed);
	cout << endl;

	system("pause");
	return 0;
}

double squared(double x)
{
	return x*x;
}

double cubed(double x)
{
	return x*x*x;
}

double sumarray(double arr[],int len,double (*pfun)(double))
{
	double total(0.0);

	for (int i = 0; i < len; i++)
		total += pfun(arr[i]);

	return total;
}