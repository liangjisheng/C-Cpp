
#include "MyComplex.hpp"

void test()
{
	MyComplex d1;
	MyComplex d2(4.0, 6.6);

	d1.Display();
	d2.Display();

	d1 = d2;
	d1.Display();
	cout << endl;

	MyComplex d3;
	d3 = d1 + d2;
	cout << endl;

	cout << d1.operator==(d2) << endl;
	cout << d1.operator!=(d2) << endl;
	d3.Display();
}

void test1()
{
	MyComplex d1;
	MyComplex d2(4.0, 9.6);
	d1.Display();
	d2.Display();

	d1 += d2;
	d1.Display();
	d2.Display();
}

void test2()
{
	MyComplex d1;
	MyComplex d2(0, 0);

	d2 = ++ d1;
	d2.Display();
	d1.Display();

	MyComplex d3(1.0, 2.0);
	d3 = d1++;
	d3.Display();
	d1.Display();
}

void test3()
{
	MyComplex d1(7, 0);
	MyComplex d2(6, 0);
	MyComplex d3;
	MyComplex d4(6, 0);

	cout << d1.operator>(d2) << endl;
	cout << d1.operator<(d2) << endl;
	cout << d3.operator<=(d4) << endl;
	cout << d2.operator>=(d4) << endl;
}


int main()
{
	// test();
	// test1();
	// test2();
	test3();

	system("pause");
	return 0;
}