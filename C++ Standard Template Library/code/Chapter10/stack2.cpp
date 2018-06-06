
#include <iostream>
#include "Stack.hpp"

using namespace std;

int main()
{
	try {
		Stack<int> st;

		// push three elements into the stack
		st.push(1);
		st.push(2);
		st.push(3);

		// pop and print two elements from the stack
		cout << st.pop() << ' ';
		cout << st.pop() << ' ';
		cout << endl;

		// modify top element
		st.top() = 77;

		// push tow new elements
		st.push(4);
		st.push(5);

		// pop one element with processing it
		st.pop();

		// pop and print three elements
		// ERROR: one element too many
		cout << st.pop() << ' ';
		cout << st.pop() << endl;
		cout << st.pop() << endl;
	}
	catch(const exception& e) {
		cerr << "EXCEPTION: " << e.what() << endl;
	}

	system("pause");
	return 0;
}
