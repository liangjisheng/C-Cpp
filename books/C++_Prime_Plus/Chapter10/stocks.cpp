// stocks.cpp -- the implement class stock
#include"stocks.h"
#include"iostream"
#include"cstring"

void stock::acquire(const char * co,int n,double pr)
{
	strncpy(company,co,50);
	company[50]='\0';
	if(n<0) {
		std::cerr<<"Number of shares can't be negative.\n"
			<<company<<" shares set to 0.\n";
		shares=0;
	}
	else 
		shares=n;
	share_val=pr;
	set_tot();
}

void stock::buy(int num,double pr)
{
	if(num<0) {
		std::cerr<<"Number of shares purchased can't be negative.\n"
			"Transaction is aborted.\n";
	}
	else {
		shares+=num;
		share_val=pr;
		set_tot();
	}
}

void stock::sell(int num,double pr)
{
	using std::cerr;
	if(num<0) {
		std::cerr<<"Number of shares sold can't be negative.\n"
			"Transaction is aborted.\n";
	}
	else if(num>shares) {
		cerr<<"You can't sell more than you have!\n"
			"Transaction is aborted.\n";
	}
	else {
		shares-=num;
		share_val=pr;
		set_tot();
	}
}

void stock::update(double pr) 
{
	share_val=pr;
	set_tot();
}

void stock::show()
{
	using std::cout;
	using std::endl;
	cout<<"Company: "<<company
		<<" shares: "<<shares
		<<"\nshare price: $"<<share_val
		<<" Total Worth: $"<<total_val<<endl;
}