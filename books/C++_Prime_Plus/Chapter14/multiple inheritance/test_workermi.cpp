// test_workermi.cpp -- multiple inheritance
#include"iostream"
#include"cstring"
#include"workermi.h"

;int main() 
{
	Waiter wt,wt1;
	Singer s,s1;
	SingerWaiter sw,sw1;
	wt.Show();
	wt1.Show();
	s.Show();
	s1.Show();
	sw.Show();
	sw1.Show();
	return 0;
}