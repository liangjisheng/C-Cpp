// Working with a list

#include <iostream>
#include <list>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::string;

int main()
{
//  	list<string> text;
//  	list<string>::iterator iter;

	// Read the data
// 	cout<<"Enter a few lines of text.Just press Enter to end: \n";
// 	string sentence;
// 	while(getline(cin,sentence,'\n'), !sentence.empty())
// 		text.push_front(sentence);
// 
// 	// Output the data using an iterator
// 	cout<<"\nHere is text you entered: \n";
// 	for(iter=text.begin();iter!=text.end();iter++)
// 		cout<<*iter<<endl;
// 
// 	// Sort the data in ascending sequence
// 	cout<<"\nIn ascending sequence the sentence you entered are: \n";
// 	text.sort();
// 	for(iter=text.begin();iter!=text.end();iter++)
// 		cout<<*iter<<endl;

	list<int>::iterator iter;

	int data[]={10,22,4,56,89,77,13,9};
	list<int> numbers(data,data+8);
	for(iter = numbers.begin();iter!=numbers.end();iter++)
		cout<<*iter<<' ';
	cout<<endl;

	numbers.erase(++numbers.begin());	// Remove the second element
	for(iter = numbers.begin();iter!=numbers.end();iter++)
		cout<<*iter<<' ';
	cout<<endl;

	// Remove all expects the first and the last two
	numbers.erase(++numbers.begin(),--(--numbers.end()));
	for(iter = numbers.begin();iter!=numbers.end();iter++)
		cout<<*iter<<' ';
	cout<<endl;

	list<int> numbers_1(data,data+8);
	numbers_1.remove(22);		// 删除所有等于22的元素
	for(iter = numbers_1.begin();iter!=numbers_1.end();iter++)
		cout<<*iter<<' ';
	cout<<endl;

	numbers_1.assign(10,99);	// Replace contents by 10 copies of 99
	for(iter = numbers_1.begin();iter!=numbers_1.end();iter++)
		cout<<*iter<<' ';
	cout<<endl;

	// Remove contents by 22 4 56
	numbers_1.assign(data+1,data+4);
	for(iter = numbers_1.begin();iter!=numbers_1.end();iter++)
		cout<<*iter<<' ';
	cout<<endl;

	system("pause");
	return 0;
}