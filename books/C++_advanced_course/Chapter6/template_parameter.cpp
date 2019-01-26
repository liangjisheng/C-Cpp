
#include <iostream>

using std::cout;
using std::endl;


template<class T, int size>
class Average
{
	T Element[size];
	T average_value;
public:
	Average(T *in)
	{
		average_value = (T)0;
		for(int i = 0; i < size; i++)
		{
			Element[i] = in[i];
			average_value += in[i];
		}
		average_value /= size;
	}

	void show()
	{
		cout << "The elements are: ";
		for(int i = 0; i < size; i++)
			cout << Element[i] << " ";
		cout << "\nThe average is: " << average_value << endl;
	}
};


int main()
{
	int arr_int[3] = {3, 6, 9};
	double arr_dbl[4] = {1.1, 2.2, 3.3, 4.4};
	Average<int, 3> ia(arr_int);
	Average<double, 4> da(arr_dbl);
	ia.show();
	da.show();

	system("pause");
	return 0;
}

