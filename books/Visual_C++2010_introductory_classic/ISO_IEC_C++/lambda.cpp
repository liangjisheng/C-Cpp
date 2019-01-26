// Using lambda expressions
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

// Just to avoid a lot of using directive in the example...
using namespace std; 

// Template function to return the average of the elements in a vector
template<typename T>
T average(const vector<T>& vec)
{
	T sum(0);
	// ָ���ں������ڿ��԰����÷���sum
	for_each(vec.begin(), vec.end(),
		[&sum](const T& value) {sum += value;  });
	return sum / vec.size();
}

// Template function to set a vector to values begining with start
// and incremented by increment
template<typename T>
void setValues(vector<T>& vec, T start, T increment)
{
	T current(start);
	generate(vec.begin(), vec.end(),
		[increment, &current]()->T {T result(current);
	current += increment;
	return result; });
}

// Template function to set a vector to random values between min and max
template<typename T>
void randomValues(vector<T>& vec, T min, T max)
{
	// Initialize random number generator
	srand(static_cast<unsigned int>(time(0)));
	generate(vec.begin(), vec.end(),
		[=]() {return static_cast<T>(static_cast<double>(rand()) /
			RAND_MAX*(max - min) + min); });
}

// Template function to list the values in a vector
template<class T>
void listVector(const vector<T>& vec)
{
	int count = 0;
	for_each(vec.begin(),vec.end(),
		[&count](const T& n)->void {cout << setw(10) << n;
	if (++count % 5) cout << " ";
	else cout << endl; });
}

int main()
{
	vector<int> integerData(50);
	randomValues(integerData,1,10);	// Set random integer values
	cout << "Vector contains:" << endl;
	listVector(integerData);
	cout << "Average value is " << average(integerData) << endl;

	vector<double> realData(20);
	setValues(realData, 5.0, 2.5);	// Set real values starting at 5.0
	cout << "Vector contains:" << endl;
	listVector(realData);
	cout << "Average value is " << average(realData) << endl;

	system("pause");
	return 0;
}