// cubes.cpp -- regular and reference arguments
#include"iostream"
using namespace std;
double cube(double);
double refcube(const double &);

int main() {
	double x=3;
	cout<<cube(x)<<" =cube of "<<x<<endl;
	cout<<refcube(x)<<" =refcube of "<<x<<endl;
	double side=3;
	double * pd=&side;
	double & rd=side;
	long edge=5L;
	double lens[]={1,2,3,4};
	double c1=refcube(side);		// ra is side
	double c2=refcube(lens[2]);		// ra is lens[2]
	double c3=refcube(rd);			// ra is rd is side
	double c4=refcube(*pd);			// ra is *pd is side
	double c5=refcube(edge);		// ra is temporary variable
	double c6=refcube(7);			// ra is temporary variable
	double c7=refcube(side+10);		// ra is temporary variable
	cout<<"c1="<<c1<<endl;
	cout<<"c2="<<c2<<endl;
	cout<<"c3="<<c3<<endl;
	cout<<"c4="<<c4<<endl;
	cout<<"c5="<<c5<<endl;
	cout<<"c6="<<c6<<endl;
	cout<<"c7="<<c7<<endl;

	return 0;
}

double cube(double a) {
	a*= a*a;
	return a;
}

double refcube(const double & ra) {
	return ra*ra*ra;
}