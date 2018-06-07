// memb_pt.cpp derefeencing pointers to class members
#include"iostream"
using namespace std;

class Example {
private:
	int feet;
	int inches;
public:
	Example(int n=0) : feet(n),inches(n*2) {}
	~Example() {}
	void show_in() const { cout<<"inches="<<inches<<endl; }
	void show_ft() const { cout<<"feet="<<feet<<endl; }
	void use_ptr() const ;
};

void Example::use_ptr() const {
	Example yard(3);
	int Example:: * pt;
	pt=&Example::inches;
	cout<<"Set pt to &Example::inches:\n";
	cout<<"this->pt: "<<this->*pt<<endl;
	cout<<"yard.*pt: "<<yard.*pt<<endl;
	pt=&Example::feet;
	cout<<"Set pt to &Example::feet.\n";
	cout<<"this->*pt: "<<this->*pt<<endl;
	cout<<"yard.*pt: "<<yard.*pt<<endl;
	void (Example::*pf) () const;
	pf=&Example::show_in;
	cout<<"Set pf to &Example::show_in: \n";
	cout<<"Using (this->*pf) (): ";
	(this->*pf)();
	pf=&Example::show_ft;
	cout<<"Set pf to &Example::show_ft: \n";
	cout<<"Using (this->*pf)(): ";
	(this->*pf)();
	cout<<"Using (yard.*pf)() ";
	(yard.*pf)();
}

int main()
{
	Example car(15);
	Example van(20);
	Example garage;
	cout<<"car.use_ptr() output: \n";
	car.use_ptr();
	cout<<"\nvan.use_ptr() output: \n";
	van.use_ptr();

	return 0;
}