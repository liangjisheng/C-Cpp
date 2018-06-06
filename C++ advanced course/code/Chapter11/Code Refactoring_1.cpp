

#include <iostream>

using namespace std;

class TData
{
	int month;
	int day;
	int year;
public:
	bool isleapyear() 
	{ return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }
	TData() { month = 1; day = 1; year = 2000; }
	TData(int m)
	{
		if(m > 0 && m < 13)
			month = m;
		else
			month = 1;
		year = 2000;
		day = 1;
	}
	TData(int m, int d)
	{
		int limit[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if(m > 0 && m < 13 && d > 0 && d < 32)
		{
			month = m;
			day = d;
		}
		else
		{
			month = 1;
			day = 1;
		}
		if(day > limit[month - 1])
		{
			month = 1;
			day = 1;
		}
		year = 2000;
	}
	TData(int m, int d, int y)
	{
		int limit[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if(m > 0 && m < 13 && d > 0 && d < 32 && y > 0)
		{
			month = m;
			day = d;
			year = y;
		}
		else
		{
			month = 1;
			day = 1;
			year = 2000;
		}

		if(!isleapyear() && month == 2 && day == 29)
		{
			month = 1;
			day = 1;
			year = 2000;
			return ;
		}
		if(day > limit[month - 1])
		{
			month = 1;
			day = 1;
			year = 2000;
		}
	}

	void show() { cout << month << "/" << day << "/" << year << endl; }
};


int main()
{
	TData t1(5);
	t1.show();
	TData t2(5, 32);
	t2.show();
	TData t3(8, 38, 2008);
	t3.show();
	TData t4(8, 8, 2008);
	t4.show();

	system("pause");
	return 0;
}