// test_stocks.cpp -- test class stock 
#include"iostream"
#include"stocks.h"

int main()
{
	using std::cout;
	using std::ios_base;
	stock s;
	s.acquire("Apple",20,12.50);
	cout.setf(ios_base::fixed);
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	s.show();
	s.buy(15,18.25);
	s.show();
	s.sell(400,20.00);
	s.show();

	return 0;
}