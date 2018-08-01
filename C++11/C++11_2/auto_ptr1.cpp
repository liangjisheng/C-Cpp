
// 本例展示了auto_ptrs转移拥有权的行为
#include <iostream>
#include <memory>
using namespace std;

// define output operator for auto_ptr
// print object value or NULL
template <typename T>
ostream& operator<<(ostream& strm,const auto_ptr<T>& p)
{
	// does p own an object?
	if(NULL == p.get())
		strm<<"NULL";		
	else
		strm<<*p;
	return strm;
}

int main()
{
	auto_ptr<int> p(new int(42));
	auto_ptr<int> q;

	// 输出是，因为是const reference所以不会发生auto_ptr所有权的转移 
	cout<<"After initialization:"<<endl;
	cout<<" p: "<<p<<endl;
	cout<<" q: "<<q<<endl;

	q=p;
	cout<<"After assignment auto pointers:"<<endl;
	cout<<" p: "<<p<<endl;
	cout<<" q: "<<q<<endl;

	*q += 13;
	p = q;
	cout<<"After change and reassignment:"<<endl;
	cout<<" p: "<<p<<endl;
	cout<<" q: "<<q<<endl;
	
	
	cout<<endl<<endl<<endl;
	const auto_ptr<int> p1(new int(42));
	const auto_ptr<int> q1(new int(0));
	const auto_ptr<int> r1;
	
	cout<<"after initialization:"<<endl;
	cout<<" p1: "<<p1<<endl;
	cout<<" q1: "<<q1<<endl;
	cout<<" r1: "<<r1<<endl;
	
	*q1 = *p1;
	// *r1 = *p1;				// Runningtime Error: undefined behavior
	*p1 = -77;
	cout<<"after assigning values:"<<endl;
	cout<<" p1: "<<p1<<endl;
	cout<<" q1: "<<q1<<endl;
	cout<<" r1: "<<r1<<endl;
	
	// q1 = p1;				// Error at compile time
	// r1 = p1;				// Error at compile time

	system("pause");
	return 0;
}
