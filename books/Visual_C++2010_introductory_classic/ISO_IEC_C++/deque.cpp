// Using a double-ended queue

#include <iostream>
#include <deque>
#include <algorithm>
#include <numeric>
using std::cin;
using std::cout;
using std::endl;
using std::deque;
using std::sort;
using std::accumulate;

int main()
{
	deque<int> data;
	deque<int>::iterator iter;
	deque<int>::reverse_iterator riter;

	// Read the data
	cout<<"Enter a series of non-zero integers separated by spaces."
		<<" Enter 0 to end.\n";
	int value(0);
	while(cin>>value,value!=0)
		data.push_front(value);

	// Output the data using an iterator
	cout<<"\nThe values you entered are:\n";
	for(iter=data.begin();iter != data.end();iter++)
		cout<<*iter<<' ';
	cout<<endl;

	// Output the data using a reverse iterator
	cout<<"\nIn reverse order the values you entered are: \n";
	for(riter = data.rbegin();riter!=data.rend();riter++)
		cout<<*riter<<' ';
	cout<<endl;

	// Sort the data in descending sequence
	cout<<endl;
	cout<<"\nIn descending sequence the values you entered are: \n";
	sort(data.begin(),data.end());
	for(iter=data.begin();iter != data.end();iter++)
		cout<<*iter<<' ';
	cout<<endl;

	// Calculate the sum of the elements
	cout<<"\nThe sum of the elements in the queue is:\n"
		<<accumulate(data.begin(),data.end(),0)<<endl;

	system("pause");
	return 0;
}