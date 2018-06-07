// test_worker.cpp -- test worker chass hierarchy
#include"iostream"
//#include"string"
#include"worker0.h"
const int LIM=4;

int main() 
{
	Waiter bob("Bob Apple",314L,5);
	Singer bev("beverly Hills",522L,3);
	Waiter w_temp;
	Singer s_temp;
	Worker * pw[LIM]={ &bob,&bev,&w_temp,&s_temp };
	int i;
	pw[2]->Set();
	pw[3]->Set();
	for(i=0;i<LIM;i++) {
		pw[i]->Show();
		std::cout<<std::endl;
	}

	return 0;
}