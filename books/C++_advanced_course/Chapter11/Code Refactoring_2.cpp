
#include <iostream>

using namespace std;

class TDate
{
	int month;
	int day;
	int year;
	bool valid(int m, int d, int y) const 
	{
		if(m < 1 || m > 12 || d < 1 || d > 31 || y < 1)
			return false;
		if(!isleapyear(y) && m == 2 && d == 29)
			return false;
		int limit[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if(d > limit[m - 1])
			return false;
		else
			return true;
	}
public:
	bool isleapyear(int y = 0) const 
	{
		int t = (y == 0) ? year : y;
		return (t % 4 == 0 && t % 100 != 0) || (t % 400 == 0);
	}
	void setdate(int m, int d, int y)
	{
		if(valid(m, d, y))
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
	}
	TDate() { setdate(1, 1, 2000); }
	TDate(int m) { setdate(m, 1, 2000); }
	TDate(int m, int d) { setdate(m, d, 2000); } 
	TDate(int m, int d, int y) { setdate(m, d, y); }
	void show() { cout << month << "/" << day << "/" << year << endl; }
};


int main()
{
	TDate t1(5);
	t1.show();
	TDate t2(5, 32);
	t2.show();
	TDate t3(8, 38, 2008);
	t3.show();
	TDate t4(8, 8, 2008);
	t4.show();

	system("pause");
	return 0;
}