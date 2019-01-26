
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	queue<string> q;

	// insert three elements into the queue
	q.push("These ");
	q.push("are ");
	q.push("more than ");

	// read and print two elements from the queue
	cout << q.front();
	q.pop();
	cout << q.front();
	q.pop();
	cout << endl;

	// insert two new elements
	q.push("four ");
	q.push("words");

	// skip one element
	q.pop();

	// read and print two elements
	cout << q.front();
	q.pop();
	cout << q.front() << endl;
	q.pop();

	// print number of element in the queue
	cout << "number of elements in the queue: " << q.size() << endl;

	system("pause");
	return 0;
}