// stocks.h -- the declare of stocks
class stock{
	char company[50];
	int shares;
	double share_val;
	double total_val;
	void set_tot() 
	{ total_val=shares * share_val; }
public:
	void acquire(const char * ,int,double);
	void buy(int,double);
	void sell(int,double);
	void update(double);
	void show();
};