// Handling a variable number of arguments
#include <iostream>
#include <cstdarg>

using std::cout;
using std::endl;

int sum(int count, ...)
{
	if (count <= 0)
		return 0;

	va_list arg_ptr;	// Declare argument list pointer
	va_start(arg_ptr, count);	// Set arg_ptr to 1st optional argument

	int sum(0);
	for (int i = 0; i < count; i++)
		// Add int value from arg_ptr and increment
		sum += va_arg(arg_ptr, int);

	va_end(arg_ptr);	// Reset the pointer to null
	return sum;
}

int main()
{
	cout << sum(6, 2, 4, 6, 8, 10, 12) << endl;
	cout << sum(9, 11, 22, 33, 44, 55, 66, 77, 88, 99) << endl;

	system("pause");
	return 0;
}