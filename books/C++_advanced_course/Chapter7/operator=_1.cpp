
#include <iostream>
#include <string>

using namespace std;

class CopyTest
{
private:
	string name;
	int id;
public:
	CopyTest(int i, string n) : id(i), name(n)
	{ cout << "Constructor" << endl; }

	~CopyTest() { cout << "deconstructor" << endl; }

	CopyTest(const CopyTest &e)
	{
		name = e.name;
		id = e.id;
		cout << "CopyTest CopyConstructor is called" << endl;
	}

	CopyTest& operator=(const CopyTest &e)
	{
		if(this == &e)
			return *this;
		name = e.name;
		id = e.id;
		cout << "CopyTest operator= function is called" << endl;
		return *this;
	}

	virtual void Display() { cout << "name = " << name << " id = " << id << endl; }
};


class CopyTestChild : public CopyTest
{
private:
	int childId;
public:
	CopyTestChild(int i, string n, int ci) : CopyTest(i, n), childId(ci)
	{ cout << "CopyTestChild is Constructor" << endl; }
	~CopyTestChild() { cout << "CopyTestChild deconstructor" << endl; }
	CopyTestChild(const CopyTestChild &e) : CopyTest(e)
	{
		childId = e.childId;
		cout << "CopyTestChild CopyConstructor is called" << endl;		
	}

	CopyTestChild& operator=(const CopyTestChild &e)
	{
		if(this == &e)
			return *this;
		CopyTest::operator=(e);
		childId = e.childId;
		cout << "CopyTestChild operator= function is called" << endl;
		return *this;
	}

	virtual void Display()
	{
		CopyTest::Display();
		cout << "ChildId is " << childId << endl;
	}
};


int main()
{
	CopyTestChild t1(1, "hehe", 1);
	CopyTestChild t2(2, "haha", 2);

	cout << "Before operator = t2 is: ";
	t2.Display();

	t2 = t1;
	cout << "After operator= t2 is: ";
	t2.Display();

	system("pause");
	return 0;
}


