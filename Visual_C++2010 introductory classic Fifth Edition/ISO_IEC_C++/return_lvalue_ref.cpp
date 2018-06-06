// Returning a reference
#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::setw;

double& lowest(double values[], int length);	// Function prototype

int main()
{
	double arr[] = { 3.0,10.0,1.5,15.0,2.7,23.0,
					4.5,12.0,6.8,13.5,2.1,14.0 };
	int len(sizeof(arr) / sizeof(arr[0]));

	cout << endl;
	for (int i = 0; i < len; i++)
		cout << setw(6) << arr[i];
	cout << endl;

	lowest(arr, len) = 6.9;
	cout << endl;
	for (int i = 0; i < len; i++)
		cout << setw(6) << arr[i];
	cout << endl;

	lowest(arr, len) = 7.9;
	cout << endl;
	for (int i = 0; i < len; i++)
		cout << setw(6) << arr[i];
	cout << endl;

	system("pause");
	return 0;
}

// Function returning a reference
double& lowest(double values[], int length)
{
	int j(0);
	for (int i = 1; i < length; i++)
		if (values[j] > values[i])
			j = i;
	return values[j];
}