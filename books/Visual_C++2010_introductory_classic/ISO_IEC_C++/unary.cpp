// Unary predicate to identity negative values

#include <iostream>
#include <list>
#include <functional>
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::greater;

// 使用基础模板定义一元谓词
template<typename T>
class is_negative : public std::unary_function<T,bool>
{
public:
	result_type operator()(argument_type& value)
	{
		return value < 0;
	}
};

// Template function list the contents of a list
template<typename T>
void listlist(list<T>& data)
{
	for(auto iter=data.begin();iter!=data.end();iter++)
		cout<<*iter<<' ';
	cout<<endl;
}

// Template function to read data from cin and store it in a list
template<typename T>
void loadlist(list<T>& data)
{
	T value = T();
	while(cin>>value,value != T())
		data.push_back(value);
}

int main()
{
	// Process integers
	list<int> numbers;
	cout<<"Enter non-zero integers separated by spaces. Enter 0 to end.\n";
	loadlist(numbers);
	cout<<"\nThe list contains: "<<endl;
	listlist(numbers);
	numbers.remove_if(is_negative<int>());
	cout<<"\nAfter applying the remove_if() function the list contains: \n";
	listlist(numbers);

	// Precess floating-point values
	list<double> values;
	cout<<"\nEnter non-zero values separated by spaces. Enter 0 to end.\n";
	loadlist(values);
	cout<<"\nThe list contains: \n";
	listlist(values);
	values.remove_if(is_negative<double>());
	cout<<"\nAfter applying the remove_if() function the list contains: \n";
	listlist(values);

	// Precess floating-point values
	list<double> morevalues;
	cout<<"\nEnter non-zero values separated by spaces. Enter 0 to end.\n";
	loadlist(morevalues);
	cout<<"\nThe list contains: \n";
	listlist(morevalues);
	morevalues.remove_if(is_negative<double>());
	cout<<"\nAfter applying the remove_if() function the list contains: \n";
	listlist(morevalues);

	// Merge the last two lists
	values.sort(greater<double>());
	morevalues.sort(greater<double>());
	values.merge(morevalues,greater<double>());
	listlist(morevalues);

	system("pause");
	return 0;
}