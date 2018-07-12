#include"iostream"
#include"cmath"
using namespace std;
#ifndef DATE
#define DATE
class Date{
public:
	Date(int,int,int);
	friend void ShowDate(Date&);
private:
	int year,month,day;
};
#endif
Date::Date(int y,int m,int d):year(y),month(m),day(d){}
void ShowDate(Date &date)
{cout<<date.year<<" "<<date.month<<" "<<date.day<<endl;}
//main
int main()
{
	Date myDate(1997,11,26);
	ShowDate(myDate);
	return 0;
}
