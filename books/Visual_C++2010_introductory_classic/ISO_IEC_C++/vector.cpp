#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

template<typename T>
void listInfo(vector<T>& v)
{
	cout<<"\nContainer capacity: "<<v.capacity()
		<<" size: "<<v.size()<<endl;
}

int main()
{
	vector<double> data;
	listInfo(data);

	cout<<"\nAfter calling reserve(100): \n";
	data.reserve(100);
	listInfo(data);

	vector<int> numbers(10,-1);
	cout<<"\nThe initial values are:\n";
	for(vector<int>::size_type i = 0;i<numbers.size();i++)
		cout<<numbers[i]<<' ';
	cout<<endl;

	auto oldC = numbers.capacity();
	auto newC = oldC;
	cout<<"\n\n";
	listInfo(numbers);
	for(int i=0;i<1000;i++)
	{
		numbers.push_back(2*i);
		newC = numbers.capacity();
		if(oldC < newC)
		{
			oldC = newC;
			listInfo(numbers);
		}
	}

	system("pause");
	return 0;
}